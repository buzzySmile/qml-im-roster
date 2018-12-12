#ifndef QIMCONTACTSMODEL_H
#define QIMCONTACTSMODEL_H

#include <QColor>

#include "QImAbstractListModel.h"
#include "common/QImContact.h"

class QImContactsModelPrivate;

class QImContactsModel : public QImAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(ContactsRoles)

public:
    enum ContactsRoles {
        ItemRole = Qt::UserRole,
        IdRole = Qt::UserRole + 1,
        NameRole,
        AvatarRole,
        OnlineRole,
        PresenceRole
    };

    const QColor onlineColor = QColor(90, 190, 80, 127);
    const QColor offlineColor = QColor(255, 100, 95, 127);

    QImContactsModel(QObject *parent = nullptr);
    ~QImContactsModel();

    qint64 contactId(const QModelIndex &index) const;
    QImContact contact(const QModelIndex &index) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QHash<qint32, QByteArray> roleNames() const;

    int count() const;

signals:
    void countChanged();
    void updateFinished();

private slots:
    void contactsChanged();

private:
    QList<qint64> mContactList;
};

#endif // QIMCONTACTSMODEL_H
