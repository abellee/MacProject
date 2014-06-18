#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVariant>
#include <QList>

class DataThread : public QThread
{
    Q_OBJECT
public:
    explicit DataThread(QObject *parent = 0);
    void run();
    void loadImages();
    QNetworkReply *reply;
    QNetworkAccessManager *mgr;
    QStringList imagesList;
    QStringList failedList;

signals:
    void pageData_loadComplete(QList<QVariant> pageData, int totalNum);
    void imageLoadedSignal(int num);

public slots:
    void loadByPage(int page);
    void read(QNetworkReply *reply);
    void loadImageByList(QStringList list);
    void imageLoadComplete(QNetworkReply *reply);
};

#endif // DATATHREAD_H
