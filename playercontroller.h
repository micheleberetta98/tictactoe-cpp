#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <string>

// Controller per il nome del giocatore che deve muovere.
// Definisce un SIGNAL:
// - textChanged per il cambio del testo da mostrare
class PlayerController : public QObject {
    Q_OBJECT
   public:
    explicit PlayerController(QObject* parent = nullptr);

    void updatePlayerName(std::string playerName);

    Q_SIGNAL void textChanged(const QString& playerName);
};

#endif
