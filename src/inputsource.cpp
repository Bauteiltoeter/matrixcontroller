#include "inputsource.h"
#include <QDebug>

InputSource::InputSource(QObject *parent) : QObject(parent)
{
    active = false;
    input_number = -1;
    type = camera;
    name = "";
    rect1Instance=NULL;
}

void InputSource::attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid)
{
    QQmlComponent rect1(engine,grid);


    rect1.loadUrl(QUrl("qrc:/qml/InputSourceTile.qml"));

    rect1Instance = qobject_cast<QQuickItem *>(rect1.create( engine->rootContext() ));


    engine->setObjectOwnership(rect1Instance,QQmlEngine::JavaScriptOwnership);


    rect1Instance->setParentItem(grid);


    updateLabel();
    setType(type);
    setInput_number(input_number);
}

void InputSource::setName(const QString &value)
{
    name = value;
    qDebug() << "Setting new name for id: " << input_number << value;
    updateLabel();
}

void InputSource::setType(const t_input_types &value)
{
    type = value;

    if(rect1Instance)
    {
        switch(type)
        {
        case camera: rect1Instance->setProperty("icon","videocam.svg"); break;
        case pc:     rect1Instance->setProperty("icon","computer.svg"); break;
        case mixer:  rect1Instance->setProperty("icon","cutter.svg"); break;

        }
    }

}

void InputSource::setInput_number(int value)
{
    input_number = value;

    if(rect1Instance)
        rect1Instance->setProperty("inputNumber",value);
}

void InputSource::updateLabel()
{
    QString label="lool";

    if (name.length() != 0)
        label =  name + " (In " + QString::number(input_number)+")";
    else
        label = "Input " + QString::number(input_number);

    if(rect1Instance)
        rect1Instance->setProperty("label",label);
}
