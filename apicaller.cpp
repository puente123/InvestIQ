#include "apicaller.h"
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>

ApiCaller::ApiCaller() {
    // Constructor
}

void ApiCaller::getData() {
    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");
    QNetworkRequest request(apiUrl);

    // Start the network request asynchronously
    manager.get(request);

    connect(&manager, &QNetworkAccessManager::finished, this, [&](QNetworkReply *reply){
        responseData = reply->readAll();
    });
}


const QByteArray& ApiCaller::getResponseData() const{
    return responseData;
}


