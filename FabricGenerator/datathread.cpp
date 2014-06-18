#include "datathread.h"

#include <QDebug>
#include <QUrl>
#include <QNetworkRequest>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>
#include <QDateTime>

DataThread::DataThread(QObject *parent) :
    QThread(parent),
    mgr(new QNetworkAccessManager(this))
{
}

void DataThread::run()
{

}

void DataThread::loadByPage(int page)
{
    qDebug() << "loading:" + QString::number(page);

    QUrl url("http://test.hanloon.com/cloud/api/?act=query_xf_fabric&page=" + QString::number(page));

    QNetworkRequest req;
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    req.setUrl(url);
    mgr->get(req);
    connect(mgr, SIGNAL(finished(QNetworkReply *)), this, SLOT(read(QNetworkReply *)));
}

void DataThread::read(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QByteArray ba = reply->readAll();
        QJsonParseError jsonpe;
        QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);
        if(jsonpe.error == QJsonParseError::NoError){
            QJsonObject obj = json.object();
            int totalNum = obj["total"].toString().toInt();
            QJsonArray arr = obj["items"].toArray();

            emit(pageData_loadComplete(arr.toVariantList(), totalNum));
        }
    }

}

void DataThread::loadImageByList(QStringList list)
{
    mgr->disconnect(this, 0);

    connect(mgr, SIGNAL(finished(QNetworkReply *)), this, SLOT(imageLoadComplete(QNetworkReply *)));
    imagesList = list;
    loadImages();
}

void DataThread::loadImages()
{
    qDebug() << "startLoadImage:" + imagesList[0];
    QUrl url("http://oa.hanloon.com" + imagesList[0]);

    QNetworkRequest req;
    req.setUrl(url);
    mgr->get(req);
}

void DataThread::imageLoadComplete(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QByteArray ba = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(ba);
        QStringList arr = imagesList[0].split("/");
        QString filename = arr[arr.size() - 1];
        bool bo = pixmap.save("/Users/abellee/Desktop/fabric/" + filename);
        if(bo){
            imagesList.pop_front();
            if(imagesList.size() > 0){
                loadImages();
            }
            emit imageLoadedSignal(imagesList.size());
        }
    }else{
        failedList.push_back(imagesList[0]);
        imagesList.pop_front();
    }

    if(imagesList.size() <= 0 && failedList.size() > 0){
        imagesList = failedList;
        failedList.clear();
        loadImages();
    }
}
