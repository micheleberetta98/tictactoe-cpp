#ifndef BOXCONTROLLER_H
#define BOXCONTROLLER_H

#include <QObject>

class BoxController : public QObject
{
    Q_OBJECT
private:
    int id;
    char value;
public:
    explicit BoxController(QObject *parent = nullptr);

    void setId(int id);
    Q_SLOT void setValue(char value);

    Q_SIGNAL void textChanged(const QString& text);

};

#endif
