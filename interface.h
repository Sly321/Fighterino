#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include "character.h"

class Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject *parent = 0);

signals:

public slots:
    void drawInterface(QPainter *p, Character *c);

};

#endif // INTERFACE_H
