#ifndef DRAW_H
#define DRAW_H

#include <QtWidgets>
#include <QSysInfo>
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
    void setCurrent(int);

public slots:
    int fps();
    void winC();
    void winE();

private:
    Character *character;
    Character *enemy;
    Background *background;
    UIOverlay *UIinterface;

    QRect animRect;
    bool showFps;
    bool win;
    QString winChar;
    QImage winIcon;
    int high;
    int width;
    int fpsInt;
    int i;
    QTimer *timerUpdate;
    QTimer *seconds;
    QPropertyAnimation *animation;
    QWidget *parentWindow;
    DrawObject *bigBang;
    QString getOSName();

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

};

#endif // DRAW_H
