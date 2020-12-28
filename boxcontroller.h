#ifndef BOXCONTROLLER_H
#define BOXCONTROLLER_H

#include <QObject>
#include <string>

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
