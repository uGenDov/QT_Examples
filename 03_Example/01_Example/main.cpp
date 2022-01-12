#include <QStyleFactory>
#include "demo.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Demo window;
    window.show();
    QApplication::setStyle(QStyleFactory::create("Windows"));
    return QApplication::exec();
}