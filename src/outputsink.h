#ifndef OUTPUTSINK_H
#define OUTPUTSINK_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>

class OutputSink : public QObject
{
    Q_OBJECT
public:
    typedef enum {
        dvi,
        pc,
        mixer,
        monitor,
        recorder,
        beamer
    } t_output_types;

    explicit OutputSink(QObject *parent = 0);


    void attachGUI(QQmlApplicationEngine* engine, QQuickItem* grid);

    void setName(const QString &value);
    void setType(const t_output_types &value);
    void setOutput_number(int value);
    void setActive(bool value);

    void updateLabel();
    QString getLabel();
signals:
    void inputDropped(int outputId);
public slots:

private slots:
    void inputDropped();

private:
    QString name;
    t_output_types type;
    int output_number;
    bool active;
    bool locked;

    QQuickItem *qml;
};

#endif // OUTPUTSINK_H
