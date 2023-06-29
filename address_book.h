#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_address_book.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Address_bookClass; };
QT_END_NAMESPACE

class Address_book : public QMainWindow
{
    Q_OBJECT

public:
    Address_book(QWidget *parent = nullptr);
    ~Address_book();

private:
    Ui::Address_bookClass *ui;
};
