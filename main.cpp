
#include "mainwindow.h"
#include "jsonreader.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //ApiCaller api;

    // Create JsonReader object
    JsonReader read;

    // Create MainWindow object
    MainWindow w;

    read.readJsonData();


    w.show();
    // Return control to the event loop
    return a.exec();
}

