#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include "gamecontroller.h"
#include "lib/game.h"
#include "playercontroller.h"
#include "winnercontroller.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Istanziamento dei vari controller
    std::shared_ptr<GameController> game{new GameController()};
    auto boxes = game->boxControllers();
    auto currentPlayer = game->playerController();
    auto winner = game->winnerController();

    QQmlApplicationEngine engine;
    // I controller sono esposti al QML: in questo modo
    // è possibile realizzare le connessioni in attesa degli eventi
    engine.rootContext()->setContextProperty("game", game.get());
    engine.rootContext()->setContextProperty("currentPlayer", currentPlayer);
    engine.rootContext()->setContextProperty("winner", winner);
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
