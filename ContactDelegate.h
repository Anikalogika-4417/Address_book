#pragma once

#include <QItemDelegate>
#include <QPainter>


#include "ContactModel.h"
#include "ContactItem.h"


class ContactItem;
class ContactDelegate final : public QItemDelegate
{
	Q_OBJECT

public:
	explicit ContactDelegate(QObject* parent);
	~ContactDelegate() override;

	ContactDelegate(const ContactDelegate&) = delete;
	ContactDelegate(ContactDelegate&&) = delete;
	const ContactDelegate& operator =(const ContactDelegate&) = delete;
	ContactDelegate& operator = (ContactDelegate&&) = delete;

protected:

	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
	[[nodiscard]] QSize sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const override;
};
