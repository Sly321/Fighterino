//! Fighterino Klasse für die Menüs.
/*!
 *  Diese Klasse liefert die Widgets für die Menüs und
 *  Auswahlmöglichkeiten.
 */

#ifndef FIGHTERINO_H
#define FIGHTERINO_H

#include "draw.h"
#include "startmenu.h"
#include "choosemenu.h"
#include "chat.h"
#include "definitions.h"
#include "choosebackground.h"

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
    //! der Fighterino Constructor.
    /*!
     * \brief Contructor der Klasse Fighterino.
     * \param parent Übergibt falls vorhanden das parent-QWidget.
     */
    explicit Fighterino(QWidget *parent = 0);

private:
    QStackedWidget *windows;
    Draw *drawWidget;
    QLineEdit *line;
    QTextEdit *text;
    StartMenu *startmenu;
    Chat *chat;
    ChooseMenu *chooseMenu;
    ChooseBackground *chooseBg;
    int gameChar;
    int character2;
    int gameBg;

private slots:
    void setChooseMenu(int a);
    void setBackground(int a);
    void setCharacter(int a);
    void setCharacter2(int a);
    void setFocusTo(int a);

protected:
    //! Registriert die Tastenschläge des Benutzers.
    /*!
     * \brief keyPressEvent
     * \param e Die Taste welche gedrückt wird.
     */
    void keyPressEvent(QKeyEvent *e);
    //! Erhält Widgets Größenveränderung-Ereignisse, die in dem Event-Parameter übergeben werden.
    /*!
     * \brief resizeEvent
     * \param event Das ResizeEvent.
     */
    void resizeEvent(QResizeEvent *event);

};

#endif // FIGHTERINO_H
