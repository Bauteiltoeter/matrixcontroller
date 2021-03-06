#ifndef INPUTSOURCE_H
#define INPUTSOURCE_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>

class InputSource : public QObject
{
    Q_OBJECT


public:
    typedef enum {
        dvi,
        camera,
        pc,
        mixer
    } t_input_types;

    explicit InputSource(QObject *parent = 0);

    void attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid);

    void setName(const QString &value);
    void setType(const t_input_types &value);
    void setInput_number(int value);
    void setActive(bool value);

    void updateLabel();
    QString getLabel();

signals:
    void inputDraged(int i);
public slots:

private slots:
    void inputDraged();
private:
    QString name;
    t_input_types type;
    int input_number;
    bool active;

    QQuickItem *qml;

};

#endif // INPUTSOURCE_H
