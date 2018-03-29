#include "routenmanager.h"

#include <QDebug>

RoutenManager::RoutenManager(QObject *parent) : QObject(parent)
{

}

void RoutenManager::addRoute(int inputId, int outputId)
{
    if(inputId < 0 && inputId >16)
    {
        qDebug() << "RoutenManager::addRoute inputId out of range (" << inputId << ")";
        return;
    }

    if(outputId < 0 && outputId >16)
    {
        qDebug() << "RoutenManager::addRoute outputId out of range (" << outputId << ")";
        return;
    }

    int oldRoute = searchRouteToOutput(outputId);
    if(oldRoute==-1)
    {
        qDebug() << "no route to output, creating new one!";
        routen[inputId-1].append(outputId);
    }
    else
    {
        qDebug() << "Found old route, deleting it and creating a new one!";
        deleteRoute(oldRoute, outputId);
        routen[inputId-1].append(outputId);
    }
}

void RoutenManager::deleteRoute(int inputId, int outputId)
{
    routen[inputId-1].removeOne(outputId);
}

int RoutenManager::searchRouteToOutput(int outputId)
{
    for( int i=0; i < 16; i++)
    {
        if(routen[i].contains(outputId))
        {
            qDebug() << "Found route to output " << outputId << "from input " << i+1;
            return i+1;
        }
    }

    qDebug() << "No route to output " << outputId;
    return -1;

}
