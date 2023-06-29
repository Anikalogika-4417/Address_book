#include "ContactDelegate.h"

ContactDelegate::ContactDelegate(QObject* parent)
	: QItemDelegate(parent)
{
}

ContactDelegate::~ContactDelegate()
{
}

QSize ContactDelegate::sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const
{
	const auto& chat = index.data(ContactModel::ContactRole).value<contactItemPtr>();

	const int added_height = 10 * 2;
	const QFontMetrics fm{ {"Titilium Web", 14, QFont::Normal} };
	return { option.rect.width(), fm.height() + added_height };
}

void ContactDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	const auto& contact = index.data(ContactModel::ContactRole).value<contactItemPtr>();

	const auto whole_rect = option.rect;

	const auto& draw_name = [&]()
	{
		painter->drawText(whole_rect, Qt::AlignLeft | Qt::AlignVCenter, contact->getContactName());
	};

	draw_name();
}



