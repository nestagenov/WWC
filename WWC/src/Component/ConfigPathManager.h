#ifndef CONFIGPATHMANAGER_H
#define CONFIGPATHMANAGER_H

#include <QString>

#include <QFileInfo>
#include <QDir>
#include <QDebug>


inline QString pathToConfig(const QString &name)
{
    QString localConfigPath = ".config/" + name;
    QString userConfigPath = QDir::homePath() + '/' + localConfigPath;

    QFileInfo localConfigFile(localConfigPath);
    QFileInfo userConfigFile(userConfigPath);

    if (localConfigFile.exists() && localConfigFile.isFile())
    {
        return localConfigPath;
    }
    else if (userConfigFile.exists() && userConfigFile.isFile())
    {
        return userConfigPath;
    }

    return localConfigPath;
}

#endif // CONFIGPATHMANAGER_H
