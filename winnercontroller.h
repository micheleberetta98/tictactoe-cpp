#ifndef WINNERCONTROLLER_H
#define WINNERCONTROLLER_H

#include <QObject>
#include <string>

class WinnerController : public QObject
{
    Q_OBJECT
public:
    explicit WinnerController(QObject *parent = nullptr);

    void updateWinner(std::string winner);
    Q_SIGNAL void textChanged(const QString& winnerName);

};

#endif
