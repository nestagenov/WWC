#include "checkWWC.h"

checkWWC::checkWWC()
{
    Manager<confPath, QtSettings>::servTo(this, &defaulConfigValues);
}


void checkWWC::setOne(int value)
{
    this->one = value;
}

void checkWWC::setTwo(bool value)
{
    this->two = value;
}

int checkWWC::getOne()
{
    return this->one;
}

bool checkWWC::getTwo()
{
    return this->two;
}

void checkWWC::saveConfig()
{
    if (not settings())
        return;
    settings()->setValue("SomeParameter1", 1024);
    settings()->setValue("SomeParameter2", false);
    settings()->sync();

}

void checkWWC::setupConfig()
{
    if (not settings())
        return;

        setOne(settings()->value("SomeParameter1", defaulConfigValues["SomeParameter1"].toInt()).toInt());
        setTwo(settings()->value("SomeParameter2", defaulConfigValues["SomeParameter2"].toBool()).toBool());


}
