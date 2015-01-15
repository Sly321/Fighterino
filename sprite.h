//! Sprite Klasse für die Bilder.
/*!
 *  Diese Klasse stellt verschiedene Sprites für
 *  die verschiedenen Szenen/Aktionen zur Verfügung.
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <QtWidgets>

class Sprite
{
public:
    //! Erzeugt ein Sprite aus einem Bild.
    /*!
     * \brief Sprite erstellt ein Sprite.
     * \param bild Das Bild für den Sprite.
     */
    Sprite(QImage bild);
    //! Gibt das Bild zurück.
    /*!
     * \brief getImage
     * \return ein Bild.
     */
    QImage getImage();
    //! Gibt das Bild zurück.
    /*!
     * \brief getImage
     * \param sequence Eine Sequenz von Bildern.
     * \return ein Bild.
     */
    QImage getImage(int sequence);
    //! Gibt das Bild zurück.
    /*!
     * \brief getImageMirrored
     * \param sequence Eine Sequenz von Bildern.
     * \return ein gespiegeltes Bild.
     */
    QImage getImageMirrored(int sequence);
    //! Gibt das Bild zurück.
    /*!
     * \brief getImage
     * \param x X-Wert des Bildes.
     * \param y Y-Wert des Bildes.
     * \param sequence Eine Sequenz von Bildern.
     * \param mirrored Bild ist nicht gespiegelt.
     * \return ein Bild.
     */
    QImage getImage(int x, int y, int sequence, bool mirrored = false);

private:
    QImage bild;
    int anzahl;
    int x;
    int y;
};

#endif // SPRITE_H
