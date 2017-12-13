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
        camera,
        pc,
        mixer
    } t_input_types;

    explicit InputSource(QObject *parent = 0);

    void attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid);

    void setName(const QString &value);
    void setType(const t_input_types &value);
    void setInput_number(int value);

    void updateLabel();
signals:
public slots:

private:
    QString name;
    t_input_types type;
    int input_number;
    bool active;

    QQuickItem *rect1Instance;

};

#endif // INPUTSOURCE_H
