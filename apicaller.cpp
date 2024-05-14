#include "apicaller.h"
#include "jsonreader.h"
//#include "apicaller.moc"
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
    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");
    QNetworkRequest request(apiUrl);

    // Start the network request asynchronously
    reply = manager.get(request);
    connect(reply, &QNetworkReply::finished, this, &ApiCaller::parseData);
    //connect(this, &ApiCaller::dataArrayFinished, this, &JsonReader::parseData);
}

void ApiCaller::parseData(){
    responseData = reply->readAll();
    emit dataArrayFinished(responseData);
}


const QByteArray& ApiCaller::getResponseData() const{
    return responseData;
}


