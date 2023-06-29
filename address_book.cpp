#include "address_book.h"

Address_book::Address_book(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Address_bookClass())
    , helper(Helper::instance())
{
    ui->setupUi(this);
    //Before starting - no data on right side
    ui->info_widget->hide();

    //connections with view
    connect(this, &Address_book::showContact, ui->contacts_listView, &ContactView::onContactAdded);

    //connections wuth button clicked
    connect(ui->contacts_add_button, &QPushButton::clicked, this, &Address_book::onAddButtonCliecked);
    connect(ui->info_edit_save_button, &QPushButton::clicked, this, &Address_book::onSaveEditButtonClicked);

    //connections with helper
    connect(this, &Address_book::newContact, helper.data(), &Helper::AddLine);

    connect(helper.data(), &Helper::FileEroor, this, &Address_book::ContactAddedError);
    connect(helper.data(), &Helper::ContactAdded, this, &Address_book::ContactAdded);

}

Address_book::~Address_book()
{
    delete ui;
}

void Address_book::onAddButtonCliecked()
{
    ui->info_widget->show();
    ui->name_edit->clear();
    ui->nickname_edit->clear();
    ui->phone_edit->clear();
    ui->work_edit->clear();
    ui->info_edit_save_button->setText(SAVE_BUTTON);
}

void Address_book::onSaveEditButtonClicked()
{
    if (ui->info_edit_save_button->text() == SAVE_BUTTON)
    {
        if (ui->name_edit->text().isEmpty() || ui->phone_edit->text().isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please, fill filds name and phone");
            return;
        }

        
        //TODO send to saving to the file
        emit newContact(contactItemPtr
            { new ContactItem
                {
                ui->name_edit->text(),
                ui->nickname_edit->text(),
                ui->phone_edit->text(),
                ui->work_edit->text()
                }
            }
        );
    }
    else 
    {

    }

    
}

void Address_book::ContactAddedError(const QString& eroor_)
{
    QMessageBox::warning(this, "Warning", eroor_);
}

void Address_book::ContactAdded(const contactItemPtr new_contact_)
{

    emit showContact(QVariant::fromValue<contactItemPtr>(new_contact_));
}


