#ifndef QIMCONTACT_H
#define QIMCONTACT_H

#include <QMap>
#include <QDateTime>
#include <QUrl>
#include "qimobjectinterface.h"

class QImContactPrivate;

class QImContact: public QObject, public QImObjectInterface
{
    Q_OBJECT
    Q_ENUMS(Gender)
public:
    static bool alphabetLessThan(const QImContact &contact1, const QImContact &contact2)  {
        return contact1.fullName() < contact2.fullName();
    }
    static bool presenceLessThan(const QImContact &contact1, const QImContact &contact2)  {
        return contact1.presence() > contact2.presence();
    }

    enum Gender {
        MALE,
        FEMALE,
        UNKNOWN
    };

    QImContact();
    QImContact(const QVariantMap &contact);
    QImContact(const QImContact &other);
    QImContact &operator =(const QImContact &other);
    ~QImContact();

    virtual QVariantMap toVariantMap() const;

    virtual QString error() const;
    virtual QString errorMessage() const;

    qint64 id() const;
    bool isOnline() const;
    QDateTime updateTime() const;   // Timestamp, MSecsSinceEpoch
    QDateTime presence() const;     // Timestamp, unix-time

    QString fullName() const;       // User name
    Gender gender() const;          // 0 - N/A, 1 - male, 2 - female
    QUrl avatarUrl() const;         // Avatar URL

private:
    QImContactPrivate *d;
};

#endif // QIMCONTACT_H
