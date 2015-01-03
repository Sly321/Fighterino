#ifndef CHOOSEMENU_H
#define CHOOSEMENU_H

#include <QtWidgets>
#include <QtMultimedia/QSound>

class ChooseMenu : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseMenu(QWidget *parent = 0);

private:
    int auswahl;
    QString selectedString;
    QImage icon0;
    QImage icon1;
    QImage icon2;
    QImage icon3;
    QImage icon4;
    QImage icon5;


    QWidget *parentWindow;
    QPushButton *pushButtonBack;

    /* Animation */
    QPropertyAnimation *animation;

    /* State Machine */
    QStateMachine *machine;

    /* States / Positions */
    QState *topleft;
    QState *top;
    QState *midleft;
    QState *mid;

    /* Transitions */
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
    void right();
    void down();
    void up();
    void left();

public slots:

private slots:
    void backToStartmenu();
    void forwardChoosebg();
    void selectedTopleft();
    void selectedTop();
    void selectedMidleft();
    void selectedMid();

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

};

#endif // CHOOSEMENU_H
