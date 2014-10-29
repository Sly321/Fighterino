#ifndef STARTMENU_H
#define STARTMENU_H

#include <QtWidgets>

namespace Ui {
class StartMenu;
}

class TextTitel;

class StartMenu : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QRect ptitle MEMBER title)

public:
    explicit StartMenu(QWidget *parent = 0);

    ~StartMenu();

signals:
    void setCurrent(int a);

public slots:
    void Anim();

private slots:
    void on_pushButton_6_clicked();

private:
    Ui::StartMenu *ui;
    QRect text;
    QPropertyAnimation *animation;
    QRect title;
    QTimer *timerUpdate;
    int countAnimation;

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // STARTMENU_H
