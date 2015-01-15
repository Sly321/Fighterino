//! UIOverlay Klasse ist für die Darstellung des Interfaces zuständig.
/*!
 * Hierbei werden die Mana-, und Lebensbalken beider Spieler angezeigt.
 * Außerdem gehört zu jedem Spieler ein kleines Profilbild.
 */

#ifndef UIOVERLAY_H
#define UIOVERLAY_H

#include <QObject>
#include "character.h"

class UIOverlay : public QObject
{
    Q_OBJECT
public:
    //! Contructor der Klasse UIOverlay.
    /*!
     * \brief UIOverlay Erstellt einige Interface-Daten.
     * \param parent Das parent Widget falls vorhanden.
     */
    explicit UIOverlay(QObject *parent = 0);

signals:

public slots:
    //! Zeichnet das Interface.
    /*!
     * \brief drawInterface
     * \param p Der Painter damit gezeichnet werden kann.
     * \param c Informationen vom ersten Spieler.
     * \param e Informationen vom zweiten Spieler.
     */
    void drawInterface(QPainter *p, Character *c, Character *e);

};

#endif // UIOVERLAY_H
