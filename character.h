#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

#include <QtWidgets>
#include "sprite.h"

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = 0);
    QImage getChar();
    int getX();
    int getY();

private:
    int option;
    int xPos;
    int yPos;
    int imageSequence;
    Sprite *stand;
    Sprite *walk;
    Sprite *jump;
    QTimer *timer;

signals:

public slots:

private slots:
    void count();

};

#endif // CHARACTER_H
