#ifndef BOXCONTROLLER_H
#define BOXCONTROLLER_H

#include <QObject>
#include <string>

class BoxController : public QObject
{
    Q_OBJECT
private:
    int id;
    std::string value;
public:
    explicit BoxController(QObject *parent = nullptr);

    void setId(int id);
    Q_SLOT void setValue(std::string value);

    Q_SIGNAL void textChanged(const QString& text);

};

#endif
