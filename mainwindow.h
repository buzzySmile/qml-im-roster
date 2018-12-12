#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QQmlApplicationEngine>
#include <QAbstractListModel>

class QImContactsModel;

class MainWindow : public QObject
{
    Q_OBJECT
public:
    MainWindow(QQmlApplicationEngine *parent = nullptr);

    Q_INVOKABLE QAbstractListModel *model() const;

private:
    QImContactsModel *mModel;
    QWidget *mContactsView;
};

#endif // MAINWINDOW_H
