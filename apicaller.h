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

    const QByteArray &getResponseData() const;

public slots:
    void getData();

signals:
    void responseSaved();

private:
    QNetworkAccessManager manager;
    QByteArray responseData;

};

#endif // APICALLER_H
