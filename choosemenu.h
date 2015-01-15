//! chooseMenu Klasse repräsentiert die Charakterauswahl.
/*!
 * chooseMenu Klasse repräsentiert die Charakterauswahl, sie zeigt die Charaktere an und
 * fängt die Tasten ab die der Benutzer eingibt. Wenn der Benutzer fertig ist werden die
 * Daten weitergegeben und es wird zur Hauptklasse zurückgekehrt.
 */

#ifndef CHOOSEMENU_H
#define CHOOSEMENU_H

#include <QtWidgets>
#include <QtMultimedia/QSound>

class ChooseMenu : public QWidget
{
    Q_OBJECT
public:
    //! Contructor der chooseMenu Klasse.
    /*!
     * \brief ChooseMenu Erstellt die nötigen Image dateien und initialisiert die Einstellungen für das Auswahlmenü.
     * \param parent Das parent Widget falls vorhanden.
     */
    explicit ChooseMenu(QWidget *parent = 0);
    //! Setzt das Menu darauf das es ein Spieler gegen Spieler Spiel wird und 2 Charaktere ausgewählt werden.
    /*!
     * \brief setPlayerVSPlayer
     * \param value der Wert für den Modus.
     */
    void setPlayerVsPlayer(bool value);

private:
    int auswahl;
    int auswahlp2;
    bool pvp;
    bool player2pick;
    QString selectedString;
    QString selectedStringp2;
    QImage icon0;
    QImage icon1;
    QImage icon2;
    QImage icon3;
    QImage icon4;
    QImage icon5;
    QWidget *parentWindow;
    QPushButton *pushButtonBack;
    QPropertyAnimation *animation;
    QStateMachine *machine;
    QState *topleft;
    QState *top;
    QState *midleft;
    QState *mid;
    QSignalTransition *tld; /* Topleft Down  */
    QSignalTransition *tlr; /* Topleft Right */
    QSignalTransition *tl;  /* Top Left      */
    QSignalTransition *td;  /* Top Down      */
    QSignalTransition *mlu; /* Midleft Up    */
    QSignalTransition *mlr; /* Midleft Right */
    QSignalTransition *ml;  /* Mid Left      */
    QSignalTransition *mu;  /* Mid Up        */
    QPushButton *rectChoose;

signals:
    //! Signalisiert der Main das ein anderes Widget angezeigt werden soll.
    /*!
     * \brief setCurrent
     * \param int Das Widget welches angezeigt werden soll.
     */
    void setCurrent(int);
    //! Signalisiert der Main das ein Charakter ausgewählt wurde.
    /*!
     * \brief setCharacter
     * \param Der Character der ausgewählt wurde.
     */
    void setCharacter(int);
    //! Signalisiert der Main das ein 2.Charakter ausgewählt wurde.
    /*!
     * \brief setCharacter2
     * \param Der 2.Character der ausgewählt wurde.
     */
    void setCharacter2(int);
    //! Signalisiert das der Anweder nach rechts gegangen ist.
    /*!
     * \brief right
     */
    void right();
    //! Signalisiert das der Anweder nach unten gegangen ist.
    /*!
     * \brief down
     */
    void down();
    //! Signalisiert das der Anweder nach oben gegangen ist.
    /*!
     * \brief right
     */
    void up();
    //! Signalisiert das der Anweder nach links gegangen ist.
    /*!
     * \brief left
     */
    void left();

private slots:
    void backToStartmenu();
    void forwardChoosebg();
    void forwardPvp();
    void selectedTopleft();
    void selectedTop();
    void selectedMidleft();
    void selectedMid();

protected:
    //! Zeichnet die Charaktere und das Auswahlgitter für den User.
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

#endif // CHOOSEMENU_H
