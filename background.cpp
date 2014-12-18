#include "background.h"

Background::Background(int _option, QObject *parent) : QObject(parent)
{
    option = _option;
    switch(option) {
    case 1:
        bg.load(":/images/background/forrest_clean.png");
        bg2.load(":/images/background/forrest.png");
        bg3.load(":/images/background/water.png");
        bg4.load(":/images/background/hills_clean.png");
        break;
    case 2:
        bg.load(":/images/background_bc/bc2_test.png");
        bg2.load(":/images/background_bc/final.png");
        bg3.load(":/images/background_bc/bc4_test.png");
        bg4.load(":/images/background_bc/bc5_test.png");
        break;
    case 3:
        break;
    }
}

/**Zeichnet den Hintergrund
 *
 * @brief Background::drawBackground
 * @param p Painter zum zeichnen wird übergeben
 */
void Background::drawBackground(QPainter *p) {
    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(Qt::darkGreen));
    p->drawRect(0,0,800,800);

    switch(option) {
    case 1:
        drawTiles(bg, 70, p, true);
        drawTiles(bg, 120, p);
        drawTiles(bg, 170, p, true);
        drawTiles(bg, 210, p);
        drawTiles(bg2, 385, p); //
        drawTiles(bg3, 543, p); // 57y
        break;
    case 2:
        //drawTiles(bg, 70, p, true);
        drawTiles(bg2, 70, p);
        drawTiles(bg3, 302, p); //
        drawTiles(bg4, 337, p);
        drawTiles(bg3, 508, p);
        drawTiles(bg4, 543, p);// 57y
        break;
    case 3:
        break;
    }
}

/**Mit der Methode wird ein Image eingebunden und dann an der
 * als parameter übergebenen Y Position von X=0 bis X=800 füllen
 * ausgegeben.
 *
 * @brief Background::drawTiles
 * @param img Das ggf. mehrfach zu zeichnende Image
 * @param y Y Position des Images
 * @param p Painter zum zeichnen wird übergeben
 * @param versetzt true wenn die images um 50 pixel versetzt sein soll
 *                 benutzt bei wiederholenden für nicht so eine Eintönigkeit.
 */
void Background::drawTiles(QImage img, int y, QPainter *p, bool versetzt) {
    int x = img.width();
    if (!versetzt) {
        int anzahl = 800 / x;
        for (int i = 0; i <= anzahl; i++) {
            p->drawImage(i * x, y, img);
        }
    } else {
        int anzahl = 850 / x;
        for (int i = 0; i <= anzahl; i++) {
            p->drawImage(-50 + (i * x), y, img);
        }
    }
}
