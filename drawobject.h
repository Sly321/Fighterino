//! drawObject Klasse um ein Objekt zeichnen zu können.
/*!
 */

#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <QObject>
#include "sprite.h"

class DrawObject : public QObject
{
    Q_OBJECT

public:
    //! Contructor der drawObject Klasse.
    /*!
     * \brief Constructor der Klasse DrawObject.
     * \param source Die Quelle des Frames.
     * \param _frameX X-Wert des Frames.
     * \param _frameY Y-Wert des Frames.
     * \param parent Das parent Widget falls vorhanden.
     */
    explicit DrawObject(QString source, int _frameX, int _frameY, QObject *parent = 0);

private:
    Sprite *obj;
    int xPos;
    int yPos;
    int frameX;
    int frameY;
    int frameCurrent;
    int frameTotal;

    QTimer *timer;


signals:

public slots:
    //! Gibt ein Objekt/Frame zurück.
    /*!
     * \brief getObject
     * \return Das erstellte Bild
     */
    QImage getObject();

private slots:
    void count();


};

#endif // DRAWOBJECT_H
