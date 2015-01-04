#ifndef CHOOSEBACKGROUND_H
#define CHOOSEBACKGROUND_H

#include <QtWidgets>

class ChooseBackground : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseBackground(QWidget *parent = 0);

private:
    void backToStartmenu();
    void forwardGame();
    int auswahl;

    QPushButton *rectChoose;

    /* Animation */
    QPropertyAnimation *animation;

    /* State Machine */
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
    void setCurrent(int);
    void setBackground(int);
    void right();
    void left();

public slots:
    void selectedLeft();
    void selectedMid();
    void selectedRight();

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);

};

#endif // CHOOSEBACKGROUND_H
