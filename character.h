//! Character Klasse ist für die Darstellung und Bewegungen der Charaktere zuständig.
/*!
 * Diese Klasse ist vollständig für das Zeichnen und Bewegen des
 * Charakters zuständig. Sie wird von Draw.cpp aufgerufen.
 * Um neue Bilder einzufügen muss nur im Contructer ein Case
 * hinzugefügt werden, z.B. Case 2. Nun kann dann im Auswahlmenu
 * für Charaktere die 2 gewählt werden (Mitte oben) und die Bilder
 * dieses Charakteres werden geladen. Achte darauf alle Bilder, und
 * auch auf die richtige größe eingefügt zu haben. Sonst wird es nicht
 * funktionieren. Shadow kann so geladen werden wie er ist, er wird
 * für alle Charaktere benutzt.
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

#include <QtWidgets>
#include <QtMultimedia/QSound>
#include "sprite.h"

class Character : public QObject
{
    Q_OBJECT

public:
    //! Construktor der Klasse Character.
    /*!
     * \brief Character
     * \param _option Welcher Charakter ausgewählt wurde.
     * \param enemy Ob ein Gegner existiert oder nicht (Computergegner).
     * \param parent Das Parent Widget falls vorhanden.
     */
    explicit Character(int _option = 1, bool enemy = false, QObject *parent = 0);

    //! Zeichnet den Charakter.
    /*!
     * \brief drawChar
     * \param p Der Painter damit gezeichnet werden kann.
     * \param e Der Gegner falls vorhanden.
     */
    void drawChar(QPainter *p, Character *e = NULL);

    //! Gibt den aktuellen X-Wert zurück den der Charakter hat.
    /*!
     * \brief getX
     * \return Die aktuelle X-Position.
     */
    int getX();

    //! Gibt den aktuellen Y-Wert zurück den der Charakter hat.
    /*!
     * \brief getY
     * \return Die aktuelle Y-Position.
     */
    int getY();

    //! Gibt das aktuelle Leben des Charakteres zurück.
    /*!
     * \brief getLife
     * \return Der aktuelle Lebens-Wert des Charakteres.
     */
    int getLife();

    //! Gibt das aktuelle Mana des Charakteres zurück.
    /*!
     * \brief getMana
     * \return Der aktuelle Mana-Wert des Charakteres.
     */
    int getMana();

    //! Gibt das Icon zurück als QImage welches den Charakter darstellt.
    /*!
     * \brief getIcon
     * \return Icon von dem ausgewählten Charakter (Das Gesicht als QImage).
     */
    QImage getIcon();

    //! Gibt den Namen des aktuellen Charakteres zurück.
    /*!
     * \brief getName
     * \return Name des aktuellen Charakteres.
     */
    QString getName();

private:
    bool walkingLeft;
    bool walkingRight;
    bool stunned;
    bool standing;
    bool jumping;
    bool jumpingUp;
    bool jumpingRight;
    bool jumpingLeft;
    bool crouching;
    bool punching;
    bool lookingLeft;
    bool lookingRight;

    int option;
    int xPos;
    int yPos;
    int jumpYPos;
    int imageSequence;
    int punchCount;

    QImage shadow;
    Sprite *stand;
    Sprite *walk;
    Sprite *jump;
    Sprite *crouch;
    Sprite *imgPunch;
    Sprite *imgStun;

    QTimer *timer;
    QTimer *secTimer;

    int life;
    int mana;

    /* Global Stuff */
    QImage characterIcon;
    QString characterName;

signals:
    //! Der Charakter stirbt.
    /*!
     * \brief death Signalisiert den Tod des aktuellen Charakteres.
     */
    void death();

public slots:

    //! Signalisiert das der Charakter nach rechts läuft oder nicht.
    /*!
     * \brief moveRight
     * \param value True - läuft nach rechts.<br>False - läuft nicht nach rechts.
     */
    void moveRight(bool value);

    //! Signalisiert das der Charakter nach links läuft oder nicht.
    /*!
     * \brief moveLeft
     * \param value True - läuft nach links.<br>False - läuft nicht nach links.
     */
    void moveLeft(bool value);

    //! Signalisiert das der Charakter springt.
    /*!
     * \brief jumpUp
     */
    void jumpUp();

    //! Signalisiert das der Charakter sich duckt oder sich nicht duckt.
    /*!
     * \brief setCrouch
     * \param value True - der Charaktere duckt sich.<br>False - der Charaktere duckt sich nicht.
     */
    void setCrouch(bool value);

    //! Signalisiert das der Charakter zuschlägt.
    /*!
     * \brief punch
     */
    void punch();

    //! Verringert das Leben des Charakteres.
    /*!
     * \brief reduceLife
     * \param redu Die Menge um wieviel es reduziert wird.
     */
    void reduceLife(int redu);

    //! Setzt das Leben eines Charakteres.
    /*!
     * \brief setLife
     * \param value Die Menge des Lebens das gesetzt werden soll.
     */
    void setLife(int value);

    //! Setzt den Charakter auf stunned oder nicht.
    /*!
     * \brief setStunned
     * \param value True - Charakter ist stunned.<br>False - Charakter ist nicht stunned.
     */
    void setStunned(bool value);

    //! Gibt an ob ein Gegner sich links von einem befindet.
    /*!
     * \brief enemyIsLeft
     * \param enemy Variable der Klasse Character, dies ist der Gegner.
     * \return True - Wenn der Gegner sich links befindet.<br>False - Wenn nicht.
     */
    bool enemyIsLeft(Character *enemy);

    //! Gibt an ob ein Gegner sich rechts von einem befindet.
    /*!
     * \brief enemyIsRight
     * \param enemy Variable der Klasse Character, dies ist der Gegner.
     * \return True - Wenn der Gegner sich rechts befindet.<br>False - Wenn nicht.
     */
    bool enemyIsRight(Character *enemy);

    //! Gibt an ob ein Gegner sich links und in schlagweite von einem befindet.
    /*!
     * \brief enemyIsLeftRange
     * \param enemy Variable der Klasse Character, dies ist der Gegner.
     * \return True - Wenn der Gegner sich links befindet und in schlagweite ist.<br>False - Wenn nicht.
     */
    bool enemyIsLeftRange(Character *enemy);

    //! Gibt an ob ein Gegner sich rechts und in schlagweite von einem befindet.
    /*!
     * \brief enemyIsRightRange
     * \param enemy Variable der Klasse Character, dies ist der Gegner.
     * \return True - Wenn der Gegner sich rechts befindet und in schlagweite ist.<br>False - Wenn nicht.
     */
    bool enemyIsRightRange(Character *enemy);

private slots:
    void count();
    void calculate();
    void second();

};

#endif // CHARACTER_H
