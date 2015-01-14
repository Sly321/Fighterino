//! Chat Klasse beschäftigt sich damit einen Chat anzuzeigen und ihn auszuwerten.
/*!
 *
 */

#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QtWidgets>

class Chat : public QWidget
{
    Q_OBJECT


public:
    //! Contructor der Klasse Chat.
    /*!
     * \brief Chat Erstellt einige standardvariable für die Klasse.
     * \param parent Das parent Widget falls vorhanden.
     */
    explicit Chat(QWidget *parent = 0);

signals:
    //! Signalisiert der Main das ein anderes Widget angezeigt werden soll.
    /*!
     * \brief setCurrent
     * \param a Das Widget welches angezeigt werden soll.
     */
    void setCurrent(int a);

    //! Signalisiert der Main das ein anderes Widget den Focus bekommen soll.
    /*!
     * \brief setFocusTo
     * \param a Das widget welches den Focus bekommen soll.
     */
    void setFocusTo(int a);

private:
    QLineEdit *line;
    QTextEdit *chat;
    void hideChat();
    QWidget *parent;

public slots:
    //! Signalisiert dem Chat das er versteckt oder angezeigt werden soll.
    /*!
     * \brief signal
     */
    void signal();

    //! Zeigt nur den Chat.
    /*!
     * \brief showOnlyChat
     */
    void showOnlyChat();

    //! Versteckt nur den Chat.
    /*!
     * \brief hideOnlyChat
     */
    void hideOnlyChat();
};

#endif // CHAT_H
