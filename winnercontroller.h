#ifndef WINNERCONTROLLER_H
#define WINNERCONTROLLER_H

#include <QObject>
#include <string>

// Controller per il nome del giocatore che ha vinto.
// Definisce un SIGNAL:
// - textChanged per il cambio del testo da mostrare
class WinnerController : public QObject {
    Q_OBJECT
   public:
    explicit WinnerController(QObject* parent = nullptr);

    void updateWinner(std::string winner);
    Q_SIGNAL void textChanged(const QString& winnerName);
};

#endif
