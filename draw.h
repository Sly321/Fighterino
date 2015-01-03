#ifndef DRAW_H
#define DRAW_H

#include <QtWidgets>
#include <QSysInfo>
#include <QtMultimedia/QSound>
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
    void kiActionTrue();

private:
    Character *character;
    Character *enemy;
    Background *background;
    UIOverlay *UIinterface;

    QRect animRect;
    bool showFps;
    bool win;
    bool ki;
    bool actionKI;
    int whichActionKI;
    QString winChar;
    QImage winIcon;
    int high;
    int width;
    int fpsInt;
    int i;
    QTimer *timerUpdate;
    QTimer *seconds;
    QTimer *kiActions;
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
