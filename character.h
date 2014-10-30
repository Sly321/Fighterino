#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

#include <QtWidgets>
#include "sprite.h"

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(int a, QObject *parent = 0);
    QImage getChar();
    int getX();
    int getY();
    int getLife();
    int getMana();

private:
    int option;
    int xPos;
    int yPos;
    int imageSequence;
    Sprite *stand;
    Sprite *walk;
    Sprite *jump;
    QTimer *timer;

    int life;
    int mana;

signals:

public slots:

private slots:
    void count();

};

#endif // CHARACTER_H
