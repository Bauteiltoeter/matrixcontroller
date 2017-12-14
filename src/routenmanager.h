#ifndef ROUTENMANAGER_H
#define ROUTENMANAGER_H

#include <QObject>
#include <QList>

class RoutenManager : public QObject
{
    Q_OBJECT
public:
    explicit RoutenManager(QObject *parent = 0);

    void addRoute(int inputId, int outputId);
    void deleteRoute(int inputId, int outputId);
signals:

public slots:

private:
    int searchRouteToOutput(int outputId);

    QList<int> routen[16];
};

#endif // ROUTENMANAGER_H
