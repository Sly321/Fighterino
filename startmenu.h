//! StartMenu Klasse beschäftigt sich damit das Startfenster anzuzeigen.
/*!
 *  Erhält Informationen(Mausclicks) vom User welcher Modus ausgewählt wird.
 */
#ifndef STARTMENU_H
#define STARTMENU_H

#include <QtWidgets>
#include <QtMultimedia/QSound>

namespace Ui {
class StartMenu;
}

class TextTitel;

class StartMenu : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QRect ptitle MEMBER title)

public:
    //! Construktor der Klasse StartMenu.
    /*!
     * \brief StartMenu
     * \param parent Das Parent Widget falls vorhanden.
     */
    explicit StartMenu(QWidget *parent = 0);

    ~StartMenu();

signals:
    //! Signalisiert der Main das ein anderes Widget angezeigt werden soll.
    /*!
     * \brief setCurrent
     * \param a Das Widget welches angezeigt werden soll.
     */
    void setCurrent(int a);

public slots:
    //! Startet die Animation im Start-Menü.
    /*!
     * \brief Anim
     */
    void Anim();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::StartMenu *ui;
    QRect text;
    QPropertyAnimation *animation;
    QRect title;
    QTimer *timerUpdate;
    int countAnimation;
    QWidget *parent;

protected:
    //! Zeichnet Elemente für die Klasse.
    /*!
     * \brief paintEvent
     * \param e Das paintEvent.
     */
    void paintEvent(QPaintEvent *e);

};

#endif // STARTMENU_H
