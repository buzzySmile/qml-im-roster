#include <QCoreApplication>
#include <QApplication>
#include <QDateTime>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QDir>

#include "QImDataStorage.h"
#include "mainwindow.h"


void FillDataStorage()
{
    QVariantMap contact;

    contact["id"]         = 138974544;
    contact["fullName"]   = "Ingmar Bergman";
    contact["avatarUrl"]  = "https://upload.wikimedia.org/wikipedia/commons/f/f2/Ingmar_Bergman_(1966).jpg";    // https://upload.wikimedia.org/wikipedia/commons/f/f2/Ingmar_Bergman_%281966%29.jpg
    contact["presence"]   = QDateTime::fromTime_t(1185753600).toMSecsSinceEpoch();
    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
    contact["gender"]     = 1;
    DataStorageInstance.setContactEntry(QImContact(contact));

    contact["id"]         = 93242344;
    contact["fullName"]   = "Andrei Tarkovsky";
    contact["avatarUrl"]  = "https://pbs.twimg.com/profile_images/815920049743601664/5wO_ejUu_400x400.jpg";
    contact["presence"]   = QDateTime::fromTime_t(536095788).toMSecsSinceEpoch();
    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
    contact["gender"]     = 1;
    DataStorageInstance.setContactEntry(QImContact(contact));

    contact["id"]         = 94444444;
    contact["fullName"]   = "Roman Polanski";
    contact["avatarUrl"]  = "https://www.famousbirthdays.com/headshots/roman-polanski-3.jpg";
    contact["presence"]   = -1;
    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
    contact["gender"]     = 1;
    DataStorageInstance.setContactEntry(QImContact(contact));

    contact["id"]         = 55555555;
    contact["fullName"]   = "Stanley Kubrick";
    contact["avatarUrl"]  = "http://www.cultjer.com/img/ug_photo/2014_04/StanelyKubrick__12103001160820140422154926_440.jpg";
    contact["presence"]   = QDateTime::fromTime_t(920764800).toMSecsSinceEpoch();
    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
    contact["gender"]     = 1;
    DataStorageInstance.setContactEntry(QImContact(contact));

    contact["id"]         = 66666666;
    contact["fullName"]   = "David Lynch";
    contact["avatarUrl"]  = "https://upload.wikimedia.org/wikipedia/commons/thumb/3/3b/David_Lynch_head_07.jpg/220px-David_Lynch_head_07.jpg";
    contact["presence"]   = -1;
    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
    contact["gender"]     = 1;
    DataStorageInstance.setContactEntry(QImContact(contact));

//    contact["id"]         = 77777777;
//    contact["fullName"]   = "Unknown director";
//    contact["avatarUrl"]  = "https://postalinspectors.uspis.gov/radImages/wanted/silhouette.jpg";
//    contact["presence"]   = 0;
//    contact["updateTime"] = QDateTime::currentMSecsSinceEpoch();
//    contact["gender"]     = 0;
//    DataStorageInstance.setContactEntry(QImContact(contact));
}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QQmlApplicationEngine engine;
    FillDataStorage();

    QCoreApplication::setApplicationName("QML_List_example");
    const QString appPath = QCoreApplication::applicationDirPath();

    // This allows starting without previously defining QML2_IMPORT_PATH.
    QDir qmlImportDir(appPath);
#if defined (Q_OS_WIN)
    qmlImportDir.cd("..");
#endif
    qmlImportDir.cd("../../../qml");
    engine.addImportPath(qmlImportDir.canonicalPath());
    // Manage import paths for Linux and OSX.
    QStringList importPathList = engine.importPathList();
    importPathList.prepend(QCoreApplication::applicationDirPath() + "/qml");
    engine.setImportPathList(importPathList);

    // create gui object
    MainWindow *clientGui = new MainWindow(&engine);
    QAbstractListModel *model = clientGui->model();
    engine.rootContext()->setContextProperty("clientContext", clientGui);
    engine.rootContext()->setContextProperty("contactsModel", model);

    engine.load(QUrl("qrc:///qml/main.qml"));

    // Quit the application when the engine closes.
    QObject::connect((QObject*) &engine, SIGNAL(quit()), (QObject*) &app, SLOT(quit()));

    return app.exec();
}
