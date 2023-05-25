#include <QApplication>
#include <string>
#include <iostream>
#include "menu.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Menu * chick_start = new Menu();
    chick_start->show();
    return QApplication::exec();
}
