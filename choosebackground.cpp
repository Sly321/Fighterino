#include "choosebackground.h"

ChooseBackground::ChooseBackground(QWidget *parent) : QWidget(parent)
{
    auswahl = 1;
    rectChoose = new QPushButton(this);
    rectChoose->setStyleSheet("QPushButton { background-color: rgba(255,255,255, 20%); border-width: 5px; border-color: darkCyan; border-style: groove;}");

    icon1.load(":/images/background/hills_clean.png");
    icon1 = icon1.scaled(100,100, Qt::KeepAspectRatio);

    machine = new QStateMachine;

    sleft = new QState(machine);
    sleft->assignProperty(rectChoose, "geometry", QRect(245, 250, 100, 100));

    mid = new QState(machine);
    mid->assignProperty(rectChoose, "geometry", QRect(350, 250, 100, 100));

    sright = new QState(machine);
    sright->assignProperty(rectChoose, "geometry", QRect(455, 250, 100, 100));

    machine->setInitialState(sleft);

    animation = new QPropertyAnimation(rectChoose, "geometry");
    animation->setDuration(300);    // ANIMATIONS DURATION
    animation->setEasingCurve(QEasingCurve::OutExpo); // ANIMATIONS ... ANIMATION

    /* Left Right */
    lr = sleft->addTransition(this, SIGNAL(right()), mid);
    lr->addAnimation(animation);

    /* Mid Left */
    ml = mid->addTransition(this, SIGNAL(left()), sleft);
    ml->addAnimation(animation);

    /* Mid Right */
    mr = mid->addTransition(this, SIGNAL(right()), sright);
    mr->addAnimation(animation);

    /* Midright Left */
    rl = sright->addTransition(this, SIGNAL(left()), mid);
    rl->addAnimation(animation);

    machine->start();

    connect(sleft, SIGNAL(entered()), this, SLOT(selectedLeft()));
    connect(mid, SIGNAL(entered()), this, SLOT(selectedMid()));
    connect(sright, SIGNAL(entered()), this, SLOT(selectedRight()));

}

void ChooseBackground::paintEvent(QPaintEvent *e) {
    QSize rectSize(100, 100);
    QPainter painter(this);
    painter.drawImage(245, 250, icon1);
    for (int x = 0; x < 3; x++) {
            int posX = 245 + (100 * x) + (5 * x);
            int posY = 145 + (100) + (5);
            QRect rect(QPoint(posX, posY), rectSize);
            painter.drawRect(rect);
    }

    QPen pen(QBrush(Qt::green), 2);
    painter.setPen(pen);
    painter.drawText(QRect(245, 460, 310, 100), "Auswahl " + QString::number(auswahl) + "\nName: " + selectedString, QTextOption(Qt::AlignCenter));

    painter.setFont(QFont("Arial", 60, -1, false));
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);
    painter.drawText(QRect(0,0,800,200), "Umgebungsauswahl", QTextOption(Qt::AlignCenter));
}

void ChooseBackground::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_Left:
        qDebug() << "keyPressEvent: left in chooseBackground";
        emit left();
        break;
    case Qt::Key_Right:
        qDebug() << "keyPressEvent: right in chooseBackground";
        emit right();
        break;
    case Qt::Key_Down:
        qDebug() << "keyPressEvent: down in chooseBackground";
        break;
    case Qt::Key_Up:
        qDebug() << "keyPressEvent: up in chooseBackground";
        break;
    case Qt::Key_Return:
        forwardGame();
        break;
    case Qt::Key_Escape:
        qDebug() << "keyPressEvent: escape in chooseMenu";
        backToStartmenu();
        break;
    }
}

void ChooseBackground::backToStartmenu() {
    emit setCurrent(0);
}

void ChooseBackground::forwardGame() {
    emit setBackground(auswahl);
    emit setCurrent(2);
}

void ChooseBackground::selectedLeft() {
    selectedString = "Forrest";
    auswahl = 1;
    this->update();
}

void ChooseBackground::selectedMid() {
    selectedString = "Mid";
    auswahl = 2;
    this->update();
}

void ChooseBackground::selectedRight() {
    selectedString = "Right";
    auswahl = 3;
    this->update();
}

