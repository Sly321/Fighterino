//! chooseBackground Klasse symbolisiert ein Auswahlwidget in welchem der Benutzer einen Hintergrund für sein Spiel auswählen kann.
/*!
 */

#ifndef CHOOSEBACKGROUND_H
#define CHOOSEBACKGROUND_H

#include <QtWidgets>

class ChooseBackground : public QWidget
{
    Q_OBJECT
public:
    //! Contructor der chooseBackground Klasse.
    /*!
     * \brief ChooseBackground Erstellt die nötigen Image dateien und initialisiert die Einstellungen für das Auswahlmenü.
     * \param parent Das parent Widget falls vorhanden.
     */
    explicit ChooseBackground(QWidget *parent = 0);

private:
    void backToStartmenu();
    void forwardGame();
    int auswahl;
    QPushButton *rectChoose;
    QPropertyAnimation *animation;
    QStateMachine *machine;
    QString selectedString;
    QState *sright;
    QState *sleft;
    QState *mid;
    QSignalTransition *lr;
    QSignalTransition *mr;
    QSignalTransition *ml;
    QSignalTransition *rl;
    QImage icon1;
    QImage icon2;
    QImage icon3;

signals:
    //! Signalisiert der Main das ein anderes Widget angezeigt werden soll.
    /*!
     * \brief setCurrent
     * \param Das Widget welches angezeigt werden soll.
     */
    void setCurrent(int);

    //! Signalisiert der Main das ein background ausgewählt wurde.
    /*!
     * \brief setBackground
     * \param Der background der ausgewählt wurde.
     */
    void setBackground(int);

    //! Signalisiert das der Anweder nach rechts gegangen ist.
    /*!
     * \brief right
     */
    void right();

    //! Signalisiert das der Anweder nach links gegangen ist.
    /*!
     * \brief left
     */
    void left();

public slots:
    //! Wird angetriggert wenn das linke Icon selektiert wurde.
    void selectedLeft();
    //! Wird angetriggert wenn das mittige Icon selektiert wurde.
    void selectedMid();
    //! Wird angetriggert wenn das rechte Icon selektiert wurde.
    void selectedRight();

protected:
    //! Zeichnet elemente für die Klasse.
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

};

#endif // CHOOSEBACKGROUND_H
