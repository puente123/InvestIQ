#ifndef APICALLER_H
#define APICALLER_H

#include <QByteArray>
#include <QObject>
#include <QFuture>
#include <QtConcurrent>
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ApiCaller : public QObject
{
    Q_OBJECT


public:
    ApiCaller();

public slots:
    const QByteArray &getResponseData() const;
    void getData();
    void parseData();

signals:
    void dataArrayFinished(const QByteArray &responseData);

private:
    QNetworkAccessManager manager;
    QNetworkReply *reply = nullptr;;
    QByteArray responseData;

};

#endif // APICALLER_H
