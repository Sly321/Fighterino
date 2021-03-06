#include "character.h"

Character::Character(int _option, bool enemy, QObject *parent) : QObject(parent)
{
    stunned = false;
    walkingLeft = false;
    walkingRight = false;
    standing = false;
    jumping = false;
    jumpingUp = false;
    jumpingRight = false;
    jumpingLeft = false;
    crouching = false;
    punching = false;
    lookingLeft = enemy;
    lookingRight = !enemy;
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

    xPos = (enemy ? 650 : 50);
    yPos = 300;
    jumpYPos = 0;

    switch(option) {
    case 1:
        characterName = "Asuma";
        characterIcon = QImage(":/characters/icons/asuma.bmp");
        stand = new Sprite(QImage(":/character/asuma/stand_asuma.png"));
        walk = new Sprite(QImage(":/character/asuma/walk_asuma.png"));
        jump = new Sprite(QImage(":/character/asuma/jump_asuma.png"));
        crouch = new Sprite(QImage(":/character/asuma/crouch_asuma.png"));
        imgPunch = new Sprite(QImage(":/character/asuma/punching_asuma.png"));
        imgStun =  new Sprite(QImage(":/character/asuma/stunn_asuma.png"));
        shadow.load(":/character/misc/shadow.png"); // Brauch nicht verändert werden
        break;
    case 2:
        characterName = "Ryu";
        characterIcon = QImage(":/characters/icons/ryu.bmp");
        stand = new Sprite(QImage(":/character/ryu/stand_ryu.png"));
        walk = new Sprite(QImage(":/character/ryu/walk_ryu.png"));
        jump = new Sprite(QImage(":/character/ryu/jump_ryu.png"));
        crouch = new Sprite(QImage(":/character/ryu/crouch_ryu.png"));
        imgPunch = new Sprite(QImage(":/character/ryu/punching_ryu.png"));
        imgStun =  new Sprite(QImage(":/character/ryu/stunn_ryu.png"));
        shadow.load(":/character/misc/shadow.png");
        break;
    case 3:
        characterName = "Ahri";
        characterIcon = QImage(":/characters/icons/ahri.bmp");
        stand = new Sprite(QImage(":/character/ahri/stand_ahri.png"));
        walk = new Sprite(QImage(":/character/ahri/walk_ahri.png"));
        jump = new Sprite(QImage(":/character/ahri/jump_ahri.png"));
        crouch = new Sprite(QImage(":/character/ahri/crouch_ahri.png"));
        imgPunch = new Sprite(QImage(":/character/ahri/punching_ahri.png"));
        imgStun =  new Sprite(QImage(":/character/ahri/stunn_ahri.png"));
        shadow.load(":/character/misc/shadow.png");
        break;
    case 4:
        characterName = "Chenpo";
        characterIcon = QImage(":/characters/icons/chenpo.bmp");
        stand = new Sprite(QImage(":/character/chenpo/stand_chenpo.png"));
        walk = new Sprite(QImage(":/character/chenpo/walk_chenpo.png"));
        jump = new Sprite(QImage(":/character/chenpo/jump_chenpo.png"));
        crouch = new Sprite(QImage(":/character/chenpo/crouch_chenpo.png"));
        imgPunch = new Sprite(QImage(":/character/chenpo/punching_chenpo.png"));
        imgStun =  new Sprite(QImage(":/character/chenpo/stunn_chenpo.png"));
        shadow.load(":/character/misc/shadow.png");
        break;
    default:
        break;
    }
}

void Character::drawChar(QPainter *p, Character *e) {
    calculate();

    //1. Stelle, sonst steht der Schatten auf ihm.
    p->drawImage(xPos + 25, yPos + 75, shadow);

    if (stunned && !punching) {
        if (lookingRight) {
            p->drawImage(xPos, yPos + jumpYPos, imgStun->getImage(0));
        } else {
            p->drawImage(xPos, yPos + jumpYPos, imgStun->getImageMirrored(0));
        }
    } else if (jumping) {
        if (lookingRight) {
            p->drawImage(xPos, yPos + jumpYPos, jump->getImage(0));
        } else {
            p->drawImage(xPos, yPos + jumpYPos, jump->getImageMirrored(0));
        }
    } else if (jumpingRight) {
        // Logische Abfrage, wenn er hochspringt dann nimm das 2. Bild, wenn er runterspringt das 3.
        p->drawImage(xPos, yPos + jumpYPos, jump->getImage(jumpingUp ? 1 : 2));
    } else if (jumpingLeft) {
        p->drawImage(xPos, yPos + jumpYPos, jump->getImageMirrored(jumpingUp ? 1 : 2));
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
        e->setStunned(false);
    } else if (punching){
        if(lookingRight && (e->getX() - this->getX()) < 50 && (e->getX() - this->getX()) > 0) {
            e->reduceLife(1);
        } else if(lookingLeft && (this->getX() - e->getX()) < 50 && (this->getX() - e->getX()) > 0) {
            e->reduceLife(1);
        }
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

void Character::setLife(int value) {
    life = value;
}

void Character::reduceLife(int redu) {
    life -= redu;
    stunned = true;
    if(life <= 0) {
        life = 10;
        emit death();
    }
}

void Character::setStunned(bool value) {
    stunned = value;
}

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
    if(!punching) {
        walkingRight = value;
        lookingRight = true;
        lookingLeft = false;
    }
}

void Character::moveLeft(bool value) {
    if(!punching) {
        walkingLeft = value;
        lookingLeft = true;
        lookingRight = false;
    }
}

void Character::setCrouch(bool value) {
    crouching = value;
}

void Character::punch() {
    if(!stunned && !punching && !jumping && !jumpingRight && !jumpingLeft && mana >= 15) {
        punching = true;
        punchCount = 0;
        imageSequence = 0;
        mana = mana - 15;
        QSound::play(":/punch.wav");
        walkingLeft = false;
        walkingRight = false;
    }
}

void Character::jumpUp() {
    if(!jumping && !jumpingRight && !jumpingLeft && !punching) {
        if (walkingRight) {
            jumpingRight = true;
            jumpingUp = true;
            QSound::play(":/woosh.wav");
        } else if (walkingLeft) {
            jumpingLeft = true;
            jumpingUp = true;
            QSound::play(":/woosh.wav");
        } else /* if (standing) */ {
            jumping = true;
            jumpingUp = true;
            QSound::play(":/woosh.wav");
        }
    }
}

void Character::calculate() { //xPos + kriegt eine eigene Funktion damit die abfrage

    /* Falls der Character steht, tue nichts */
    if(stunned) { // dauerfalse inc
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

QImage Character::getIcon() {
    return characterIcon;
}

QString Character::getName() {
    return characterName;
}

bool Character::enemyIsLeft(Character *enemy) {
    if(enemy->getX() < this->getX()) {
        return true;
    } else {
        return false;
    }
}

bool Character::enemyIsRight(Character *enemy) {
    if(enemy->getX() > this->getX()) {
        return true;
    } else {
        return false;
    }
}

bool Character::enemyIsLeftRange(Character *enemy) {
    if (enemyIsLeft(enemy) && (this->getX() - enemy->getX()) < 50 && (this->getX() - enemy->getX()) > 0) {
        return true;
    } else {
        return false;
    }
}

bool Character::enemyIsRightRange(Character *enemy) {
    if(enemyIsRight(enemy) && (enemy->getX() - this->getX()) < 50 && (enemy->getX() - this->getX()) > 0) {
        return true;
    } else {
        return false;
    }
}
