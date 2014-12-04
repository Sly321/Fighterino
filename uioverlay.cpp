#include "uioverlay.h"

UIOverlay::UIOverlay(QObject *parent) : QObject(parent)
{

}

void UIOverlay::drawInterface(QPainter *p, Character *c) {
    QBrush uiBg(Qt::blue, Qt::Dense4Pattern);
    p->setBrush(uiBg);
    p->drawRect(0, 0, 800, 70);

    /* LEFT PICTURE / HEALTH / MANA */
    p->setPen(QPen(Qt::gray));
    p->setBrush(QBrush(Qt::black));
    p->drawRect(QRect(10,10,205,50));      // Background

    p->setPen(QPen(Qt::white));
    p->setBrush(QBrush(Qt::darkMagenta));
    p->drawRect(QRect(15,15,40,40));       // Picture Character

    p->setPen(QPen(Qt::darkRed));
    p->setBrush(QBrush(Qt::darkRed));
    p->drawRect(QRect(60,15,150,15)); // Healthbar All
    p->setBrush(QBrush(Qt::red));
    p->drawRect(QRect(60,15,c->getLife(),15)); // Healthbar Current
    p->setPen(QPen(Qt::white));
    p->drawText(QRect(60,15,150,15), QString::number(c->getLife()) + " / 150", QTextOption(Qt::AlignCenter)); // Healthtext

    p->setPen(QPen(Qt::darkBlue));
    p->setBrush(QBrush(Qt::darkBlue));
    p->drawRect(QRect(60,40,150,15)); // Manabar All
    p->setBrush(QBrush(Qt::blue));
    p->drawRect(QRect(60,40,c->getMana(),15)); // Manabar Current
    p->setPen(QPen(Qt::white));
    p->drawText(QRect(60,40,150,15), QString::number(c->getMana()) + " / 150", QTextOption(Qt::AlignCenter)); // Manatext

    /* RIGHT PICTURE / HEALTH / MANA */
    p->setPen(QPen(Qt::gray));
    p->setBrush(QBrush(Qt::black));
    p->drawRect(QRect(585, 10, 205, 50));      // Background

    p->setPen(QPen(Qt::white));
    p->setBrush(QBrush(Qt::darkMagenta));
    p->drawRect(QRect(745, 15, 40, 40));       // Picture c

    p->setPen(QPen(Qt::darkRed));
    p->setBrush(QBrush(Qt::darkRed));
    p->drawRect(QRect(590, 15, 150, 15)); // Healthbar All
    p->setBrush(QBrush(Qt::red));
    p->drawRect(QRect(590, 15, c->getLife(), 15)); // Healthbar Current
    p->setPen(QPen(Qt::white));
    p->drawText(QRect(590, 15, 150, 15), QString::number(c->getLife()) + " / 150", QTextOption(Qt::AlignCenter)); // Healthtext

    p->setPen(QPen(Qt::darkBlue));
    p->setBrush(QBrush(Qt::darkBlue));
    p->drawRect(QRect(590, 40, 150, 15)); // Manabar All
    p->setBrush(QBrush(Qt::blue));
    p->drawRect(QRect(590, 40, c->getMana(), 15)); // Manabar Current
    p->setPen(QPen(Qt::white));
    p->drawText(QRect(590, 40, 150, 15), QString::number(c->getMana()) + " / 150", QTextOption(Qt::AlignCenter)); // Manatext

}
