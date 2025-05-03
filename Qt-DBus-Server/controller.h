#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void messageReceived(const QString &msg);

public slots:
    void takeMessage(QString msg);
};

#endif // CONTROLLER_H
