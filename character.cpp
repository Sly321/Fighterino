#include "character.h"

Character::Character(int _option, QObject *parent) : QObject(parent)
{
    walkingLeft = false;
    walkingRight = false;
    standing = false;
    jumping = false;
    jumpingRight = false;

    life = 15;
    mana = 75;
    option = _option;
    timer = new QTimer();
    timer->setInterval(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));

    timer->start();

    xPos = 50;
    yPos = 300;
    jumpYPos = 0;

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
        p->drawImage(xPos, yPos + jumpYPos, stand->getImage(imageSequence % 4));
    } else if (walkingRight){
        p->drawImage(xPos, yPos + jumpYPos, walk->getImage(imageSequence % 6));
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

void Character::jumpUp(bool value) {
    if(walkingRight) {
        jumpingRight = true;
    } else {
        jumping = value;
    }

}

// integrate moveLeftDone etc.

/**Calculates the position of the Caracter
 *
 * @brief Character::calculate
 */
void Character::calculate() { //xPos + kriegt eine eigene Funktion damit die abfrage
    if(jumpingRight) {
        if (jumpYPos >= -90) {
            jumpYPos -= 4;
            xPos += 4;
        } else {
            jumpingRight = false;
        }
    } else if(jumping) {
        if (jumpYPos >= -90) {
            jumpYPos -= 4;
            xPos += 4;
        } else {
            jumping = false;
        }
    } else if (!jumping && jumpYPos < 0) {
        jumpYPos += 4;
    } else if(walkingRight) {
        xPos = xPos + 2;
    } else if (walkingLeft) {
        xPos = xPos - 2;
    }
}


