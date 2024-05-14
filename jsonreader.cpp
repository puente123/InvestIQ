#include "jsonreader.h"
#include "apicaller.h"
#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>


JsonReader::JsonReader() {
    //Constructer Content
}

void JsonReader::readJsonData() {
    ApiCaller apiCaller;
    apiCaller.getData();
    //connect(sender, SIGNAL(signal), receiver, SLOT(slot));
    connect(&apiCaller, &ApiCaller::dataArrayFinished, this, &JsonReader::parseData);
}


//function to seperate data to be stored as dates and values
void JsonReader::parseData(const QByteArray &responseData){
    qDebug() << "Parsing data...";
    /*(const QString filePath = "fast.json.txt";
    QFile file(filePath);

    //checks if file fails to open
    if(!file.open(QIODevice::ReadOnly)){
        qWarning() << "Failed to open file for reading:" << file.errorString();
        return;
    }

    //converts all data from file into a byte array
    //QByteArray jsonData = file.readAll();
    file.close();

    //converts jsonData into a JsonDocument using function "fromJson" this document is what we read
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (jsonDoc.isNull()) {
        qWarning() << "Failed to create JSON document from file.";
        return;
    }*/

    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    QJsonObject rootObject = jsonDoc.object();

    QJsonObject timeSeries = rootObject["Time Series (Daily)"].toObject();

    //creates file to output information to
    QFile outputFile("closing_costs.txt");
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing.";
        return;
    }
    QTextStream out(&outputFile);

    //sets string of dates which are the keys for timeSeries
    const QStringList dates = timeSeries.keys();

    //iterates over each "key or date"
    for(int i = 0; i < dates.size(); i++) {
        const QString &date = dates.at(i);
        //converts each date into a object to be saved
        QJsonObject data = timeSeries[date].toObject();
        //saves the closing cost of each date
        QString closingCost = data["4. close"].toString();
        out << date << "," << closingCost << "\n";
    }

    outputFile.close();
    qDebug() << "Data parsing complete.";
    //emit dataReady(responseData);
}
