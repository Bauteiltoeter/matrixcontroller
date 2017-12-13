#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include "routingcontroller.h"

int main(int argc, char *argv[])
{
    RoutingController r;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    r.setEngine(&engine);


    return app.exec();
}
