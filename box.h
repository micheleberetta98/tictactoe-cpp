#ifndef BOX_H
#define BOX_H

#include <QObject>

class Box : public QObject
{
    int id;
    char value;

    Q_OBJECT
public:
    explicit Box(QObject *parent = nullptr);

    void setId(int);
    void setValue(char);

    Q_SIGNAL void textChanged(const QString& text);

};

#endif
