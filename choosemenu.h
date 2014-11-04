#ifndef CHOOSEMENU_H
#define CHOOSEMENU_H

#include <QtWidgets>

class ChooseMenu : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseMenu(QWidget *parent = 0);

private:
    QString selectedString;
    QImage icon1;
    QImage icon2;
    QImage icon3;
    QImage icon4;
    QImage faceTemplate;

    QWidget *parentWindow;
    QPushButton *pushButtonBack;

    /* Animation */
    QPropertyAnimation *animation;

    /* State Machine */
    QStateMachine *machine;

    /* States / Positions */
    QState *topleft;
    QState *top;
    QState *topright;
    QState *midleft;
    QState *mid;
    QState *midright;
    QState *botleft;
    QState *bot;
    QState *botright;

    /* Transitions */
    QSignalTransition *tld; /* Topleft Down  */
    QSignalTransition *tlr; /* Topleft Right */
    QSignalTransition *tl;  /* Top Left      */
    QSignalTransition *tri; /* Top Right     */
    QSignalTransition *td;  /* Top Down      */
    QSignalTransition *trl; /* Topright Left */
    QSignalTransition *trd; /* Topright Down */
    QSignalTransition *mlu; /* Midleft Up    */
    QSignalTransition *mlr; /* Midleft Right */
    QSignalTransition *mld; /* Midleft Down  */
    QSignalTransition *ml;  /* Mid Left      */
    QSignalTransition *mu;  /* Mid Up        */
    QSignalTransition *mr;  /* Mid Right     */
    QSignalTransition *md;  /* Mid Down      */
    QSignalTransition *mru; /* Midright Up   */
    QSignalTransition *mrl; /* Midright left */
    QSignalTransition *mrd; /* Midright down */
    QSignalTransition *blu; /* Botleft Up    */
    QSignalTransition *blr; /* Botleft Right */
    QSignalTransition *bl;  /* Bot Left      */
    QSignalTransition *bu;  /* Bot Up        */
    QSignalTransition *br;  /* Bot Right     */
    QSignalTransition *brl; /* Botright left */
    QSignalTransition *bru; /* Botright up   */

    QPushButton *rectChoose;

signals:
    void setCurrent(int);
    void right();
    void down();
    void up();
    void left();

public slots:

private slots:
    void backToStartmenu();
    void selectedTopleft();
    void selectedTop();
    void selectedTopright();
    void selectedMidleft();
    void selectedMid();
    void selectedMidright();
    void selectedBotleft();
    void selectedBot();
    void selectedBotright();

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

};

#endif // CHOOSEMENU_H
