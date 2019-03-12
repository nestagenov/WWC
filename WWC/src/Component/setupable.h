#ifndef SETUPABLE_H
#define SETUPABLE_H

#include "QtSettings.h"



class Setupable
{
public:
    Setupable() = default;

    virtual ~Setupable() = default;

    virtual void setupConfig() = 0;
    virtual void saveConfig() {}
    virtual void saveDefaultConfig();

    virtual bool isConfigValid() const;


    ISettings * settings() const;
    void set(ISettings * settings, const QMap<QString, QVariant> * defaultConfigValues);


protected:

    ISettings * m_settings = nullptr;
    const QMap<QString, QVariant> * defaultValues = nullptr;
};


#endif // SETUPABLE_H
