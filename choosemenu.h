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
    explicit ChooseMenu(QWidget *parent = 0);
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
    void setCurrent(int);
    void setCharacter(int);
    void setCharacter2(int);
    void right();
    void down();
    void up();
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
     * \brief keyPressEvent
     * \param e Die Taste welche losgelassen wurde.
     */
    void keyReleaseEvent(QKeyEvent *e);

};

#endif // CHOOSEMENU_H
