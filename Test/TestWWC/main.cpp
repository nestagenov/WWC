#include <QCoreApplication>
#include <QDebug>
#include "checkWWC.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    checkWWC t = checkWWC();
    t.saveConfig();
    qDebug() << "stop"<<endl;
    return a.exec();
}
