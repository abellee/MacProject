#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QList>
#include <QtCore/qmath.h>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    curPage(1),
    numPerPage(50),
    thread(new DataThread(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->resize(400, 50);
    label->move(0, 125);
    label->setAlignment(Qt::AlignCenter);
    label->setText("共0页，正在加载第0页!");

    connect( this, SIGNAL( loadNextPage(int) ), thread, SLOT( loadByPage(int) ) );
    connect(thread, SIGNAL(pageData_loadComplete(QList<QVariant>,int)), this, SLOT(pageDataIsComplete(QList<QVariant>,int)));
    connect(this, SIGNAL(loadImage(QStringList)), thread, SLOT(loadImageByList(QStringList)));
    connect(thread, SIGNAL(imageLoadedSignal(int)), this, SLOT(imageLoadedSlot(int)));

    thread->start();

    btn = new QPushButton(this);
    btn->setText("开始下载");
    connect(btn, SIGNAL(clicked()), this, SLOT(startLoadImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startLoadImage()
{
    delete btn;
    emit loadNextPage(curPage);
}

void MainWindow::pageDataIsComplete(QList<QVariant> pageData, int totalNum)
{
    fabricData = fabricData + pageData;
    curPage++;
    int totalPage = qCeil(totalNum / (double)numPerPage);
    label->setText("共" + QString::number(totalPage) + "页，正在加载第" + QString::number(curPage) + "页!");
    if(curPage >= totalPage){
        label->setText("已加载完成，共" + QString::number(fabricData.size()) + "条数据，正在生成Excel文档！");
        genExcel();
    }else{
        emit loadNextPage(curPage);
    }
}

void MainWindow::genExcel()
{
    using namespace QXlsx;
    Document xlsx;
    QStringList images;
    int row = 0;
    foreach(QVariant v, fabricData){
        QMap<QString, QVariant> map = v.toMap();
        qDebug() << "<<<<" + map["photo_b"].toString() + ">>>>";
        if(map["photo_b"].toString() != ""){
            qDebug() << "has photo";
            row++;
            xlsx.write(row, 1, map["ml_name"]);
            xlsx.write(row, 2, map["jiage"]);
            xlsx.write(row, 3, map["chengfen"]);
            xlsx.write(row, 4, map["shazhi"]);
            xlsx.write(row, 5, map["pinpai"]);

            QStringList arr = map["photo_b"].toString().split("/");
            xlsx.write(row, 6, arr[arr.size() - 1]);

            images.push_back(map["photo_b"].toString());

            QString str;
            if(map["ml_type"].toString() == "xf"){
                str = "否";
            }else{
                str = "是";
            }

            xlsx.write(row, 7, str);
        }
    }
    bool bo = xlsx.saveAs("/Users/abellee/Desktop/fabric.xlsx");
    if(bo){
        label->setText("生成完毕! start load fabric images...");
//        emit loadImage(images);
    }
}

void MainWindow::imageLoadedSlot(int num)
{
    if(num <= 0){
        label->setText("all images are downloaded!");
        return;
    }
    label->setText("remain " + QString::number(num) + " images...");
}
