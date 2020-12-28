#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <string>

class PlayerController : public QObject
{
    Q_OBJECT
public:
    explicit PlayerController(QObject *parent = nullptr);

    Q_SLOT void changePlayerName(std::string playerName);

    Q_SIGNAL void textChanged(const QString& playerName);
};

#endif
