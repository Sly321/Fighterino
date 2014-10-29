#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{
    option = 1;
    timer = new QTimer();
    timer->setInterval(50);
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

void Character::count() {
    imageSequence++;
}
