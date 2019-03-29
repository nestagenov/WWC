#ifndef QTSETTINGS_H
#define QTSETTINGS_H
#include "ISettings.h"

#include <QSettings>




class QtSettings: public ISettings
{
public:

     QtSettings(const QString &fileName, Format format = NativeFormat, QObject *parent = nullptr)
    {

         if (format == IniFormat)
             this->my_settings = new QSettings(fileName, QSettings::IniFormat, parent);
         else
             this->my_settings = new QSettings(fileName, QSettings::NativeFormat, parent);

     }



    void setValue(const QString &key, const QVariant &value) override
    {
        my_settings->setValue(key, value);
    }

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const override
    {
        return my_settings->value(key, defaultValue);
    }

     bool contains(const QString &key) const override
    {
        return my_settings->contains(key);
    }

     void sync() override
    {
        my_settings->sync();
    }

    void setIniCodec(const char * codecName) override
    {
       my_settings->setIniCodec(codecName);
    }

     void beginGroup(const QString &prefix) override
    {
        my_settings->beginGroup(prefix);
    }

     void endGroup() override
    {
        this->my_settings->endGroup();
    }



private:
  QSettings * my_settings = nullptr;
};





#endif // QTSETTINGS_H
