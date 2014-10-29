#include "fighterino.h"

Fighterino::Fighterino(QWidget *parent)
{
    QGraphicsScene scene;
    scene.addRect(QRectF(0, 0, 100, 200), QPen(Qt::black), QBrush(Qt::green));

    this->setWindowTitle("QKeyCollide");
    this->setMinimumSize(QSize(800, 600));
    //this->setStyleSheet("QWidget { opacity: 10; }");

    windows = new QStackedWidget(this);
    startmenu = new StartMenu();

    QWidget *test2 = new QWidget();

    QLabel *label2 = new QLabel("Test2\nIn the terminal, you can also see all keys i registered.");
    QVBoxLayout *test2Layout = new QVBoxLayout;
    test2Layout->addWidget(label2);
    test2->setLayout(test2Layout);

    drawWidget = new Draw(this);
    chooseMenu = new ChooseMenu(this);

    windows->addWidget(startmenu);
    windows->addWidget(test2);
    windows->addWidget(drawWidget);
    windows->addWidget(chooseMenu);

    windows->setGeometry(QRect(0,0,800,600));

    QVBoxLayout *wdg1 = new QVBoxLayout;
    wdg1->addWidget(windows);
    QVBoxLayout *mainLayout = new QVBoxLayout(windows);

    chat = new Chat(this);

    mainLayout->addSpacing(400);
    mainLayout->addWidget(chat);
    this->setLayout(mainLayout);
    this->setFixedSize(800,600);

    connect(chat, SIGNAL(setCurrent(int)), windows, SLOT(setCurrentIndex(int)));
    connect(startmenu, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
    connect(chooseMenu, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
}

void Fighterino::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {

        /* Numeric Keys */
    case Qt::Key_0:
        qDebug() << "keyPressEvent: 0";
        break;
    case Qt::Key_1:
        qDebug() << "keyPressEvent: 1";
        windows->setCurrentIndex(0);
        break;
    case Qt::Key_2:
        qDebug() << "keyPressEvent: 2";
        windows->setCurrentIndex(1);
        break;
    case Qt::Key_3:
        qDebug() << "keyPressEvent: 3";
        windows->setCurrentIndex(2);
        //drawWidget->setFocus();
        qDebug() << "Focus switched to Window 3";
        break;
    case Qt::Key_4:
        qDebug() << "keyPressEvent: 4";
        break;
    case Qt::Key_5:
        qDebug() << "keyPressEvent: 5";
        break;
    case Qt::Key_6:
        qDebug() << "keyPressEvent: 6";
        break;
    case Qt::Key_7:
        qDebug() << "keyPressEvent: 7";
        break;
    case Qt::Key_8:
        qDebug() << "keyPressEvent: 8";
        break;
    case Qt::Key_9:
        qDebug() << "keyPressEvent: 9";
        break;

        /* Arrow Keys */
    case Qt::Key_Left:
        qDebug() << "keyPressEvent: left";
        drawWidget->moveLeft();
        break;
    case Qt::Key_Right:
        qDebug() << "keyPressEvent: right";
        drawWidget->moveRight();
        break;
    case Qt::Key_Down:
        qDebug() << "keyPressEvent: down";
        drawWidget->moveDown();
        break;
    case Qt::Key_Up:
        qDebug() << "keyPressEvent: up";
        drawWidget->moveUp();
        break;

        /* Alphabetic Keys */
    case Qt::Key_A:
        qDebug() << "keyPressEvent: A";
        break;
    case Qt::Key_B:
        qDebug() << "keyPressEvent: B";
        break;
    case Qt::Key_C:
        qDebug() << "keyPressEvent: C";
        drawWidget->e_animation();
        break;
    case Qt::Key_D:
        qDebug() << "keyPressEvent: D";
        break;
    case Qt::Key_E:
        qDebug() << "keyPressEvent: E";
        break;
    case Qt::Key_F:
        qDebug() << "keyPressEvent: F";
        startmenu->Anim();
        break;
    case Qt::Key_G:
        qDebug() << "keyPressEvent: G";
        break;
    case Qt::Key_H:
        qDebug() << "keyPressEvent: H";
        break;
    case Qt::Key_I:
        qDebug() << "keyPressEvent: I";
        break;
    case Qt::Key_J:
        qDebug() << "keyPressEvent: J";
        break;
    case Qt::Key_K:
        qDebug() << "keyPressEvent: K";
        break;
    case Qt::Key_L:
        qDebug() << "keyPressEvent: L";
        break;
    case Qt::Key_M:
        qDebug() << "keyPressEvent: M";
        break;
    case Qt::Key_N:
        qDebug() << "keyPressEvent: N";
        break;
    case Qt::Key_O:
        qDebug() << "keyPressEvent: O";
        break;
    case Qt::Key_P:
        qDebug() << "keyPressEvent: P";
        break;
    case Qt::Key_Q:
        qDebug() << "keyPressEvent: Q";
        break;
    case Qt::Key_R:
        qDebug() << "keyPressEvent: R";
        break;
    case Qt::Key_S:
        qDebug() << "keyPressEvent: S";
        break;
    case Qt::Key_T:
        qDebug() << "keyPressEvent: T";
        break;
    case Qt::Key_U:
        qDebug() << "keyPressEvent: U";
        break;
    case Qt::Key_V:
        qDebug() << "keyPressEvent: V";
        break;
    case Qt::Key_W:
        qDebug() << "keyPressEvent: W";
        break;
    case Qt::Key_X:
        qDebug() << "keyPressEvent: X";
        drawWidget->f_animation();
        break;
    case Qt::Key_Y:
        qDebug() << "keyPressEvent: Y";
        chat->showOnlyChat();
        break;
    case Qt::Key_Z:
        qDebug() << "keyPressEvent: Z";
        break;

        /* General Keys */
    case Qt::Key_Space:
        qDebug() << "keyPressEvent: space";
        break;
    case Qt::Key_Escape:
        qDebug() << "keyPressEvent: esc";
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Closing", "Do you really want to close?",  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            qApp->quit();
        }
        break;
    case Qt::Key_Return:
        qDebug() << "keyPressEvent: enter";
        chat->singnal();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

void Fighterino::paintEvent(QPaintEvent *e) {
    //qDebug() << "paintEvent in qkeycollide.cpp";
}

void Fighterino::keyReleaseEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_Y:
        qDebug() << "keyReleaseEvent: Y";
            chat->hideOnlyChat();
        break;
    }
}

void Fighterino::setChooseMenu(int selected) {
    qDebug() << "SLOT setChooseMenu() in QKeyCollide";
    switch (selected) {
    case START_MENU:
        windows->setCurrentIndex(START_MENU);
        this->setFocus();
        break;
    case CHAMP_SELECT:
        windows->setCurrentIndex(CHAMP_SELECT);
        chooseMenu->setFocus();
        break;
    }
}
