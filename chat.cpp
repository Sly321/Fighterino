#include "chat.h"

Chat::Chat(QWidget *parent) : QWidget(parent)
{
    line = new QLineEdit;
    line->setVisible(false);
    line->setStyleSheet("QLineEdit { background-color: rgba(0,0,0, 70%); color: white; }");

    chat = new QTextEdit;
    chat->setStyleSheet("QTextEdit { background-color: rgba(0,0,0, 70%); color: white; }");
    chat->setVisible(false);
    chat->setReadOnly(true);
    chat->setText("Welcome! This is the Chat.cpp, enjoy!");

    QVBoxLayout *chatLayout = new QVBoxLayout;
    chatLayout->addWidget(chat);
    chatLayout->addWidget(line);

    this->setLayout(chatLayout);

    this->parent = parent;
}


void Chat::hideChat() {
    if (line->isVisible()) {
        /* Chat wird kleiner manchmal ?! */

        if (line->text() != "") {
            chat->setText(chat->toPlainText() + "\n" + line->text());
        }
        chat->verticalScrollBar()->setValue(chat->verticalScrollBar()->maximum());

        if(line->text() == "/1") {
            emit setCurrent(0);
        } else if (line->text() == "/2") {
            emit setCurrent(1);
        } else if (line->text() == "/3") {
            emit setCurrent(2);
        } else if (line->text() == "/fps") {
            //parent->drawWidget->setFpsVisible(!drawWidget->isFpsVisible());
        } else if (line->text() == "/quit") {
            parent->close();
        } else if (line->text() == "/help") {
            QMessageBox::information(this, "Help",
            "This Console line supports: \n\n/1 - /3 : for switching window states\n/quit  : for closing the window\n/fps   : for showing the fps in the 3rd window\n/clearchat : for clearing the chat window");
        } else if (line->text() == "/clearchat") {
            chat->clear();
        }

        line->clear();
        qDebug() << "hideChat()";
        line->setVisible(false);
        chat->setVisible(false);
        parent->setFocus();
    }
}

void Chat::singnal() {
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
