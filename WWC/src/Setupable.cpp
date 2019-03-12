#include "Setupable.h"


void Setupable::saveDefaultConfig()
{
   if (!defaultValues)
   {
       return;
   }

   Q_ASSERT(settings());

   for (const auto& key : defaultValues->keys())
   {
       if (settings()->contains(key) == false || settings()->value(key).isValid() == false)
       {
           settings()->setValue(key, defaultValues->value(key));
       }
   }
   settings()->sync();
}

bool Setupable::isConfigValid() const
{
   if (!defaultValues)
   {
       return false;
   }

   Q_ASSERT(settings());
   for (const auto& key : defaultValues->keys())
   {
       if (settings()->contains(key) == false || settings()->value(key).isValid() == false) //isValid ф\я для qVariant, которая возвратит true если тип не принадлежит метатипу, те типу созданному нами
       {
           return false;
       }
   }
   return true;
}

ISettings * Setupable::settings() const
{
   return m_settings;
}

void Setupable::set(ISettings * settings, const QMap<QString, QVariant> * defaultConfigValues)
{
   m_settings = settings;
   defaultValues = defaultConfigValues;

   if (m_settings != nullptr)
   {

       if (isConfigValid() == false)
       {
           saveDefaultConfig();
           m_settings->sync();
       }

       setupConfig();
   }
}
