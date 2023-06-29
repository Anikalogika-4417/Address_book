#include "address_book.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Address_book w;
    w.show();
    return a.exec();
}
