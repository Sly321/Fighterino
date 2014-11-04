#include "draw.h"


Draw::Draw(QWidget *parent) : QWidget(parent)
{
    /* Bools initialization */
    showFps = false;

    bigBang = new Sprite(QImage(":/sprites/bigbang.bmp"));


    character = new Character(1);

    parentWindow = parent;

    animRect.setCoords(10,10,10,10);
    animRect.setSize(QSize(50,50));

    /* Int initialization */
    xpos = 0;
    ypos = 0;
    fpsInt = 0;
    i = 0;
    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    timerUpdate->start(20);

    seconds = new QTimer(this);
    connect(seconds, SIGNAL(timeout()), this, SLOT(fps()));
    seconds->start(1000);

    cleanHills.load(":/images/background/hills_clean.png");
    water.load(":/images/background/water.png");
    forrest.load(":/images/background/forrest_clean.png");
    hills.load(":/images/background/forrest.png");

    /* Animation */
    animation = new QPropertyAnimation(this, "q_animRect");
    animation->setEndValue(QRect(10,300,50,50));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->setDuration(2000);
    animation->setLoopCount(5);

    connect(animation, SIGNAL(currentLoopChanged(int)), animation, SLOT(pause()));

}

void Draw::paintEvent(QPaintEvent *e) {
    //qDebug() << "paintEvent in draw.cpp";

    QRect rect(xpos, ypos, 80, 60);

    QPainter textPainter(this);
    textPainter.setPen(QPen(Qt::darkGreen));
    textPainter.setBrush(QBrush(Qt::darkGreen));

    //textPainter.drawPicture(0,0, cleanHills);

    textPainter.drawRect(QRect(0, 0, 800, 110));

    textPainter.drawImage(0, 0, forrest); //253 × 162
    textPainter.drawImage(253, 0, forrest);
    textPainter.drawImage(506, 0, forrest);
    textPainter.drawImage(759, 0, forrest);
    textPainter.drawImage(0, 272, hills); //190 × 186
    textPainter.drawImage(190, 272, hills);
    textPainter.drawImage(380, 272, hills);
    textPainter.drawImage(570, 272, hills);
    textPainter.drawImage(760, 272, hills);
    textPainter.drawImage(0, 440, water); //129 × 57
    textPainter.drawImage(129, 440, water);
    textPainter.drawImage(258, 440, water);
    textPainter.drawImage(387, 440, water);
    textPainter.drawImage(516, 440, water);
    textPainter.drawImage(645, 440, water);
    textPainter.drawImage(774, 440, water);
    textPainter.drawImage(100, 300, cleanHills);

    //textPainter.drawText(rect, "Block motherfucker D\nAbsatzapproved");

    //painter.draw

    i++;

    QBrush uiBg(Qt::blue, Qt::Dense4Pattern);
    textPainter.setBrush(uiBg);
    textPainter.drawRect(0, 0, 800, 100);
    //textPainter.setBrush(nobrush);

    textPainter.setPen(QPen(Qt::red));
    textPainter.setBrush(QBrush(Qt::yellow));

    if(showFps) { textPainter.drawText(QRect(700,0,80,20), "FPS: " + QString::number(fpsInt)); }

    textPainter.drawImage(character->getX(), character->getY(), character->getChar());
    textPainter.drawRect(animRect);
    textPainter.drawText(animRect, "X", QTextOption(Qt::AlignCenter));


    /* LEFT PICTURE / HEALTH / MANA */
    textPainter.setPen(QPen(Qt::gray));
    textPainter.setBrush(QBrush(Qt::black));
    textPainter.drawRect(QRect(10,10,205,50));      // Background

    textPainter.setPen(QPen(Qt::white));
    textPainter.setBrush(QBrush(Qt::darkMagenta));
    textPainter.drawRect(QRect(15,15,40,40));       // Picture Character

    textPainter.setPen(QPen(Qt::darkRed));
    textPainter.setBrush(QBrush(Qt::darkRed));
    textPainter.drawRect(QRect(60,15,150,15)); // Healthbar All
    textPainter.setBrush(QBrush(Qt::red));
    textPainter.drawRect(QRect(60,15,character->getLife(),15)); // Healthbar Current
    textPainter.setPen(QPen(Qt::white));
    textPainter.drawText(QRect(60,15,150,15), QString::number(character->getLife()) + " / 150", QTextOption(Qt::AlignCenter)); // Healthtext

    textPainter.setPen(QPen(Qt::darkBlue));
    textPainter.setBrush(QBrush(Qt::darkBlue));
    textPainter.drawRect(QRect(60,40,150,15)); // Manabar All
    textPainter.setBrush(QBrush(Qt::blue));
    textPainter.drawRect(QRect(60,40,character->getMana(),15)); // Manabar Current
    textPainter.setPen(QPen(Qt::white));
    textPainter.drawText(QRect(60,40,150,15), QString::number(character->getMana()) + " / 150", QTextOption(Qt::AlignCenter)); // Manatext

    /* RIGHT PICTURE / HEALTH / MANA */
    textPainter.setPen(QPen(Qt::gray));
    textPainter.setBrush(QBrush(Qt::black));
    textPainter.drawRect(QRect(585, 10, 205, 50));      // Background

    textPainter.setPen(QPen(Qt::white));
    textPainter.setBrush(QBrush(Qt::darkMagenta));
    textPainter.drawRect(QRect(745, 15, 40, 40));       // Picture Character

    textPainter.setPen(QPen(Qt::darkRed));
    textPainter.setBrush(QBrush(Qt::darkRed));
    textPainter.drawRect(QRect(590, 15, 150, 15)); // Healthbar All
    textPainter.setBrush(QBrush(Qt::red));
    textPainter.drawRect(QRect(590, 15, character->getLife(), 15)); // Healthbar Current
    textPainter.setPen(QPen(Qt::white));
    textPainter.drawText(QRect(590, 15, 150, 15), QString::number(character->getLife()) + " / 150", QTextOption(Qt::AlignCenter)); // Healthtext

    textPainter.setPen(QPen(Qt::darkBlue));
    textPainter.setBrush(QBrush(Qt::darkBlue));
    textPainter.drawRect(QRect(590, 40, 150, 15)); // Manabar All
    textPainter.setBrush(QBrush(Qt::blue));
    textPainter.drawRect(QRect(590, 40, character->getMana(), 15)); // Manabar Current
    textPainter.setPen(QPen(Qt::white));
    textPainter.drawText(QRect(590, 40, 150, 15), QString::number(character->getMana()) + " / 150", QTextOption(Qt::AlignCenter)); // Manatext

    textPainter.drawImage(300,180, bigBang->getImage(320,320,(i % 12)+1));
}

void Draw::moveRight() {
    xpos++;
    qDebug() << "void Draw::move()";
    this->update();
    //ypos++;
}

void Draw::moveLeft() {
    xpos--;
    qDebug() << "void Draw::move()";
    this->update();
    //ypos++;
}

void Draw::moveDown() {
    ypos++;
    qDebug() << "void Draw::move()";
    this->update();
    //ypos++;
}

void Draw::moveUp() {
    ypos--;
    qDebug() << "void Draw::move()";
    this->update();
    //ypos++;
}

int Draw::fps() {
    fpsInt = i;
    i = 0;
}

void Draw::setFpsVisible(bool b) {
    qDebug() << "Fps visible: ";
    showFps = b;
}

bool Draw::isFpsVisible() {
    return showFps;
}

void Draw::f_animation() {
    animation->start();
}

void Draw::e_animation() {
    animation->resume();
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
        }
}
