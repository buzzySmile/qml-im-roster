#include "QImDataStorage.h"

class QImDataStoragePrivate
{
public:
    // CONTACTS
    QImContact owner;
    // map of contactId and its contact entry
    QMap<qint64, QImContact> entries;
    // map of contactId and of it's presences
    QMap<qint64, QDateTime> presences;
};

QImDataStorage::QImDataStorage(QObject *parent) :
    d(new QImDataStoragePrivate())
{
    Q_UNUSED(parent)
}

QImDataStorage::~QImDataStorage()
{
    delete d;
}

void QImDataStorage::clear()
{
    delete d;
    d = new QImDataStoragePrivate();
}

QImContact QImDataStorage::ownerContact() const
{
    return d->owner;
}

void QImDataStorage::setOwnerContact(const QImContact &owner_contact)
{
    d->owner = owner_contact;
}

/// Function to get all the contacts present in the address book.
///
/// \return QList<QImContact> list of all the contacts
QList<qint64> QImDataStorage::contacts() const
{
    return d->entries.keys();
}

/// Returns the address book entry of the given contactId. If the contactId is not in the
/// database and empty QImContact will be returned.
///
/// \param contactId as a qint64
QImContact QImDataStorage::contactEntry(qint64 contact_id) const
{
    if(d->entries.contains(contact_id))
        return d->entries.value(contact_id);
    else if(contact_id == d->owner.id())
        return d->owner;
    else
        return QImContact();
}

void QImDataStorage::setContactEntry(const QImContact &contact)
{
    d->entries[contact.id()] = contact;
}

void QImDataStorage::removeContactEntry(qint64 contact_id)
{
    d->entries.remove(contact_id);
    d->presences.remove(contact_id);
}

/// Get presences of the contact by contactId.
///
/// \param contactId as a qint64
QDateTime QImDataStorage::contactPresence(qint64 contact_id) const
{
    if(d->presences.contains(contact_id))
        return d->presences.value(contact_id);
    else
        return QDateTime();     // return invalid QDateTime
}

void QImDataStorage::setContactPresence(qint64 contact_id, QDateTime presence)
{
    d->presences[contact_id] = presence;
}
