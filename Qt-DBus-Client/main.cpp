#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "controller.h"
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Controller *controller = new Controller();
    if(QDBusConnection::sessionBus().registerObject("/message",controller,QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals | QDBusConnection::ExportAllInvokables | QDBusConnection::ExportNonScriptableSlots | QDBusConnection::ExportScriptableSignals)){
        qDebug() << "++Dbus Objesi Başarıyla Kaydedildi++";
    }else{
        qDebug() << "--Dbus Objesi Kaydedilemedi: "+QDBusConnection::sessionBus().lastError().message();
        return 1;
    }
    if(QDBusConnection::sessionBus().registerService("org.example.dbus")){
        qDebug() << "++Dbus Servis Kaydı Başarılı++";
    }else{
        qDebug() << "--Dbus Servis Kaydı Başarısız : "+QDBusConnection::sessionBus().lastError().message();
        return 1;
    }
    qmlRegisterType<Controller>("com.example.dbus",1,0,"Controller");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
