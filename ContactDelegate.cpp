#include "ContactDelegate.h"

ContactDelegate::ContactDelegate(QObject* parent)
	: QItemDelegate(parent)
{
}

ContactDelegate::~ContactDelegate()
{
}

void ContactDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
}

QSize ContactDelegate::sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const
{
	const auto& chat = index.data(ContactModel::ChatRole).value<contactItemPtr>();

	const int added_height = 10 * 2;
	const QFontMetrics fm{ {"Titilium Web", 14, QFont::Normal} };
	return { option.rect.width(), fm.height() + added_height };
}


