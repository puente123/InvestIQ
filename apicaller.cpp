#include "apicaller.h"
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>

ApiCaller::ApiCaller() {
    // Constructor
}

QFuture<QByteArray> ApiCaller::getData() {
    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");
    QNetworkRequest request(apiUrl);

    // Start the network request asynchronously
    QNetworkReply* reply = manager.get(request);

    // Create a QFutureInterface for managing the future result
    QFutureInterface<QByteArray> futureInterface;

    // Connect the reply's finished signal to a lambda function
    QObject::connect(reply, &QNetworkReply::finished, [=]() mutable {
        QByteArray responseData;
        if (reply->error() == QNetworkReply::NoError) {
            responseData = reply->readAll();
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        // Clean up the reply object
        reply->deleteLater();

        // Report the result to the future interface
        futureInterface.reportResult(responseData);
    });

    // Start the future interface and return the future
    futureInterface.reportStarted();
    return futureInterface.future();
}


/*QFuture<QByteArray> ApiCaller::getData() {
    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");
    QNetworkRequest request(apiUrl);

    //starts asynchronous operation
    QFuture<QByteArray> future = QtConcurrent::run([=]() {
        //starts network request to get stock data
        QNetworkReply *reply = manager.get(request);

        //prevents the code from continuing until network request is finished
        QEventLoop loop;
        //connects the finished signal so loop quits when done
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        //saves the data from the API call
        QByteArray responseData;
        if (reply->error() == QNetworkReply::NoError) {
            responseData = reply->readAll();
        } else {
            qDebug() << "Error:" << reply->errorString();
        }
        reply->deleteLater();

        //returns the QByteArray for the lamdba function
        return responseData;
    });

    //returns future for the entire function
    return future;
}*/


/*void ApiCaller::getData(){
    //maybe make manager a class variable
    QNetworkAccessManager manager;

    QUrl apiUrl("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=demo");

    QNetworkRequest request(apiUrl);

    QNetworkReply *reply = manager.get(request);

    QObject::connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << "Response:" << responseData;
            emit dataReady(responseData); // Emit signal with the response data
        } else {
            qDebug() << "Error:" << reply->errorString();
        }
        reply->deleteLater();
    });

}*/
