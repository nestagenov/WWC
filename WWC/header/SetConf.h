#ifndef SETTINGS_H
#define SETTINGS_H


#include <QSettings>
#include "Setupable.h"



template<typename T, typename G>
class SetConfig
        : public QObject
{

public:
    explicit SetConfig(QObject * parent = nullptr)
        : QObject(parent)
    {

        this->settings = new G(T::path, ISettings::NativeFormat);
        //this->settings->setIniCodec("UTF-8");
    }


    ~SetConfig()
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


    static SetConfig<T, G> * servTo(Setupable *  object, const QMap<QString, QVariant> * defaultConfigValues)
    {
        static SetConfig<T, G> * t{nullptr};

        if (!t)
        {
            t = new SetConfig<T, G>(nullptr);
        }

        object->set(t->settings, defaultConfigValues);


        return t;
        }



private:

    QList<Setupable *> objects;
    ISettings * settings = nullptr;

};



#endif // SETTINGS_H
