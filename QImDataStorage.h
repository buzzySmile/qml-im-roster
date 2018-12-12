#ifndef QIMDATASTORAGE
#define QIMDATASTORAGE

#include "singletone/singleton.h"

#include "common/QImContact.h"

class QImDataStoragePrivate;

class QImDataStorage : public QObject
{
    Q_OBJECT
public:
    QImDataStorage(QObject* parent = nullptr);
    ~QImDataStorage();

    void clear();

    QImContact ownerContact() const;
    void setOwnerContact(const QImContact &owner_contact);

    QList<qint64> contacts() const;

    QImContact contactEntry(qint64 contact_id) const;
    void setContactEntry(const QImContact &contact);
    void removeContactEntry(qint64 contact_id);

    QDateTime contactPresence(qint64 contact_id) const;
    void setContactPresence(qint64 contact_id, QDateTime presence);   

private:
    QImDataStoragePrivate *d;
};

#define DataStorageInstance Singleton<QImDataStorage>::instance()

#endif // QIMDATASTORAGE
