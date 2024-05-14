
#include "mainwindow.h"
#include "jsonreader.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ApiCaller api;

    // Create JsonReader object
    JsonReader read;

    // Create MainWindow object
    MainWindow w;

    api.getData();
    read.parseData(api.getResponseData());

    w.show();
    // Return control to the event loop
    return a.exec();
}

