#include "xfWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(xfWidget);

    QApplication a(argc, argv);
    xfWidget w;
    w.show();

    return a.exec();
}
