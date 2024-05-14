#ifndef APICALLER_H
#define APICALLER_H

#include <QByteArray>
#include <QObject>
#include <QFuture>
#include <QtConcurrent>
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ApiCaller
{

public:
    ApiCaller();
    QFuture<QByteArray> getData();

private:
    QNetworkAccessManager manager;

/*public slots:
    //void getData();


signals:
    void dataReady(const QByteArray &responseData);*/
};

#endif // APICALLER_H
