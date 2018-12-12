#include <QVBoxLayout>
#include "model/QImContactsModel.h"
#include "mainwindow.h"

MainWindow::MainWindow(QQmlApplicationEngine *parent) :
    QObject(parent),
    mContactsView(nullptr)
{
    mModel = new QImContactsModel(this);
}

QAbstractListModel *MainWindow::model() const
{
    return mModel;
}
