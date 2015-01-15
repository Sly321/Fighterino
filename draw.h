//! Die Draw Klasse (ruft die Klassen Character, Background und UiOverlay auf).
/*!
 * Die Klasse Draw ruft die Klassen Character, Background und UiOverlay auf.
 * Diese sind für das Zeichnen im Spiel verantwortlich. Character und Background werden
 * Zahlen übergeben welche für die jeweilige Auswahl stehen (Background 1, 2, ... etc.).
 * Die UiOverlay Klasse brauch zum Zeichnen immer den Character als object, damit Healthbar etc.
 * korrekte Werte zeichnen.
 */

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
    //! Constructor der Klasse Draw.
    /*!
     * \brief Contructor der Klasse Draw.
     * \param parent Übergibt falls vorhanden das parent-QWidget.
     */
    explicit Draw(QWidget *parent = 0);
    //! Setzt die Fps sichtbar.
    /*!
     * \brief setFpsVisible
     * \param b True - Fps ist sichtbar.<br>False - Fps nicht sichtbar.
     */
    void setFpsVisible(bool b);
    //! Gibt an ob die Fps sichtbar sind.
    /*!
     * \brief isFpsVisible
     * \return showFps
     */
    bool isFpsVisible();
    //! Ladet die gewählten Charaktere und den Hintergrund.
    /*!
     * \brief load
     * \param selChar der gewählte Charakter.
     * \param selBackg der gewählte Hintergrund.
     * \param selChar2 der gewählte 2.Charakter.
     */
    void load(int selChar, int selBackg, int selChar2);

signals:
    //! Signalisiert dem Chat das er versteckt oder angezeigt werden soll.
    /*!
     * \brief chatSignal
     */
    void chatSignal();
    //! Zeigt nur den Chat.
    /*!
     * \brief showOnlyChat
     */
    void showOnlyChat();
    //! Versteckt nur den Chat.
    /*!
     * \brief hideOnlyChat
     */
    void hideOnlyChat();
    //! Signalisiert der Main das ein anderes Widget angezeigt werden soll.
    /*!
     * \brief setCurrent
     * \param int Das Widget welches angezeigt werden soll.
     */
    void setCurrent(int);

public slots:
    //! Wird angetriggert wenn die fps angezeigt wird.
    int fps();
    //! Wird angetriggert wenn der erste Spieler gewinnt.
    void winC();
    //! Wird angetriggert wenn der zweite Spieler/KI gewinnt.
    void winE();
    //! Wird angetriggert wenn die KI wieder einen Zug machen soll.
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
    //! Zeichnet Elemente für die Klasse.
    /*!
     * \brief paintEvent
     * \param e Das paintEvent.
     */
    void paintEvent(QPaintEvent *e);
    //! Registriert die Tastenschläge des Benutzers.
    /*!
     * \brief keyPressEvent
     * \param e Die Taste welche gedrückt wird.
     */
    void keyPressEvent(QKeyEvent *e);
    //! Registriert wenn der Benutzer die Taste loslässt.
    /*!
     * \brief keyReleaseEvent
     * \param e Die Taste welche losgelassen wurde.
     */
    void keyReleaseEvent(QKeyEvent *e);

};

#endif // DRAW_H
