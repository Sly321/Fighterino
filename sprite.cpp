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

QImage Sprite::getImageMirrored(int sequence) {
    if (sequence <= anzahl) {
        QRect rect(y * (sequence), 0, y, y);
        QImage returnImage = bild.copy(rect);
        return returnImage.mirrored(true, false);
    } else {
        return bild.mirrored(true, false);
    }
}

/**
 * @brief Sprite::getImage
 *
 * Diese Funtion bekommt ein sprite* image und nimmt die jeweilige
 *
 * @param x
 * @param y
 * @param sequence
 * @param mirrored
 * @return
 */
QImage Sprite::getImage(int x, int y, int sequence, bool mirrored) {
    // 320 x 320
    int anzahlSpalten = this->x / x;
    int anzahlZeilen = this->y / y;
    if (sequence <= anzahlSpalten) {

    }
    QRect rect(x * ((sequence-1) % anzahlSpalten), y * ((sequence-1) / anzahlSpalten), x, y);
    return QImage(bild.copy(rect));
}


