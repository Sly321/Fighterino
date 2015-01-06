#include "chat.h"

/**
 * @brief Chat::Chat
 *
 * Diese Klasse beschäftigt sich damit einen Chat anzuzeigen und ihn auszuwerten.
 *
 * @param parent The Parent widget.
 */
Chat::Chat(QWidget *parent) : QWidget(parent)
{
    line = new QLineEdit;
    line->setVisible(false);
    line->setStyleSheet("QLineEdit { background-color: rgba(0,0,0, 70%); color: white; }");
    connect(line, SIGNAL(returnPressed()), this, SLOT(signal()));
    chat = new QTextEdit;
    chat->setStyleSheet("QTextEdit { background-color: rgba(0,0,0, 70%); color: white; }");
    chat->setVisible(false);
    chat->setReadOnly(true);
    chat->setText("Welcome! This is the Chat, enjoy!");
    chat->focusPolicy();
    QVBoxLayout *chatLayout = new QVBoxLayout;
    chatLayout->addWidget(chat);
    chatLayout->addWidget(line);
    this->setLayout(chatLayout);
    this->parent = parent;
}

/**
 * @brief Chat::hideChat
 *
 * Versteckt den Chat und wertet das geschriebene auf mögliche Befehle aus.
 * Falls ein Befehl getätigt wurde wird die entprechende Aktion ausgeführt.
 *
 */
void Chat::hideChat() {
    if (line->isVisible()) {
        if (line->text() != "") {
            chat->setText(chat->toPlainText() + "\n[Player]: " + line->text());
        }
        chat->verticalScrollBar()->setValue(chat->verticalScrollBar()->maximum());
        if (line->text() == "/quit") {
            parent->close();
        } else if (line->text() == "/help") {
            QMessageBox::information(this, "Help",
            "This Console line supports: \n\n/1 - /3 : for switching window states\n/quit  : for closing the window\n/fps   : for showing the fps in the 3rd window\n/clearchat : for clearing the chat window");
        } else if (line->text() == "/clearchat") {
            chat->clear();
        } else if (line->text() == "/controls") {
            chat->setText(chat->toPlainText() + "\n" + "Spieler 1\nBewegen mit A und D\nSpringen mit W\nKriechen mit D\nSchlagen mit Q\n\nSpieler 2\nBewegen mit Pfeil Links und Rechts\nSpringen mit Pfeil Hoch\nKriechen mit Pfeil Runter\nSchlagen mit Shift");
        }
        line->clear();
        qDebug() << "hideChat()";
        line->setVisible(false);
        chat->setVisible(false);
        emit setFocusTo(2);
    }
}

/**
 * @brief Chat::signal
 *
 * Chat bekommt ein Signal und wird darauf reagieren, je nachdem ob der Chat angezeigt
 * ist oder nicht wird er versteckt oder angezeigt,
 *
 */
void Chat::signal() {
    if(line->isVisible()) {
        hideChat();
    } else {
        line->setVisible(true);
        chat->setVisible(true);
        chat->setFixedHeight(100);
        chat->verticalScrollBar()->setValue(chat->verticalScrollBar()->maximum());
        line->setFocus();
    }
}

void Chat::showOnlyChat() {
    if (!chat->isVisible()) {
        chat->setFixedHeight(150);
        chat->verticalScrollBar()->setValue(chat->verticalScrollBar()->maximum());
        chat->setVisible(true);
    }
}

void Chat::hideOnlyChat() {
    chat->setFixedHeight(100);
    if (!line->isVisible()) {
        chat->setVisible(false);
    }
}
