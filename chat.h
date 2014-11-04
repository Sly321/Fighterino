#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QtWidgets>

class Chat : public QWidget
{
    Q_OBJECT


public:
    explicit Chat(QWidget *parent = 0);
    void singnal();
    void showOnlyChat();
    void hideOnlyChat();


signals:
    void setCurrent(int a);

private:
    QLineEdit *line;
    QTextEdit *chat;
    void hideChat();
    QWidget *parent;

public slots:

};

#endif // CHAT_H
