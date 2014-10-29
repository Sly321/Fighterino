#include "fighterino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fighterino w;
    w.show();

    return a.exec();
}
