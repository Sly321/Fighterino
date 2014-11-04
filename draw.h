#ifndef DRAW_H
#define DRAW_H

#include <QtWidgets>
#include "character.h"
#include "sprite.h"

class Draw : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QRect q_animRect MEMBER animRect READ getAnimRect WRITE setAnimRect)
public:
    explicit Draw(QWidget *parent = 0);
    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();
    void setFpsVisible(bool b);
    bool isFpsVisible();
    void setAnimRect(QRect rect) { animRect = rect; }
    QRect getAnimRect() { return animRect; }
    void f_animation();
    void e_animation();

signals:

public slots:
    int fps();

private:
    Character *character;
    QRect animRect;
    bool showFps;
    int xpos;
    int ypos;
    int high;
    int width;
    int fpsInt;
    int i;
    QImage cleanHills;
    QImage water;
    QImage forrest;
    QImage hills;
    QTimer *timerUpdate;
    QTimer *seconds;
    QPropertyAnimation *animation;
    QWidget *parentWindow;
    Sprite *bigBang;

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

};

#endif // DRAW_H
