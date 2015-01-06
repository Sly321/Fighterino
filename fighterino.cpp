#include "fighterino.h"

Fighterino::Fighterino(QWidget *parent)
{
    this->setWindowTitle("Fighterino");
    this->setMinimumSize(QSize(800, 600));

    gameChar = 1;
    gameBg = 1;
    character2 = 0;

    windows = new QStackedWidget(this);
    startmenu = new StartMenu(this);
    drawWidget = new Draw(this);
    chooseMenu = new ChooseMenu(this);
    chooseBg = new ChooseBackground(this);
    QWidget *test2 = new QWidget();

    windows->addWidget(startmenu);
    windows->addWidget(test2);
    windows->addWidget(drawWidget);
    windows->addWidget(chooseMenu);
    windows->addWidget(chooseBg);
    windows->setGeometry(QRect(0,0,800,600));

    QVBoxLayout *wdg1 = new QVBoxLayout;
    wdg1->addWidget(windows);
    QVBoxLayout *mainLayout = new QVBoxLayout(windows);

    chat = new Chat(this);

    mainLayout->addSpacing(400);
    mainLayout->addWidget(chat);
    this->setLayout(mainLayout);
    //this->setFixedSize(800,600);

    connect(drawWidget, SIGNAL(chatSignal()), chat, SLOT(signal()));
    connect(drawWidget, SIGNAL(showOnlyChat()), chat, SLOT(showOnlyChat()));
    connect(drawWidget, SIGNAL(hideOnlyChat()), chat, SLOT(hideOnlyChat()));
    connect(chat, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
    connect(chat, SIGNAL(setFocusTo(int)), this, SLOT(setFocusTo(int)));
    connect(startmenu, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
    connect(chooseMenu, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
    connect(chooseMenu, SIGNAL(setCharacter(int)), this, SLOT(setCharacter(int)));
    connect(chooseMenu, SIGNAL(setCharacter2(int)), this, SLOT(setCharacter2(int)));
    connect(chooseBg, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
    connect(chooseBg, SIGNAL(setBackground(int)), this, SLOT(setBackground(int)));
    connect(drawWidget, SIGNAL(setCurrent(int)), this, SLOT(setChooseMenu(int)));
}

void Fighterino::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_Escape:
        qDebug() << "keyPressEvent: esc";
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Closing", "Do you really want to close?",  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            qApp->quit();
        }
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

void Fighterino::setChooseMenu(int selected) {
    qDebug() << "SLOT setChooseMenu() in Fighterino.cpp Selected : " + QString::number(selected);
    switch (selected) {
    case START_MENU:
        windows->setCurrentIndex(START_MENU);
        this->setFocus();
        break;
    case OPTIONS_MENU:
        windows->setCurrentIndex(OPTIONS_MENU);
        this->setFocus();
        break;
    case STAGE_WINDOW:
        windows->setCurrentIndex(STAGE_WINDOW);
        drawWidget->load(gameChar, gameBg, character2);
        drawWidget->setFocus();
        character2 = 0;
        break;
    case CHAMP_SELECT:
        //chooseMenu = new ChooseMenu(this);
        windows->setCurrentIndex(CHAMP_SELECT);
        chooseMenu->setPlayerVsPlayer(false);
        chooseMenu->setFocus();
        break;
    case BG_SELECT:
        windows->setCurrentIndex(BG_SELECT);
        chooseBg->setFocus();
        break;
    case 5:
        windows->setCurrentIndex(CHAMP_SELECT);
        chooseMenu->setPlayerVsPlayer(true);
        chooseMenu->setFocus();
        character2 = 1;
        break;
    }
}

void Fighterino::setFocusTo(int selected) {
    switch (selected) {
    case START_MENU:
        this->setFocus();
        break;
    case OPTIONS_MENU:
        this->setFocus();
        break;
    case STAGE_WINDOW:
        drawWidget->setFocus();
        break;
    case CHAMP_SELECT:
        chooseMenu->setFocus();
        break;
    case BG_SELECT:
        chooseBg->setFocus();
        break;
    }
}

void Fighterino::setCharacter(int selected) {
    gameChar = selected;
}

void Fighterino::setCharacter2(int selected) {
    qDebug() << "char2 wurde" + QString::number(selected);
    character2 = selected;
}

void Fighterino::setBackground(int selected) {
    gameBg = selected;
}

void Fighterino::resizeEvent(QResizeEvent *event)
{
    //fitInView();
    QWidget::resizeEvent(event);
}
