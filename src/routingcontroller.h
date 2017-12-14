#ifndef ROUTINGCONTROLLER_H
#define ROUTINGCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "inputsource.h"
#include "outputsink.h"
#include "routenmanager.h"

class RoutingController : public QObject
{
    Q_OBJECT
public:
    explicit RoutingController(QObject *parent = 0);
    void setEngine(QQmlApplicationEngine *value);
signals:

public slots:

private slots:
    void inputDropped(int outputId);
    void inputDraged(int inputId);

private:
    InputSource inputSourcen[16];
    OutputSink  outputSinks[16];
    QQmlApplicationEngine* engine;
    int lastDraggedInput;
    RoutenManager routenManager;
};

#endif // ROUTINGCONTROLLER_H
