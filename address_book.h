#pragma once

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QMessageBox>

#include "ui_address_book.h"
#include "ContactItem.h"
#include "ContactView.h"
#include "Helper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Address_bookClass; };
QT_END_NAMESPACE

class Address_book : public QMainWindow
{
    Q_OBJECT

public:
    Address_book(QWidget *parent = nullptr);
    ~Address_book();

private Q_SLOTS:
    void onAddButtonCliecked();
    void onSaveEditButtonClicked();
    //void onDeleteButtonClicked();
    //void onSearchButtonClicked();

    //void onContactClicked();

    //void newContactCreated();
    //void contactEdited();
    //void contactDeleted();

    void ContactAddedError(const QString& eroor_);
    void ContactAdded(const contactItemPtr new_contact_);

Q_SIGNALS:
    void newContact(const contactItemPtr new_contact_);
    void showContact(const QVariant& var_);


private:
    Ui::Address_bookClass *ui;
    QSharedPointer<Helper> helper;

    const QString SAVE_BUTTON = "Save";
    const QString EDIT_BUTTON = "Edit";

};
