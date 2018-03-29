#include "routingcontroller.h"
#include <QQuickItem>

RoutingController::RoutingController(QObject *parent) : QObject(parent)
{
    lastDraggedInput = -1;

    for(int i=0; i< 18; i++)
    {
        inputSourcen[i].setInput_number(i+1);
        inputSourcen[i].setName("");

        outputSinks[i].setOutput_number(i+1);
        outputSinks[i].setName("");
        connect(&outputSinks[i],SIGNAL(inputDropped(int)),this,SLOT(inputDropped(int)));
        connect(&inputSourcen[i],SIGNAL(inputDraged(int)),this,SLOT(inputDraged(int)));
    }

    inputSourcen[0].setType(InputSource::camera);

    inputSourcen[5].setName("Krauti");
    inputSourcen[5].setType(InputSource::pc);

    inputSourcen[7].setName("Roland");
    inputSourcen[7].setType(InputSource::mixer);

    outputSinks[0].setName("Capture 0-00");
    outputSinks[0].setType(OutputSink::pc);

    outputSinks[1].setName("Dell 24\"");
    outputSinks[1].setType(OutputSink::monitor);

    outputSinks[2].setName("Roland 1");
    outputSinks[2].setType(OutputSink::mixer);

    outputSinks[3].setName("Ninja");
    outputSinks[3].setType(OutputSink::recorder);

    outputSinks[4].setName("Beamer L");
    outputSinks[4].setType(OutputSink::beamer);
}

void RoutingController::setEngine(QQmlApplicationEngine *value)
{
    engine = value;


    QQuickItem* myInputGrid = engine->rootObjects().at(0)->findChild<QQuickItem *>("inputRow");
    for(int i=0; i< 18; i++)
    {
        inputSourcen[i].attachGUI(engine, myInputGrid);
    }

    QQuickItem* myOutputGrid = engine->rootObjects().at(0)->findChild<QQuickItem *>("outputRow");
    for(int i=0; i< 18; i++)
    {
        outputSinks[i].attachGUI(engine, myOutputGrid);
    }
}

void RoutingController::inputDropped(int outputId)
{
    if(lastDraggedInput>0 && lastDraggedInput<=18 && outputId > 0 && outputId <= 18 )
    {

        qDebug() << "Routing input " << inputSourcen[lastDraggedInput-1].getLabel() << " to output " << outputSinks[outputId-1].getLabel();
        routenManager.addRoute(lastDraggedInput,outputId);
    }
}

void RoutingController::inputDraged(int inputId)
{
   //qDebug() << "Input dragged: " << inputId;
    lastDraggedInput= inputId;
}
