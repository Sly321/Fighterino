#include "drawobject.h"

DrawObject::DrawObject(QString source, int _frameX, int _frameY, QObject *parent) : QObject(parent)
{
    obj = new Sprite(QImage(source));
    xPos = 0;
    yPos = 0;
    frameX = _frameX;
    frameY = _frameY;
    frameCurrent = 0;

    timer = new QTimer();
    timer->setInterval(110);
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));
    timer->start();

}

QImage DrawObject::getObject() {
    return obj->getImage(frameX, frameY, (frameCurrent % 12) + 1);
}

void DrawObject::count() {
    frameCurrent++;
}
