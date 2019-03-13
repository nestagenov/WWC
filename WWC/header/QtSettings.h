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
        setSettings()->setValue(key, value);
    }

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const override
    {
        return setSettings()->value(key, defaultValue);
    }

     bool contains(const QString &key) const override
    {
        return setSettings()->contains(key);
    }

     void sync() override
    {
        setSettings()->sync();
    }

    void setIniCodec(const char * codecName) override
    {
        setSettings()->setIniCodec(codecName);
    }

     void beginGroup(const QString &prefix) override
    {
        setSettings()->beginGroup(prefix);
    }

     void endGroup() override
    {
        setSettings()->endGroup();
    }



private:
    QSettings * setSettings() const
    {
        return my_settings;
    }

private:
  QSettings * my_settings = nullptr;
};





#endif // QTSETTINGS_H
