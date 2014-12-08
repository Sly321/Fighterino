#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QPainter>
#include <QtWidgets>

class Background : public QObject
{
    Q_OBJECT

public:
    explicit Background(int _option, QObject *parent = 0);

private:
    int option;
    QImage bg;
    QImage bg2;
    QImage bg3;
    QImage bg4;
    void drawTiles(QImage img, int y, QPainter *p, bool versetzt = false);

signals:

public slots:
    void drawBackground(QPainter *p);


};

#endif // BACKGROUND_H
