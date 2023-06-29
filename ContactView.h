#pragma once

#include <QListView>
#include <QTimer>
#include <QMouseEvent>

#include "ContactItem.h"
#include "ContactModel.h"
#include "ContactDelegate.h"

class ContactView : public QListView
{
	Q_OBJECT;

public:
	explicit ContactView(QWidget* parent);
	~ContactView() override;

	ContactView(const ContactView&) = delete;
	ContactView(ContactView&&) = delete;
	const ContactView& operator =(const ContactView&) = delete;
	ContactView& operator = (ContactView&&) = delete;

public Q_SLOTS:
	void onContactAdded(const QVariant& new_contact_) const;
	void onContactsAdded(const QVariantList& contacts_list_) const;
	void onRowsInserted(const QModelIndex& parent, int first, int last);

Q_SIGNALS:
	void contactClicked(const contactItemPtr contact_data_ptr_);

protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
	QModelIndex _last_index{};
};


