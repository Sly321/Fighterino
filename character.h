#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

#include <QtWidgets>
#include <QtMultimedia/QSound>
#include "sprite.h"

class Character : public QObject
{
    Q_OBJECT

public:
    explicit Character(int _option = 1, bool enemy = false, QObject *parent = 0);
    void drawChar(QPainter *p, Character *e = NULL);
    int getX();
    int getY();
    int getLife();
    int getMana();
    QImage getIcon();
    QString getName();

private:
    bool walkingLeft;
    bool walkingRight;
    bool stunned;
    bool standing;
    bool jumping;
    bool jumpingUp;
    bool jumpingRight;
    bool jumpingLeft;
    bool crouching;
    bool punching;
    bool lookingLeft;
    bool lookingRight;

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
    Sprite *imgStun;

    QTimer *timer;
    QTimer *secTimer;

    int life;
    int mana;

    /* Global Stuff */
    QImage characterIcon;
    QString characterName;

signals:
    void death();

public slots:
    void moveRight(bool value);
    void moveLeft(bool value);
    void jumpUp();
    void setCrouch(bool value);
    void punch();
    void reduceLife(int redu);
    void setLife(int value);
    void setStunned(bool value);
    bool enemyIsLeft(Character *enemy);
    bool enemyIsRight(Character *enemy);
    bool enemyIsLeftRange(Character *enemy);
    bool enemyIsRightRange(Character *enemy);

private slots:
    void count();
    void calculate();
    void second();

};

#endif // CHARACTER_H
