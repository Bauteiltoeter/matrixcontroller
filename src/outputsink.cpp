#include "outputsink.h"

OutputSink::OutputSink(QObject *parent) : QObject(parent)
{
    active = true;
    output_number = -1;
    type = dvi;
    name = "";
    qml=NULL;
    locked = false;
}


void OutputSink::attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid)
{
    QQmlComponent rect1(engine,QUrl("qrc:/qml/OutputTile.qml"));

    qml = qobject_cast<QQuickItem *>(rect1.create(engine->contextForObject(grid) ));
    engine->setObjectOwnership(qml,QQmlEngine::JavaScriptOwnership);
    qml->setParentItem(grid);

    updateLabel();
    setType(type);
    setOutput_number(output_number);
    setActive(active);

    connect(qml, SIGNAL(inputDropped()),this, SLOT(inputDropped()));
}

void OutputSink::setName(const QString &value)
{
    name = value;
    qDebug() << "Setting new name for id: " << output_number << value;
    updateLabel();
}

void OutputSink::setType(const t_output_types &value)
{
    type = value;

    if(qml)
    {
        switch(type)
        {
        case monitor: qml->setProperty("icon","monitor.svg"); break;
        case pc:     qml->setProperty("icon","computer.svg"); break;
        case mixer:  qml->setProperty("icon","cutter.svg"); break;
        case recorder: qml->setProperty("icon","recorder.svg"); break;
        case beamer: qml->setProperty("icon","beamer.svg"); break;
        case dvi:    qml->setProperty("icon","dvi.svg"); break;
        }
    }

}

void OutputSink::setOutput_number(int value)
{
    output_number = value;

    if(qml)
        qml->setProperty("inputNumber",value);
}

void OutputSink::updateLabel()
{
    QString label;

    label = getLabel();

    if(qml)
        qml->setProperty("label",label);
}

QString OutputSink::getLabel()
{
    QString label;

    if (name.length() != 0)
        label =  name + " (Out " + QString::number(output_number)+")";
    else
        label = "Output " + QString::number(output_number);

    return label;
}

void OutputSink::inputDropped()
{
    if(!locked)
    {
        emit inputDropped(output_number);
    }
    else
    {
        qDebug() << "Received drop event, but output is locked";
    }
}

void OutputSink::setActive(bool value)
{
    active = value;

    if(qml)
        qml->setProperty("visible",active);
}
