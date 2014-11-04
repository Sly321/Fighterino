#include "sprite.h"

Sprite::Sprite(QImage bild)
{
    this->bild = bild;
    x = bild.width();
    y = bild.height();
    anzahl = x / y;
}

QImage Sprite::getImage() {
    return bild;
}

QImage Sprite::getImage(int sequence) {
    if (sequence <= anzahl) {
        QRect rect(y * (sequence), 0, y, y);
        QImage returnImage = bild.copy(rect);
        return returnImage;
    } else {
        return bild;
    }
}

QImage Sprite::getImage(int x, int y, int sequence) {
    // 320 x 320
    int anzahlSpalten = this->x / x;
    int anzahlZeilen = this->y / y;
    if (sequence <= anzahlSpalten) {

    }
    QRect rect(x * ((sequence-1) % anzahlSpalten), y * ((sequence-1) / anzahlSpalten), x, y);
    return QImage(bild.copy(rect));
}


