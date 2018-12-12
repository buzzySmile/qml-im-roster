#include <QPixmap>
#include "QImContact.h"

class QImContactPrivate
{
public:
    qint64      id;
    QDateTime   updateTime;
    bool        isOnline;
    QDateTime   presence;
    QUrl        avatarUrl;
    QString     fullName;
    qint8       gender;

    QString     error;
    QString     errorMessage;
};

QImContact::QImContact() :
    QObject(),
    d(new QImContactPrivate())
{

}

QImContact::QImContact(const QVariantMap &contact) :
    QObject(),
    d(new QImContactPrivate())
{
    if(contact.contains("error")) {
        d->error = contact.value("error").toString();
        d->errorMessage = contact.value("message").toString();
        return;
    }

    if(contact.contains("id"))
        d->id = contact.value("id", 0).toLongLong();
    if(contact.contains("updateTime"))
        d->updateTime = QDateTime::fromMSecsSinceEpoch(contact.value("updateTime", 0).toLongLong());
    if(contact.contains("presence")) {
        qint64 presence = contact.value("presence", 0).toLongLong();
        if(presence == -1)
            d->isOnline = true;
        else if (presence == 0) {
            d->isOnline = false;
            d->presence = QDateTime();
        }
        else {
            d->isOnline = false;
            d->presence = QDateTime::fromMSecsSinceEpoch(presence);
        }
    }

    if(contact.contains("fullName"))
        d->fullName = contact.value("fullName", "").toString();
    if(contact.contains("gender"))
        d->gender = contact.value("gender", 0).toInt();
    if(contact.contains("avatarUrl"))
        d->avatarUrl = contact.value("avatarUrl", "").toUrl();
}

QImContact::QImContact(const QImContact &other) :
    QObject(),
    d(other.d)
{
}

QImContact& QImContact::operator=(const QImContact &other)
{
    d = other.d;
    return *this;
}

QImContact::~QImContact()
{
}

QVariantMap QImContact::toVariantMap() const
{
    QVariantMap vmap;
    vmap["fullName"] = fullName();
    vmap["presence"] = presence();

    return vmap;
}

QString QImContact::error() const
{
    if(!d->error.isEmpty())
        return d->error;
    else
        return "N/A";
}

QString QImContact::errorMessage() const
{
    if(!d->errorMessage.isEmpty())
        return d->errorMessage;
    else
        return "N/A";
}

qint64 QImContact::id() const
{
    return d->id;
}

QDateTime QImContact::updateTime() const
{
    return d->updateTime;
}

bool QImContact::isOnline() const
{
    return d->isOnline;
}

QDateTime QImContact::presence() const
{
    return d->presence;
}

QString QImContact::fullName() const
{
    return d->fullName;
}

QImContact::Gender QImContact::gender() const
{
    switch (d->gender) {
    case 0:
        return QImContact::UNKNOWN;
    case 1:
        return QImContact::MALE;
    case 2:
        return QImContact::FEMALE;
    default:
        break;
    }
    return QImContact::UNKNOWN;
}

QUrl QImContact::avatarUrl() const
{
    return d->avatarUrl;
}
