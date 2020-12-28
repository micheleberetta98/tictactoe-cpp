#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <sstream>

#include "backend.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Backend* b = new Backend();
    auto boxes = b->boxes();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("backend", b);
    engine.rootContext()->setContextProperty("box0", boxes[0]);
    engine.rootContext()->setContextProperty("box1", boxes[1]);
    engine.rootContext()->setContextProperty("box2", boxes[2]);
    engine.rootContext()->setContextProperty("box3", boxes[3]);
    engine.rootContext()->setContextProperty("box4", boxes[4]);
    engine.rootContext()->setContextProperty("box5", boxes[5]);
    engine.rootContext()->setContextProperty("box6", boxes[6]);
    engine.rootContext()->setContextProperty("box7", boxes[7]);
    engine.rootContext()->setContextProperty("box8", boxes[8]);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
