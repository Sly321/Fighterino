#ifndef SPRITE_H
#define SPRITE_H

#include <QtWidgets>

class Sprite
{
public:
    Sprite(QImage bild);
    QImage getImage();
    QImage getImage(int sequence);

private:
    QImage bild;
    int anzahl;
    int x;
    int y;
};

#endif // SPRITE_H
