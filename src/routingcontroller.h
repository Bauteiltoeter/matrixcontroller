#ifndef ROUTINGCONTROLLER_H
#define ROUTINGCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "inputsource.h"

class RoutingController : public QObject
{
    Q_OBJECT
public:
    explicit RoutingController(QObject *parent = 0);
    void setEngine(QQmlApplicationEngine *value);
signals:

public slots:

private:
    InputSource inputSourcen[16];
    QQmlApplicationEngine* engine;
};

#endif // ROUTINGCONTROLLER_H
