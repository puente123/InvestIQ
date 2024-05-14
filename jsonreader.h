#ifndef JSONREADER_H
#define JSONREADER_H

#include "apicaller.h"

class JsonReader : public QObject
{
    //included macro for the slots and signals
    Q_OBJECT

public:
    JsonReader();

signals:
    void dataReady(const QByteArray &jsonData);

public slots:
    void readJsonData();

private:
    void parseData(const QByteArray &responseData);

private:
    ApiCaller apiCaller; //member variable
};

#endif // JSONREADER_H
