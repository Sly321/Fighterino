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
    bool jump;
    bool jumpRight;
    bool jumpLeft;

    int option;
    int xPos;
    int yPos;
    int jumpYPos;
    int imageSequence;
    Sprite *stand;
    Sprite *walk;
    //Sprite *jump;
    Sprite *crouch;

    QTimer *timer;

    int life;
    int mana;

signals:

public slots:
    void moveRight(bool value);
    void moveLeft(bool value);
    void jumpUp(bool value);

private slots:
    void count();
    void calculate();


};

#endif // CHARACTER_H
