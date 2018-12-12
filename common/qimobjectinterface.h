#ifndef QIMOBJECTINTERFACE
#define QIMOBJECTINTERFACE

#include <QVariant>


class QImObjectInterface
{
public:
    virtual ~QImObjectInterface() {}

    virtual QVariantMap toVariantMap() const = 0;

    virtual QString error() const = 0;
    virtual QString errorMessage() const = 0;
};

#endif // QIMOBJECTINTERFACE
