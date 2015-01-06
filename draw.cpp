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
    ki = false;
    winChar = "";
    whichActionKI = 0;

    /* Bools initialization */
    showFps = true;

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
    qsrand((uint)timerUpdate);

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
    e->accept();
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

    i++;

    if (ki) {
        if (actionKI) {
            enemy->moveRight(false);
            enemy->moveLeft(false);
            whichActionKI = qrand() % ((5 + 1) - 0) + 0;

            if(enemy->enemyIsLeftRange(character) | enemy->enemyIsRightRange(character)) {
                whichActionKI = 5;
            }

            switch(whichActionKI) {
            case 0:
                break;
            case 1:
                if (!(enemy->getX() > 600)) {
                    enemy->moveRight(true);
                } else {
                    enemy->moveLeft(true);
                }
                break;
            case 2:
                if (!(enemy->getX() < 200)) {
                    enemy->moveLeft(true);
                } else {
                    enemy->moveRight(true);
                }
                break;
            case 3:
                if (!(enemy->getX() > 600)) {
                    enemy->moveRight(true);
                    enemy->jumpUp();
                } else {
                    enemy->moveLeft(true);
                    enemy->jumpUp();
                }
                break;
            case 4:
                if (!(enemy->getX() < 200)) {
                    enemy->moveLeft(true);
                    enemy->jumpUp();
                } else {
                    enemy->moveRight(true);
                    enemy->jumpUp();
                }
                break;
            case 5:
                if (enemy->enemyIsLeft(character)) {
                    enemy->moveLeft(true);
                    enemy->punch();
                } else if (enemy->enemyIsRight(character)) {
                    enemy->moveRight(true);
                    enemy->punch();
                }
                break;
            }
            actionKI = false;
        }
    }
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
    case Qt::Key_Q:
        character->punch();
        break;
    case Qt::Key_Escape:
        emit setCurrent(0);
        break;
    case Qt::Key_D:
        character->moveRight(true);
        break;
    case Qt::Key_A:
        character->moveLeft(true);
        break;
    case Qt::Key_S:
        character->setCrouch(true);
        break;
    case Qt::Key_W:
        character->jumpUp();
        break;
    case Qt::Key_Shift:
        if (!ki) {
            enemy->punch();
        }
        break;
    case Qt::Key_Left:
        if (!ki) {
            enemy->moveLeft(true);
        }
        break;
    case Qt::Key_Right:
        if (!ki) {
            enemy->moveRight(true);
        }
        break;
    case Qt::Key_Up:
        if (!ki) {
            enemy->jumpUp();
        }
        break;
    case Qt::Key_Down:
        if (!ki) {
            enemy->setCrouch(true);
        }
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
    case Qt::Key_Left:
        if (!ki) {
            enemy->moveLeft(false);
        }
        break;
    case Qt::Key_Right:
        if (!ki) {
            enemy->moveRight(false);
        }
        break;
    case Qt::Key_Down:
        if (!ki) {
            enemy->setCrouch(false);
        }
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
void Draw::load(int selChar, int selBackg, int selChar2) {
    character = new Character(selChar);
    background = new Background(selBackg);
    UIinterface = new UIOverlay();
    win = false;
    winChar = "";
    if(selChar2 == 0) {
        ki = true;
        kiActions = new QTimer(this);
        kiActions->setInterval(1500);
        connect(kiActions, SIGNAL(timeout()), this, SLOT(kiActionTrue()));
        kiActions->start();
        enemy = new Character(1, true);
    } else {
        ki = false;
        enemy = new Character(selChar2, true);
    }
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

/**
 * @brief Draw::winC
 *
 * Szenario Spieler 1.
 *
 */
void Draw::winC() {
    QSound::play(":/fanfare.wav");
    winChar = character->getName();
    winIcon = character->getIcon();
    win = true;
}

/**
 * @brief Draw::winE
 *
 * Szenario Spieler 2 / KI wins.
 *
 */
void Draw::winE() {
    QSound::play(":/fanfare.wav");
    winChar = enemy->getName();
    winIcon = enemy->getIcon();
    win = true;
}

/**
 * @brief Draw::kiActionTrue
 *
 * Setzt die KI Action true sodass die KI beim nächsten Zug wieder eine Aktion machen soll.
 *
 */
void Draw::kiActionTrue() {
    actionKI = true;
}
