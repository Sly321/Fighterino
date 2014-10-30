#include "character.h"

Character::Character(int a, QObject *parent) : QObject(parent)
{
    life = 15;
    mana = 75;
    option = 1;
    timer = new QTimer();
    timer->setInterval(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));

    timer->start();

    xPos = 200;
    yPos = 180;

    switch(option) {
    case 1:
        stand = new Sprite(QImage(":/sprites/stand.png"));
        break;
    default:
        break;
    }
}

QImage Character::getChar() {
    return stand->getImage(imageSequence % 4);
}

int Character::getX() {
    return xPos;
}

int Character::getY() {
    return yPos;
}

int Character::getLife() {
    return life;
}

int Character::getMana() {
    return mana;
}

void Character::count() {
    imageSequence++;
}
