#pragma once

#include <QAbstractListModel>
#include <QVariant>
#include <QSize>


#include "ContactItem.h"

class ContactModel : public QAbstractListModel
{
	Q_OBJECT;
	friend class ContactView;

public:
	enum Role
	{
		ChatRole = Qt::UserRole,
	};

	explicit ContactModel(QObject* parent = Q_NULLPTR);
	~ContactModel() override;

	ContactModel(const ContactModel&) = delete;
	ContactModel(ContactModel&&) = delete;
	const ContactModel& operator =(const ContactModel&) = delete;
	ContactModel& operator = (ContactModel&&) = delete;


	//[[nodiscard]] contactItemPtr getContactFromName(const QString& name_) const;

	[[nodiscard]] int rowCount(QModelIndex const& parent = QModelIndex()) const override final;
	[[nodiscard]] QVariant data(QModelIndex const& index, int role = Qt::DisplayRole) const override final;
	[[nodiscard]] Qt::ItemFlags flags(const QModelIndex& index) const override final;

	using QAbstractListModel::beginInsertRows;
	using QAbstractListModel::endInsertRows;
	using QAbstractListModel::beginRemoveRows;
	using QAbstractListModel::endRemoveRows;
	using QAbstractListModel::beginResetModel;
	using QAbstractListModel::endResetModel;

	using QAbstractListModel::dataChanged;

	public Q_SLOT:
	void addContact(const QVariant& new_contact_);
	void addContacts(const QVariantList& new_contacts_list_);

private Q_SLOTS:
	void clear();

private:
	contactList model_contacts;
	QMap<QString, contactItemPtr> model_name_to_contact;
};


