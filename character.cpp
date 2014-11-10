#include "character.h"

Character::Character(int _option, QObject *parent) : QObject(parent)
{
    walkingLeft = false;
    walkingRight = false;
    standing = false;
    jumping = false;
    jumpingUp = false;
    jumpingRight = false;
    crouching = false;

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
        jump = new Sprite(QImage(":/character/template/jump.png"));
        crouch = new Sprite(QImage(":/character/template/crouch.png"));

        shadow.load(":/character/misc/shadow.png");

        break;
    default:
        break;
    }
}

void Character::drawChar(QPainter *p) {
    calculate();

    //1. Stelle, sonst steht der Schatten auf ihm.
    p->drawImage(xPos + 25, yPos + 75, shadow);

    if (standing) {
        ;
    } else if (jumping) {
        p->drawImage(xPos, yPos + jumpYPos, jump->getImage(0));
    } else if (jumpingRight) {
        // Logische Abfrage, wenn er hochspringt dann nimm das 2. Bild, wenn er runterspringt das 3.
        p->drawImage(xPos, yPos + jumpYPos, jump->getImage(jumpingUp ? 1 : 2));
    } else if (jumpingLeft) {
        p->drawImage(xPos, yPos + jumpYPos, jump->getImage(jumpingUp ? 2 : 1));
    } else if (walkingRight) { //walking right nach jump
        p->drawImage(xPos, yPos + jumpYPos, walk->getImage(imageSequence % 6));
    } else if (walkingLeft) {
        p->drawImage(xPos, yPos + jumpYPos, walk->getImage(imageSequence % 6));
    } else if (crouching) {
        p->drawImage(xPos, yPos, crouch->getImage(0));
    } else {
        p->drawImage(xPos, yPos + jumpYPos, stand->getImage(imageSequence % 4));
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

void Character::setCrouch(bool value) {
    crouching = value;
}

void Character::jumpUp(bool value) {
    if(!jumping && !jumpingRight && !jumpingLeft) {
        if (walkingRight) {
            jumpingRight = true;
            jumpingUp = true;
        } else if (walkingLeft) {
            jumpingLeft = true;
            jumpingUp = true;
        } else /* if (standing) */ {
            jumping = true;
            jumpingUp = true;
        }
    }

}

// integrate moveLeftDone etc.



/**Calculates the position of the Caracter, Nicht anfassen blicke selber manchmal nicht durch.
 *
 * @brief Character::calculate
 */
void Character::calculate() { //xPos + kriegt eine eigene Funktion damit die abfrage

    /* Falls der Character steht, tue nichts */
    if(standing) { // dauerfalse inc
        ;

    /* Platzhalter für etwaige Fähigkeiten */
    } else if (false) {
        ;

    /* Springen */
    } else if (jumping) {
        if (jumpingUp) {
            jumpYPos -= 4;
            jumpingUp = (jumpYPos > -100);
        } else {
            jumpYPos += 4;
            jumping = !(jumpYPos == 0);
        }
    } else if(jumpingRight) {
        if (jumpingUp) {
            jumpYPos -= 4;
            jumpingUp = (jumpYPos > -100);
            xPos += 6;
        } else {
            jumpYPos += 4;
            jumpingRight = !(jumpYPos == 0);
            xPos += 6;
        }
    } else if(jumpingLeft) {
        if (jumpingUp) {
            jumpYPos -= 4;
            jumpingUp = (jumpYPos > -100);
            xPos -= 6;
        } else {
            jumpYPos += 4;
            jumpingLeft = !(jumpYPos == 0);
            xPos -= 6;
        }
    } else if(walkingRight) {
        xPos += 2;
    } else if (walkingLeft) {
        xPos -= 2;
    }
}


