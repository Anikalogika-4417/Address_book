#include "ContactModel.h"

ContactModel::ContactModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

ContactModel::~ContactModel()
{
    clear();
}

void ContactModel::clear()
{
    beginResetModel();
    model_contacts.clear();
    endResetModel();
}

//contactItemPtr ContactModel::getContactFromName(const QString& name_) const
//{
//    return model_name_to_contact(name_);
//}

int ContactModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
        return static_cast<int>(model_contacts.size());
}

QVariant ContactModel::data(const QModelIndex& index, int role) const
{
    if (auto const contact = (index.isValid() && index.row() < rowCount()) ? model_contacts.at(index.row()) : nullptr)
    {
        switch (role)
        {
        case Qt::DisplayRole:
            return contact->getContactName();

        case Qt::SizeHintRole:
            return QSize{ 200, 200 };

        case ChatRole:
            return QVariant::fromValue(contact);

        default:
            break;
        }
    }

    return {};
}

Qt::ItemFlags ContactModel::flags(const QModelIndex& index) const
{
    return QAbstractListModel::flags(index);
}

void ContactModel::addContact(const QVariant& new_contact_)
{
    if (const auto contact = new_contact_.value<contactItemPtr>(); contact)
    {
        beginInsertRows(QModelIndex(), static_cast<int>(model_contacts.size()), static_cast<int>(model_contacts.size()));
        model_contacts.emplaceBack(contact);
        endInsertRows();
    }
}


void ContactModel::addContacts(const QVariantList& new_contacts_list_)
{
    if (!new_contacts_list_.isEmpty())
    {
        beginInsertRows(QModelIndex(), static_cast<int>(model_contacts.size()), static_cast<int>(model_contacts.size() + new_contacts_list_.size() - 1));
        for (auto const& contact_var : new_contacts_list_)
        {
            if (const auto contact = contact_var.value<contactItemPtr>(); contact)
            {
                model_contacts.emplaceBack(contact);
            }
        }
        endInsertRows();
    }
}
