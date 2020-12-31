#ifndef BOXCONTROLLER_H
#define BOXCONTROLLER_H

#include <QObject>
#include <string>

// Controller per una singola cella
// Definisce due SIGNAL:
// - textChanged per il cambio del contenuto (X o O)
// - backgroundChanged per il cambio del colore di sfondo
class BoxController : public QObject {
    Q_OBJECT

   public:
    explicit BoxController(QObject* parent = nullptr);

    void updateValue(std::string value);
    void updateBackground(std::string color);

    Q_SIGNAL void textChanged(const QString& text);
    Q_SIGNAL void backgroundChanged(const QString& backgroundColor);
};

#endif
