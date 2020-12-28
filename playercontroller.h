#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <string>

class PlayerController : public QObject {
    Q_OBJECT
   public:
    explicit PlayerController(QObject* parent = nullptr);

    void updatePlayerName(std::string playerName);

    Q_SIGNAL void textChanged(const QString& playerName);
};

#endif
