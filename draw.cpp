#include "draw.h"



Draw::Draw(QWidget *parent) : QWidget(parent)
{
    parentWindow = parent;

    /* Bools initialization */
    showFps = true;

    /* Objects to draw */
    bigBang = new DrawObject(":/sprites/bigbang.bmp", 320, 320);

    /* Int initialization */
    fpsInt = 0;
    i = 0;

    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    timerUpdate->start(20);

    seconds = new QTimer(this);
    connect(seconds, SIGNAL(timeout()), this, SLOT(fps()));
    seconds->start(1000);
}

void Draw::paintEvent(QPaintEvent *e) {
    QPainter textPainter(this);

    background->drawBackground(&textPainter);
    interface->drawInterface(&textPainter, character);
    character->drawChar(&textPainter);

    i++; // FPS COUNTER

    /* FPS */
    textPainter.setPen(QPen(Qt::red));
    textPainter.setBrush(QBrush(Qt::yellow));
    if(showFps) { textPainter.drawText(QRect(700,0,80,20), "FPS: " + QString::number(fpsInt)); }
}

/**
 * @brief Draw::fps
 * @return The Frames per second.
 */
int Draw::fps() {
    fpsInt = i;
    i = 0;
}

/**
 * @brief Draw::setFpsVisible
 * @param b
 */
void Draw::setFpsVisible(bool b) {
    qDebug() << "Fps visible: ";
    showFps = b;
}

/**
 * @brief Draw::isFpsVisible
 *
 * Returns the value of the showFps of Draw Class.
 *
 * @return True is fps is visible, false if not.
 */
bool Draw::isFpsVisible() {
    return showFps;
}



void Draw::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        /* Numeric Keys */
    case Qt::Key_0:

        break;
    case Qt::Key_1:
        character->punch();
        break;
    case Qt::Key_Escape:
        qDebug() << "keyPressEvent: Escape in Draw";
        parentWindow->setFocus();
        qDebug() << "Focus switched to ParentWidget";
        break;
    case Qt::Key_D:
        qDebug() << "keyPressEvent: D in Draw";
        character->moveRight(true);
        break;
    case Qt::Key_A:
        qDebug() << "keyPressEvent: A in Draw";
        character->moveLeft(true);
        break;
    case Qt::Key_S:
        qDebug() << "keyPressEvent: S in Draw";
        character->setCrouch(true);
        break;
    case Qt::Key_Space:
        qDebug() << "keyPressEvent: Space in Draw";
        character->jumpUp(true);
        break;
    case Qt::Key_Return:
        emit chatSignal();
        break;
    case Qt::Key_Y:
        emit showOnlyChat();
        break;
    }
}

void Draw::keyReleaseEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_D:
        character->moveRight(false);
        break;
    case Qt::Key_A:
        character->moveLeft(false);
        break;
    case Qt::Key_S:
        character->setCrouch(false);
        break;
    case Qt::Key_Return:
        break;
    case Qt::Key_Y:
        emit hideOnlyChat();
        break;
    }
}

void Draw::load(int selChar, int selBackg) {
    character = new Character(1);
    background = new Background(1);
    //character = new Character(selChar);
    //background = new Background(selBackg);
    interface = new UIOverlay();
}
