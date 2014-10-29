#ifndef FIGHTERINO_H
#define FIGHTERINO_H

#include "draw.h"
#include "startmenu.h"
#include "choosemenu.h"
#include "chat.h"
#include "definitions.h"

#include <QStackedWidget>
#include <QtWidgets>
#include <qDebug>
#include <QMessageBox>
#include <QPalette>
#include <QLayout>

class Fighterino : public QWidget
{
    Q_OBJECT

public:
    explicit Fighterino(QWidget *parent = 0);

private:
    QStackedWidget *windows;
    Draw *drawWidget;
    QLineEdit *line;
    QTextEdit *text;
    StartMenu *startmenu;
    Chat *chat;
    ChooseMenu *chooseMenu;


private slots:
    void setChooseMenu(int a);

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);

};

#endif // FIGHTERINO_H
