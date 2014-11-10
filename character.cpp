#include "character.h"

Character::Character(int _option, QObject *parent) : QObject(parent)
{
    walkingLeft = false;
    walkingRight = false;
    standing = false;

    life = 15;
    mana = 75;
    option = _option;
    timer = new QTimer();
    timer->setInterval(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));

    timer->start();

    xPos = 50;
    yPos = 300;

    switch(option) {
    case 1:
        stand = new Sprite(QImage(":/character/template/stand.png"));
        walk = new Sprite(QImage(":/character/template/walk.png"));

        //jump = new Sprite();
        //crouch = new Sprite();

        break;
    default:
        break;
    }
}

void Character::drawChar(QPainter *p) {
    calculate();
    if (!walkingRight) {
        p->drawImage(xPos, yPos, stand->getImage(imageSequence % 4));
    } else if (walkingRight){
        p->drawImage(xPos, yPos, walk->getImage(imageSequence % 6));
    }
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

void Character::moveRight(bool value) {
    walkingRight = value;
}

void Character::moveLeft(bool value) {
    walkingLeft = value;
}

// integrate moveLeftDone etc.

/**Calculates the position of the Caracter
 *
 * @brief Character::calculate
 */
void Character::calculate() {
    if(walkingRight) {
        xPos = xPos + 2;
    } else if (walkingLeft) {
        xPos = xPos - 2;
    }
}


