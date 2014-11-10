#ifndef DRAW_H
#define DRAW_H

#include <QtWidgets>
#include "character.h"
#include "drawobject.h"
#include "background.h"
#include "interface.h"

class Draw : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QRect q_animRect MEMBER animRect READ getAnimRect WRITE setAnimRect)
public:
    explicit Draw(QWidget *parent = 0);
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
    Background *background;
    Interface *interface;

    QRect animRect;
    bool showFps;
    int high;
    int width;
    int fpsInt;
    int i;
    QTimer *timerUpdate;
    QTimer *seconds;
    QPropertyAnimation *animation;
    QWidget *parentWindow;
    DrawObject *bigBang;

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

};

#endif // DRAW_H
