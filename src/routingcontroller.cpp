#include "routingcontroller.h"
#include <QQuickItem>

RoutingController::RoutingController(QObject *parent) : QObject(parent)
{
    for(int i=0; i< 16; i++)
    {
        inputSourcen[i].setInput_number(i+1);
        inputSourcen[i].setName("");
    }

    inputSourcen[5].setName("Krauti");
    inputSourcen[5].setType(InputSource::pc);

    inputSourcen[7].setName("Roland");
    inputSourcen[7].setType(InputSource::mixer);
}

void RoutingController::setEngine(QQmlApplicationEngine *value)
{
    engine = value;


    QQuickItem* myInputGrid = engine->rootObjects().at(0)->findChild<QQuickItem *>("inputRow");

    qDebug() << myInputGrid;

    for(int i=0; i< 16; i++)
    {
        inputSourcen[i].attachGUI(engine, myInputGrid);
    }
}
