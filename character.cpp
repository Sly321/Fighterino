#include "character.h"

/**
 * @brief Character::Character
 *
 * Diese Klasse ist vollständig für das Zeichnen und Bewegen des
 * Charakters zuständig. Sie wird von Draw.cpp aufgerufen.
 * Um neue Bilder einzufügen muss nur im Contructer ein Case
 * hinzugefügt werden, z.B. Case 2. Nun kann dann im Auswahlmenu
 * für Charaktere die 2 gewählt werden (Mitte oben) und die Bilder
 * dieses Charakteres werden geladen. Achte darauf alle Bilder, und
 * auch auf die richtige größe eingefügt zu haben. Sonst wird es nicht
 * funktionieren. Shadow kann so geladen werden wie er ist, er wird
 * für alle Charaktere benutzt.
 *
 * @param _option
 * @param parent
 */
Character::Character(int _option, QObject *parent) : QObject(parent)
{
    walkingLeft = false;
    walkingRight = false;
    standing = false;
    jumping = false;
    jumpingUp = false;
    jumpingRight = false;
    jumpingLeft = false;
    crouching = false;
    punching = false;
    lookingLeft = false;
    lookingRight = true;
    imageSequence = 0;

    punchCount = 0;
    life = 150;
    mana = 150;
    option = _option;

    timer = new QTimer();
    timer->setInterval(120);
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));
    timer->start();

    secTimer = new QTimer();
    secTimer->setInterval(1000);
    connect(secTimer, SIGNAL(timeout()), this, SLOT(second()));
    secTimer->start();

    xPos = 50;
    yPos = 300;
    jumpYPos = 0;

    switch(option) {
    case 1:
        /* HIER NEUE BILDER Z.B. // Das hier ist ein template und kann benutzt werden */

        /* Von hier ab neue Pfade angeben, einfach zu der Ressourcedatei hinzufügen (Auf präfix achten) */
        stand = new Sprite(QImage(":/character/asuma/stand_asuma.png"));
        walk = new Sprite(QImage(":/character/asuma/walk_asuma.png"));
        jump = new Sprite(QImage(":/character/asuma/jump_asuma.png"));
        crouch = new Sprite(QImage(":/character/asuma/crouch_asuma.png"));
        imgPunch = new Sprite(QImage(":/character/asuma/punching_asuma.png"));
        /* Fertig ! */
        shadow.load(":/character/misc/shadow.png"); // Brauch nicht verändert werden
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        stand = new Sprite(QImage(":/character/template/stand.png"));
        walk = new Sprite(QImage(":/character/template/walk.png"));
        jump = new Sprite(QImage(":/character/template/jump.png"));
        crouch = new Sprite(QImage(":/character/template/crouch.png"));
        imgPunch = new Sprite(QImage(":/character/template/punching.png"));
        shadow.load(":/character/misc/shadow.png");
        break;
    default:
        break;
    }
}

/**
 * @brief Character::drawChar
 *
 * Zeichnet den Charakter, je nach Zustand.
 *
 * @param p
 */
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
        p->drawImage(xPos, yPos + jumpYPos, jump->getImageMirrored(jumpingUp ? 2 : 1));
    } else if (walkingRight) { //walking right nach jump
        p->drawImage(xPos, yPos + jumpYPos, walk->getImage(imageSequence % 6));
    } else if (walkingLeft) {
        p->drawImage(xPos, yPos + jumpYPos, walk->getImageMirrored(imageSequence % 6));
    } else if (punching && punchCount < 40) {
        punchCount++;
        if (lookingRight) {
            p->drawImage(xPos, yPos + jumpYPos, imgPunch->getImage(imageSequence % 4));
        } else {
            p->drawImage(xPos, yPos + jumpYPos, imgPunch->getImageMirrored(imageSequence % 4));
        }
    } else if (crouching) {
        if (lookingRight) {
            p->drawImage(xPos, yPos, crouch->getImage(0));
        } else {
            p->drawImage(xPos, yPos, crouch->getImageMirrored(0));
        }
    } else {
        if (lookingRight) {
            p->drawImage(xPos, yPos + jumpYPos, stand->getImage(imageSequence % 4));
        } else {
            p->drawImage(xPos, yPos + jumpYPos, stand->getImageMirrored(imageSequence % 4));
        }
    }
    if (punchCount >= 40) {
        punching = false;
        punchCount = 0;
    }
}

/**
 * @brief Character::getX
 *
 * Gibt die X Position des Charakteres zurück.
 *
 * @return
 */
int Character::getX() {
    return xPos;
}

/**
 * @brief Character::getY
 *
 * Gitb die Y Position des Charakteres zurück.
 *
 * @return
 */
int Character::getY() {
    return yPos;
}

/**
 * @brief Character::getLife
 *
 * Gibt das momentane Leben des Characteres zurück.
 *
 * @return
 */
int Character::getLife() {
    return life;
}

/**
 * @brief Character::getMana
 *
 * Gibt das momentane Mana des Characteres zurück.
 *
 * @return
 */
int Character::getMana() {
    return mana;
}

void Character::count() {

    imageSequence++;
    if(imageSequence < 0) {
        imageSequence = 0;
    }
}

void Character::moveRight(bool value) {
    walkingRight = value;
    lookingRight = true;
    lookingLeft = false;
}

void Character::moveLeft(bool value) {
    walkingLeft = value;
    lookingLeft = true;
    lookingRight = false;
}

void Character::setCrouch(bool value) {
    crouching = value;
}

/**
 * @brief Character::punch
 *
 * Wenn der User zuschlagen will wird Mana und jegliche andere
 * Zustände geprüft, welcher der Charakter haben könnte.
 * Falls alles korrekt ist darf der Charakter zuschlagen.
 */
void Character::punch() {
    if(!punching && !jumping && !jumpingRight && !jumpingLeft && mana >= 15) {
        punching = true;
        punchCount = 0;
        imageSequence = 0;
        mana = mana - 15;
    }
}

/**
 * @brief Character::jumpUp
 *
 * Wenn der User die Angabe macht den Charakter springen zulassen,
 * wird hier geprüft ob das legitim ist.
 *
 * @param value
 */
void Character::jumpUp(bool value) {
    if(!jumping && !jumpingRight && !jumpingLeft) {
        if (walkingRight) {
            jumpingRight = true;
            jumpingUp = true;
        } else if (walkingLeft) {
            qDebug() << "JumpingLeft TRUE";
            jumpingLeft = true;
            jumpingUp = true;
        } else /* if (standing) */ {
            jumping = true;
            jumpingUp = true;
        }
    }
}

/**
 * @brief Character::calculate
 *
 * Berechnet die Position
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
            xPos += (xPos < 720 ?  6 : 0);
        } else {
            jumpYPos += 4;
            jumpingRight = !(jumpYPos == 0);
            xPos += (xPos < 720 ?  6 : 0);
        }
    } else if(jumpingLeft) {
        if (jumpingUp) {
            jumpYPos -= 4;
            jumpingUp = (jumpYPos > -100);
            xPos -= (xPos > 0 ?  6 : 0);
        } else {
            jumpYPos += 4;
            jumpingLeft = !(jumpYPos == 0);
            xPos -= (xPos > 0 ?  6 : 0);
        }
    } else if(walkingRight) {
        xPos += (xPos < 720 ?  2 : 0);
    } else if (walkingLeft) {
        xPos -= (xPos > 0 ?  2 : 0);
    }
}

void Character::second() {
    if (mana < 150) {
        mana++;
    }
    if (life < 150) {
        life++;
    }
}
