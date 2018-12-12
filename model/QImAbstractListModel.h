#ifndef QIMABSTRACTLISTMODEL_H
#define QIMABSTRACTLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class QImAbstractManager;

class QImAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    QImAbstractListModel(QObject *parent = 0);
    virtual ~QImAbstractListModel();

    Q_INVOKABLE QStringList roles() const;

public slots:
    QVariant get(int index, int role) const;
    QVariantMap get(int index) const;
};

#endif // QIMABSTRACTLISTMODEL_H
