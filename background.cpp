#include "background.h"

Background::Background(int _option, QObject *parent) : QObject(parent)
{
    switch(_option) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }


    /* 800 x 530 */

    //cleanHills.load(":/images/background/hills_clean.png");
    //water.load(":/images/background/water.png");
    //forrest.load(":/images/background/forrest_clean.png");
    //hills.load(":/images/background/forrest.png");

    /*
    textPainter.drawImage(0, 0, forrest); //253 × 162
    textPainter.drawImage(253, 0, forrest);
    textPainter.drawImage(506, 0, forrest);
    textPainter.drawImage(759, 0, forrest);
    textPainter.drawImage(0, 272, hills); //190 × 186
    textPainter.drawImage(190, 272, hills);
    textPainter.drawImage(380, 272, hills);
    textPainter.drawImage(570, 272, hills);
    textPainter.drawImage(760, 272, hills);
    textPainter.drawImage(0, 440, water); //129 × 57
    textPainter.drawImage(129, 440, water);
    textPainter.drawImage(258, 440, water);
    textPainter.drawImage(387, 440, water);
    textPainter.drawImage(516, 440, water);
    textPainter.drawImage(645, 440, water);
    textPainter.drawImage(774, 440, water);
    textPainter.drawImage(100, 300, cleanHills);
    */
}

void Background::drawBackground(QPainter *p) {
    p->setPen(QPen(Qt::white));
    p->setBrush(QBrush(Qt::red));

    p->drawRect(0,0,800,800);
    p->drawText(QRect(0,0,800,800), "FILLED", QTextOption(Qt::AlignCenter));
   // UI und BG extra Klassen
}
