#ifndef ISETTINGS_H
#define ISETTINGS_H

#include <string>
#include <QVariant>



class ISettings
{
public:
    enum Format {
        NativeFormat,
        IniFormat,


    };


    virtual void setValue(const QString &key, const QVariant &value) = 0;
    virtual QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const = 0;
    virtual bool contains(const QString &key) const = 0;
    virtual void sync() = 0;
    virtual void setIniCodec(const char *codecName) = 0;
    virtual void beginGroup(const QString &prefix) = 0;
    virtual void endGroup() = 0;
    virtual ~ISettings() = default;


};

#endif // ISETTINGS_H
