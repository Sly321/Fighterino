#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

#include <QtWidgets>
#include "sprite.h"

class Character : public QObject
{
    Q_OBJECT

public:
    explicit Character(int _option, QObject *parent = 0);
    void drawChar(QPainter *p);
    int getX();
    int getY();
    int getLife();
    int getMana();

private:
    bool walkingLeft;
    bool walkingRight;
    bool standing;
    bool jumping;
    bool jumpingUp;
    bool jumpingRight;
    bool jumpingLeft;
    bool crouching;
    bool punching;

    int option;
    int xPos;
    int yPos;
    int jumpYPos;
    int imageSequence;
    int punchCount;

    QImage shadow;
    Sprite *stand;
    Sprite *walk;
    Sprite *jump;
    Sprite *crouch;
    Sprite *imgPunch;

    QTimer *timer;
    QTimer *secTimer;

    int life;
    int mana;

signals:

public slots:
    void moveRight(bool value);
    void moveLeft(bool value);
    void jumpUp(bool value);
    void setCrouch(bool value);
    void punch();

private slots:
    void count();
    void calculate();
    void second();

};

#endif // CHARACTER_H
