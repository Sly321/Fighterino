//! Background Klasse für den Hintergrund.
/*!
 *  Diese Klasse stellt verschiedene Hintergründe für
 *  die verschiedenen Szenen zur Verfügung.
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QPainter>
#include <QtWidgets>

class Background : public QObject
{
    Q_OBJECT

public:
    //! Constructor welcher die Images initialisiert.
    /*!
     * \brief Contructor der Klasse Background.
     * \param _option Gibt an welcher Hintergrund gewählt wird.
     * \param parent Übergibt falls vorhanden das parent-QWidget.
     */
    explicit Background(int _option, QObject *parent = 0);

private:
    //! Eine private Variable.
    /*!
     * \brief option Brief option bla
     * Ist die Option welcher Hintergrund gewählt wird.
     */
    int option;

    //! Eine private Variable.
    /*!
     * \brief bg Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg;

    //! Eine private Variable.
    /*!
     * \brief bg2 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg2;

    //! Eine private Variable.
    /*!
     * \brief bg3 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg3;

    //! Eine private Variable.
    /*!
     * \brief bg4 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg4;

    //! Eine private Variable.
    /*!
     * \brief bg5 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg5;

    //! Eine private Variable.
    /*!
     * \brief bg6 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg6;

    //! Eine private Variable.
    /*!
     * \brief bg7 Eines der Images welche benutzt werden für den Hintergrund.
     */
    QImage bg7;

    //! Mit der Methode wird ein Image eingebunden und dann an der
    /*! als parameter übergebenen Y Position von X=0 bis X=800 füllen
     *  ausgegeben.
     *
     * \brief Background::drawTiles
     * \param img Das ggf. mehrfach zu zeichnende Image
     * \param y Y Position des Images
     * \param p Painter zum zeichnen wird übergeben
     * \param versetzt true wenn die images um 50 pixel versetzt sein soll
     *                 benutzt bei wiederholenden für nicht so eine Eintönigkeit.
     */
    void drawTiles(QImage img, int y, QPainter *p, bool versetzt = false);

signals:

public slots:
    //! Zeichnet des Hintergrund
    /*!
     * \brief drawBackground zeichnet den Hintergrund.
     * \param p Der QPainter wird übergeben damit gezeichnet werden kann.
     */
    void drawBackground(QPainter *p);


};

#endif // BACKGROUND_H
