#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <QObject>
#include "sprite.h"

class DrawObject : public QObject
{
    Q_OBJECT

public:
    explicit DrawObject(QString source, int _frameX, int _frameY, QObject *parent = 0);

private:
    Sprite *obj;
    int xPos;
    int yPos;
    int frameX;
    int frameY;
    int frameCurrent;
    int frameTotal;

    QTimer *timer;


signals:

public slots:
    QImage getObject();

private slots:
    void count();


};

#endif // DRAWOBJECT_H
