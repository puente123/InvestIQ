
#include "mainwindow.h"
#include "jsonreader.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create JsonReader object
    JsonReader read;

    // Create MainWindow object
    MainWindow w;

    // Connect signal emitted when JSON data is ready to slot showing the main window
    QObject::connect(&read, &JsonReader::dataReady, &w, &MainWindow::show);

    // Start fetching JSON data asynchronously
    read.readJsonData();

    // Return control to the event loop
    return a.exec();
}

