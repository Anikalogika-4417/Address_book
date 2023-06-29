#include "address_book.h"

Address_book::Address_book(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Address_bookClass())
{
    ui->setupUi(this);
}

Address_book::~Address_book()
{
    delete ui;
}
