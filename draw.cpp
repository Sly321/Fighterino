#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    parentWindow = parent;

    /* Bools initialization */
    showFps = true;

    /* Objects to draw */
    character = new Character(1);
    background = new Background();
    interface = new Interface();

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

    /* Animation */ /*
    animRect.setCoords(10,10,10,10);
    animRect.setSize(QSize(50,50));

    animation = new QPropertyAnimation(this, "q_animRect");
    animation->setEndValue(QRect(10,300,50,50));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->setDuration(2000);
    animation->setLoopCount(5);

    connect(animation, SIGNAL(currentLoopChanged(int)), animation, SLOT(pause())); /* */
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

    /* AnimRect */
    //textPainter.drawRect(animRect);
    //textPainter.drawText(animRect, "X", QTextOption(Qt::AlignCenter));

    //textPainter.drawImage(300,180, bigBang->getObject());
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
        qDebug() << "keyPressEvent: 0 in Draw";
        break;
    case Qt::Key_1:
        qDebug() << "keyPressEvent: 1 in Draw";
        parentWindow->setFocus();
        qDebug() << "Focus switched to ParentWidget";
        break;
    case Qt::Key_Right:
        qDebug() << "keyPressEvent: Right in Draw";
        character->moveRight(true);
        break;
    case Qt::Key_Left:
        qDebug() << "keyPressEvent: Left in Draw";
        character->moveLeft(true);
        break;
    }
}

void Draw::keyReleaseEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_Right:
        qDebug() << "keyReleaseEvent: Right in Draw";
        character->moveRight(false);
        break;
    case Qt::Key_Left:
        qDebug() << "keyReleaseEvent: Left in Draw";
        character->moveLeft(false);
        break;
    }
}

// Testings

void Draw::f_animation() {
    animation->start();
}

void Draw::e_animation() {
    animation->resume();
}
