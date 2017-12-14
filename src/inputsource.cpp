#include "inputsource.h"
#include <QDebug>

InputSource::InputSource(QObject *parent) : QObject(parent)
{
    active = true;
    input_number = -1;
    type = dvi;
    name = "";
    qml=NULL;
}

void InputSource::attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid)
{
    QQmlComponent rect1(engine,QUrl("qrc:/qml/InputSourceTile.qml"));

    qml = qobject_cast<QQuickItem *>(rect1.create(engine->contextForObject(grid) ));
    engine->setObjectOwnership(qml,QQmlEngine::JavaScriptOwnership);

    qml->setParentItem(grid);

    updateLabel();
    setType(type);
    setInput_number(input_number);
    setActive(active);

    connect(qml, SIGNAL(draged()),this, SLOT(inputDraged()));
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

    if(qml)
    {
        switch(type)
        {
        case camera: qml->setProperty("icon","videocam.svg"); break;
        case pc:     qml->setProperty("icon","computer.svg"); break;
        case mixer:  qml->setProperty("icon","cutter.svg"); break;
        case dvi:    qml->setProperty("icon","dvi.svg"); break;
        }
    }

}

void InputSource::setInput_number(int value)
{
    input_number = value;

    if(qml)
        qml->setProperty("inputNumber",value);
}

void InputSource::updateLabel()
{
    QString label = getLabel();

    if(qml)
        qml->setProperty("label",label);
}

QString InputSource::getLabel()
{
    QString label;

    if (name.length() != 0)
        label =  name + " (In " + QString::number(input_number)+")";
    else
        label = "Input " + QString::number(input_number);

    return label;
}

void InputSource::inputDraged()
{
    emit inputDraged(input_number);
}

void InputSource::setActive(bool value)
{
    active = value;

    if(qml)
        qml->setProperty("visible",active);
}
