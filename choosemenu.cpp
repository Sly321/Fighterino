#include "choosemenu.h"

#include <QtWidgets>


ChooseMenu::ChooseMenu(QWidget *parent) : QWidget(parent)
{
    parentWindow = parent;
    auswahl = 0;
    pushButtonBack = new QPushButton("Back", this);
    rectChoose = new QPushButton(this);

    icon1.load(":/characters/icons/asuma.bmp");
    icon1 = icon1.scaled(100,100, Qt::KeepAspectRatio);
    icon2.load(":/characters/icons/ryu.bmp");
    icon2 = icon2.scaled(100,100, Qt::KeepAspectRatio);
    icon3.load(":/characters/icons/ahri.bmp");
    icon3 = icon3.scaled(100,100, Qt::KeepAspectRatio);
    icon4.load(":/characters/icons/chenpo.bmp");
    icon4 = icon4.scaled(100,100, Qt::KeepAspectRatio);

    rectChoose->setStyleSheet("QPushButton { background-color: rgba(255,255,255, 20%); border-width: 5px; border-color: darkCyan; border-style: groove;}");

    machine = new QStateMachine;

    /* States */
    topleft = new QState(machine);
    topleft->assignProperty(rectChoose, "geometry", QRect(290, 145, 100, 100));

    top = new QState(machine);
    top->assignProperty(rectChoose, "geometry", QRect(400, 145, 100, 100));

    midleft = new QState(machine);
    midleft->assignProperty(rectChoose, "geometry", QRect(290, 255, 100, 100));

    mid = new QState(machine);
    mid->assignProperty(rectChoose, "geometry", QRect(400, 255, 100, 100));

    /* Set First State */
    machine->setInitialState(topleft);

    /* Animation for the States */
    animation = new QPropertyAnimation(rectChoose, "geometry");
    animation->setDuration(300);    // ANIMATIONS DURATION
    animation->setEasingCurve(QEasingCurve::OutExpo); // ANIMATIONS ... ANIMATION

    /* Topleft Right */
    tlr = topleft->addTransition(this, SIGNAL(right()), top);
    tlr->addAnimation(animation);

    /* Topleft Down */
    tld = topleft->addTransition(this, SIGNAL(down()), midleft);
    tld->addAnimation(animation);

    /* Top Left */
    tl = top->addTransition(this, SIGNAL(left()), topleft);
    tl->addAnimation(animation);

    /* Top Down */
    td = top->addTransition(this, SIGNAL(down()), mid);
    td->addAnimation(animation);

    /* Midleft Up */
    mlu = midleft->addTransition(this, SIGNAL(up()), topleft);
    mlu->addAnimation(animation);

    /* Midleft Right */
    mlr = midleft->addTransition(this, SIGNAL(right()), mid);
    mlr->addAnimation(animation);

    /* Mid Left */
    ml = mid->addTransition(this, SIGNAL(left()), midleft);
    ml->addAnimation(animation);

    /* Mid Up */
    mu = mid->addTransition(this, SIGNAL(up()), top);
    mu->addAnimation(animation);

    machine->start();

    connect(pushButtonBack, SIGNAL(clicked()), this, SLOT(backToStartmenu()));

    connect(topleft, SIGNAL(entered()), this, SLOT(selectedTopleft()));
    connect(top, SIGNAL(entered()), this, SLOT(selectedTop()));
    connect(midleft, SIGNAL(entered()), this, SLOT(selectedMidleft()));
    connect(mid, SIGNAL(entered()), this, SLOT(selectedMid()));
}

void ChooseMenu::paintEvent(QPaintEvent *e) {
    QSize rectSize(100, 100);
    QPainter painter(this);
    painter.drawImage(290,145, icon1);
    painter.drawImage(400,145, icon2);
    painter.drawImage(290,255, icon3);

    painter.drawImage(400,255, icon4);
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            int posX = 290 + (100 * x) + (10 * x);
            int posY = 145 + (100 * y) + (10 * y);
            QRect rect(QPoint(posX, posY), rectSize);
            painter.drawRect(rect);
        }
    }
    QPen pen(QBrush(Qt::green), 2);
    painter.setPen(pen);
    qDebug() << "Painting now";
    painter.drawText(QRect(245, 460, 310, 100), "Auswahl " + QString::number(auswahl) + "\nName: " + selectedString, QTextOption(Qt::AlignCenter));
    painter.setFont(QFont("Arial", 60, -1, false));
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);
    painter.drawText(QRect(0,0,800,200), "Charakterauswahl", QTextOption(Qt::AlignCenter));
}

void ChooseMenu::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_Left:
        QSound::play(":/click.wav");
        emit left();
        break;
    case Qt::Key_Right:
        QSound::play(":/click.wav");
        emit right();
        break;
    case Qt::Key_Down:
        QSound::play(":/click.wav");
        emit down();
        break;
    case Qt::Key_Up:
        QSound::play(":/click.wav");
        emit up();
        break;
    case Qt::Key_Return:
        forwardChoosebg();
        break;
    case Qt::Key_Escape:
        backToStartmenu();
        break;
    }
}

void ChooseMenu::forwardChoosebg() {
    emit setCharacter(auswahl);
    emit setCurrent(4);
}

void ChooseMenu::backToStartmenu() {
    emit setCurrent(0);
}

void ChooseMenu::selectedTopleft() {
    selectedString = "Asuma";
    auswahl = 1;
    this->update();
}

void ChooseMenu::selectedTop() {
    selectedString = "Ryu";
    auswahl = 2;
    this->update();
}

void ChooseMenu::selectedMidleft() {
    selectedString = "Ahri";
    auswahl = 3;
    this->update();
}

void ChooseMenu::selectedMid() {
    selectedString = "Chenpo";
    auswahl = 4;
    this->update();
}
