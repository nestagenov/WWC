#ifndef CHECKWWC_H
#define CHECKWWC_H
#include "WWC.h"
#include <QObject>
#include "confPath.h"


class checkWWC: public Setupable
{
public:
    checkWWC();

    void setupConfig() override;
    void saveConfig() override;

    void setOne(int);
    void setTwo(bool);

private:

    QMap<QString, QVariant> defaulConfigValues = {
        {"SomeParameter1", 21},
        {"SomeParameter2", true}
    };
    int one;
    bool two;
};

#endif // CHECKWWC_H
