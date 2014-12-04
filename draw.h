#ifndef DRAW_H
#define DRAW_H

#include <QtWidgets>
#include "character.h"
#include "drawobject.h"
#include "background.h"
#include "uioverlay.h"

class Draw : public QWidget
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = 0);
    void setFpsVisible(bool b);
    bool isFpsVisible();
    void load(int character, int background);

signals:
    void chatSignal();
    void showOnlyChat();
    void hideOnlyChat();

public slots:
    int fps();

private:
    Character *character;
    Background *background;
    UIOverlay *interface;

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
