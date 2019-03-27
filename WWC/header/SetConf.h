#ifndef MANAGER_H
#define MANAGER_H


#include <QSettings>
#include "Setupable.h"



template<typename Config, typename Object>
class Manager
        : public QObject
{

public:
    explicit Manager(QObject * parent = nullptr)
        : QObject(parent)
    {

        this->settings = new Object(Config::name, ISettings::NativeFormat);
    }


    ~Manager()
    {
        this->settings->sync();
        for (auto && object : this->objects)
        {
            object->set(nullptr, nullptr);
        }

        if (this->settings != nullptr)
        {
            delete this->settings;
            this->settings = nullptr;
        }
    }


    static Manager<Config, Object> * servTo(Setupable *  object, const QMap<QString, QVariant> * defaultConfigValues)
    {
        static Manager<Config, Object> * t{nullptr};

        if (!t)
        {
            t = new Manager<Config, Object>(nullptr);
        }

        object->set(t->settings, defaultConfigValues);


        return t;
        }



private:

    QList<Setupable *> objects;
    ISettings * settings = nullptr;

};



#endif // MANAGER_H
