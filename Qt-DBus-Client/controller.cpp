#include "controller.h"
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>
#include <QDBusMessage>
Controller::Controller(QObject *parent)
    : QObject{parent}
{}
void Controller::sendMessage(QString msg) {
    QDBusMessage signal = QDBusMessage::createSignal(
        "/message",
        "org.example.dbus",
        "sendMessageSignals");
    signal << msg;
    QDBusConnection::sessionBus().send(signal);
    emit sendMessageSignals(msg);
}
