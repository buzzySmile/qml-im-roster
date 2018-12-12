#include <QPixmap>

#include "QImDataStorage.h"
#include "QImContactsModel.h"

QImContactsModel::QImContactsModel(QObject *parent) :
    QImAbstractListModel(parent)
{
    mContactList = DataStorageInstance.contacts();
}

QImContactsModel::~QImContactsModel()
{
}

qint64 QImContactsModel::contactId(const QModelIndex &index) const
{
    int row = index.row();
    return mContactList.at(row);
}

QImContact QImContactsModel::contact(const QModelIndex &index) const
{
    return DataStorageInstance.contactEntry(contactId(index));
}

int QImContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mContactList.count();
}

QVariant QImContactsModel::data(const QModelIndex &index, int role) const
{
    switch( role ) {
    case ItemRole:
        return contact(index).toVariantMap();
    case IdRole:
        return contact(index).id();
    case NameRole:
        return contact(index).fullName();
    case AvatarRole:
        return contact(index).avatarUrl();
    case OnlineRole:
        return contact(index).isOnline();
    case PresenceRole:
        if(contact(index).isOnline())
            return "online";
        else if(!contact(index).presence().isValid())
            return "N/A";
        else
            return contact(index).presence().toString();
    case Qt::DisplayRole:
        return contact(index).fullName();
    case Qt::DecorationRole:
        if(contact(index).isOnline())
            return onlineColor;
        else
            return offlineColor;
    default:
        return QVariant();
    }
}

// NOTE: binding for QML
QHash<qint32, QByteArray> QImContactsModel::roleNames() const
{
    static QHash<qint32, QByteArray> *roles = nullptr;
    if( roles )
        return *roles;

    roles = new QHash<qint32, QByteArray>();
    roles->insert(ItemRole, "item");
    roles->insert(IdRole, "id");
    roles->insert(NameRole, "name");
    roles->insert(AvatarRole, "avatar");
    roles->insert(OnlineRole, "isOnline");
    roles->insert(PresenceRole, "presenceTime");

    return *roles;
}

int QImContactsModel::count() const
{
    return mContactList.count();
}

void QImContactsModel::contactsChanged()
{
    beginResetModel();
    mContactList.clear();
    endResetModel();

    beginInsertRows(QModelIndex(), 0, DataStorageInstance.contacts().size());
    mContactList = DataStorageInstance.contacts();
    endInsertRows();

    emit updateFinished();
}
