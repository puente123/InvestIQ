#include "apicaller.h"
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>
#include <QObject>


ApiCaller::ApiCaller() {
    // Constructor
}

void ApiCaller::getData() {
    qDebug() << "start api get data";
    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");
    QNetworkRequest request(apiUrl);

    // Start the network request asynchronously
    reply = manager.get(request);
    connect(reply, &QNetworkReply::finished, this, &ApiCaller::parseData);
    //connect(this, &ApiCaller::dataArrayFinished, this, &JsonReader::parseData);
}

void ApiCaller::parseData(){
    qDebug() << "start api parse data";
    responseData = reply->readAll();
    reader.parseData(responseData);
    //connect(sender, SIGNAL(signal), receiver, SLOT(slot));
    //emit dataArrayFinished(responseData);
    //connect(this, &ApiCaller::dataArrayFinished, this, &JsonReader::parseData);
}


const QByteArray& ApiCaller::getResponseData() const{
    return responseData;
}


