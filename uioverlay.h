#ifndef UIOVERLAY_H
#define UIOVERLAY_H

#include <QObject>
#include "character.h"

class UIOverlay : public QObject
{
    Q_OBJECT
public:
    explicit UIOverlay(QObject *parent = 0);

signals:

public slots:
    void drawInterface(QPainter *p, Character *c, Character *e);

};

#endif // UIOVERLAY_H
