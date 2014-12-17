#include "draw.h"

/**
 * Die Klasse Draw ruft die Klassen Character, Background und UiOverlay auf.
 * Diese sind für das Zeichnen im Spiel verantwortlich. Character und Background werden
 * Zahlen übergeben welche für die jeweilige Auswahl stehen (Background 1, 2, ... etc.).
 * Die UiOverlay Klasse brauch zum Zeichnen immer den Character als object, damit Healthbar etc.
 * korrekte Werte zeichnen.
 */
Draw::Draw(QWidget *parent) : QWidget(parent)
{
    parentWindow = parent;

    win = false;
    winChar = "";

    /* Bools initialization */
    showFps = true;

    /* Objects to draw */
    bigBang = new DrawObject(":/sprites/bigbang.bmp", 320, 320);

    /* Int initialization, Fps wird später die Fps errechnen und i wird der Zähler der Fps pro Sekunde sein. */
    fpsInt = 0;
    i = 0;

    /* Für das zeichnen zuständig, je schneller je öfter */
    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    /* Das sind 60 FPS auf Mac, Besser schreibe statt 20 -> 16 rein für Windows. */
    if (getOSName() == "windows") {
        timerUpdate->start(15);
    } else {
        timerUpdate->start(20);
    }

    /* Das sind die Sekunden, sie werden benutzt um die FPS auszurechnen. */
    seconds = new QTimer(this);
    connect(seconds, SIGNAL(timeout()), this, SLOT(fps()));
    seconds->start(1000);
}

/**
 * @brief Draw::paintEvent
 *
 * Das Zeichen Event, zeichnet den Bildschirm neu, immer bei Update.
 *
 * @param e
 */
void Draw::paintEvent(QPaintEvent *e) {
    QPainter textPainter(this);

    if(!win) {
        background->drawBackground(&textPainter);
        UIinterface->drawInterface(&textPainter, character, enemy);
        character->drawChar(&textPainter, enemy);
        enemy->drawChar(&textPainter, character);
    } else {
        textPainter.setPen(QPen(Qt::red));
        textPainter.setBrush(QBrush(Qt::yellow));
        textPainter.setFont(QFont("Arial", 60, -1, false));
        textPainter.drawImage(QRect(350,100,100,100), winIcon.scaled(100,100));
        textPainter.drawText(QRect(0,0,800,600), "Spieler " + winChar + " gewann!", QTextOption(Qt::AlignCenter));
        textPainter.setFont(QFont("Arial", 12, -1, false));
        textPainter.drawText(QRect(0,500,800,100), "(Escape drücken um ins Startmenu zu kommen.)", QTextOption(Qt::AlignCenter));
    }

    i++; // FPS COUNTER

    /* FPS */
    //textPainter.setPen(QPen(Qt::red));
    //textPainter.setBrush(QBrush(Qt::yellow));
    //if(showFps) { textPainter.drawText(QRect(700,0,80,20), "FPS: " + QString::number(fpsInt)); }
}

/**
 * @brief Draw::fps
 *
 * Errechnet lediglich die fps und setzt den Zähler wieder 0.
 *
 * @return The Frames per second.
 */
int Draw::fps() {
    fpsInt = i;
    i = 0;
    return fpsInt;
}

/**
 * @brief Draw::setFpsVisible
 *
 * Setzt die Fps Zahl sichtbar oder unsichtbar (true für sichtbar).
 *
 * @param b
 */
void Draw::setFpsVisible(bool b) {
    qDebug() << "Fps visible: ";
    showFps = b;
}

/**
 * @brief Draw::isFpsVisible
 *
 * Gibt aus ob die Fps Sichtbar sind.
 *
 * @return
 */
bool Draw::isFpsVisible() {
    return showFps;
}

/**
 * @brief Draw::keyPressEvent
 *
 * Das Event wenn eine Taste gedrückt wurde.
 *
 * @param e
 */
void Draw::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        /* Numeric Keys */
    case Qt::Key_0:

        break;
    case Qt::Key_1:
        character->punch();
        break;
    case Qt::Key_Escape:
        emit setCurrent(0);
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
        character->jumpUp();
        break;
    case Qt::Key_Return:
        emit chatSignal();
        break;
    case Qt::Key_Y:
        emit showOnlyChat();
        break;
    }
}

/**
 * @brief Draw::keyReleaseEvent
 *
 * Das Event wenn eine Taste losgelassen wurde.
 *
 * @param e
 */
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

/**
 * @brief Draw::load
 *
 * Läd den Charakter und den Hintergrund.
 *
 * @param selChar
 * @param selBackg
 */
void Draw::load(int selChar, int selBackg) {
    character = new Character(selChar);
    enemy = new Character(1, true);
    background = new Background(selBackg);
    UIinterface = new UIOverlay();
    win = false;
    winChar = "";
    qDebug() << "NEW DRAW";
    connect(enemy, SIGNAL(death()), this, SLOT(winC()));
    connect(character, SIGNAL(death()), this, SLOT(winE()));
}

/**
 * @brief GetOSName
 *
 * Checked Umgebumgsvariablen aus um das OS zu verifizieren.
 *
 * @return Das momentane OS als QString.
 */
QString Draw::getOSName()
{
    #if defined(Q_OS_ANDROID)
        return QLatin1String("android");
    #elif defined(Q_OS_BLACKBERRY)
        return QLatin1String("blackberry");
    #elif defined(Q_OS_IOS)
        return QLatin1String("ios");
    #elif defined(Q_OS_MAC)
        return QLatin1String("osx");
    #elif defined(Q_OS_WINCE)
        return QLatin1String("wince");
    #elif defined(Q_OS_WIN)
        return QLatin1String("windows");
    #elif defined(Q_OS_LINUX)
        return QLatin1String("linux");
    #elif defined(Q_OS_UNIX)
        return QLatin1String("unix");
    #else
        return QLatin1String("unknown");
    #endif
}

void Draw::winC() {/*
    QMessageBox win;
    win.setText("Character " + enemy->getName() + "hat gewonnen!/nKlick Ok um zum Startmenu zu kommen.");
    win.setStandardButtons(QMessageBox::Ok);
    win.setDefaultButton(QMessageBox::Ok);
    win.exec();*/
    winChar = character->getName();
    winIcon = character->getIcon();
    win = true;
}

void Draw::winE() {/*
    QMessageBox win;
    win.setText("Character " + character->getName() + "hat gewonnen!/nKlick Ok um zum Startmenu zu kommen.");
    win.setStandardButtons(QMessageBox::Ok);
    win.setDefaultButton(QMessageBox::Ok);
    win.exec();*/
    winChar = enemy->getName();
    winIcon = enemy->getIcon();
    win = true;
}
