#ifndef JSONREADER_H
#define JSONREADER_H

#include "apicaller.h"
#include <QObject>

class JsonReader : public QObject
{
    Q_OBJECT
    //included macro for the slots and signals


public:
    JsonReader();

public slots:
    void parseData(const QByteArray &responseData);
    void readJsonData();


/*private:
    ApiCaller apiCaller; //member variable*/
};

#endif // JSONREADER_H
