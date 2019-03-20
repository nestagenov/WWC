#include <QCoreApplication>
#include <QDebug>
#include "checkWWC.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    checkWWC example1 = checkWWC();
    qDebug() << example1.getOne() << " "<< example1.getTwo() <<endl;
    example1.saveConfig();
    checkWWC example2 = checkWWC();
    qDebug() << example2.getOne() << " "<< example2.getTwo() <<endl;


    return a.exec();
}
