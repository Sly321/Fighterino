#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QtWidgets>

class Chat : public QWidget
{
    Q_OBJECT


public:
    explicit Chat(QWidget *parent = 0);

signals:
    void setCurrent(int a);
    void setFocusTo(int a);

private:
    QLineEdit *line;
    QTextEdit *chat;
    void hideChat();
    QWidget *parent;

public slots:
    void signal();
    void showOnlyChat();
    void hideOnlyChat();
};

#endif // CHAT_H
