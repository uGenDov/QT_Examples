#include <QApplication>
#include "demo.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Demo window;
    window.show();
    return QApplication::exec();
}