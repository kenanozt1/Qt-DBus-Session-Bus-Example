#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","org.example.dbus")
public:
    explicit Controller(QObject *parent = nullptr);

    Q_SCRIPTABLE void sendMessage(QString msg);
signals:
    Q_SCRIPTABLE void sendMessageSignals(const QString msg);

signals:
};

#endif // CONTROLLER_H
