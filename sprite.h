#ifndef SPRITE_H
#define SPRITE_H

#include <QtWidgets>

class Sprite
{
public:
    Sprite(QImage bild);
    QImage getImage();
    QImage getImage(int sequence);
    QImage getImageMirrored(int sequence);
    QImage getImage(int x, int y, int sequence, bool mirrored = false);

private:
    QImage bild;
    int anzahl;
    int x;
    int y;
};

#endif // SPRITE_H
