#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QPainter>
#include <QtWidgets>

class Background : public QObject
{
    Q_OBJECT

public:
    explicit Background(int _option, QObject *parent = 0);

private:
    QImage bg;
    QImage bg2;

signals:

public slots:
    void drawBackground(QPainter *p);

};

#endif // BACKGROUND_H
