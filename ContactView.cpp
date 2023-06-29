#include "ContactView.h"

ContactView::ContactView(QWidget* parent)
	: QListView(parent)
{
	//TODO create font
	//setFont(CHAT_FONT);

	QTimer::singleShot(100, [this]
		{
			const auto model = new ContactModel(this);
			setModel(model);
			setItemDelegate(new ContactDelegate(this));
			connect(model, &ContactModel::rowsInserted, this, &ContactView::onRowsInserted);
		}
	);
	// important !!!
	setResizeMode(Adjust);

	setContextMenuPolicy(Qt::ActionsContextMenu);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setSpacing(0);
	setMouseTracking(true);
	//TODO change style
	//setStyleSheet(VIEW_CHAT_STYLE_SHEET);
}

ContactView::~ContactView() = default;

void ContactView::onContactAdded(const QVariant& new_contact_) const
{
	const auto model = qobject_cast<ContactModel*>(this->model());
	if (!model)
		return;
	model->addContact(new_contact_);
}

void ContactView::onContactsAdded(const QVariantList& contacts_list_) const
{
	const auto model = qobject_cast<ContactModel*>(this->model());
	if (!model)
		return;
	model->addContacts(contacts_list_);
}

void ContactView::onRowsInserted(const QModelIndex& parent, int first, int last)
{
	ensurePolished();
	scrollToBottom();
}

void ContactView::mouseMoveEvent(QMouseEvent* event)
{
	if (const auto& model = qobject_cast<ContactModel*>(this->model()))
	{
		auto const& item_index = indexAt(event->pos());
		if (_last_index != item_index)
		{
			if (_last_index.isValid())
			{
				if (const auto& contact = _last_index.data(ContactModel::ChatRole).value<contactItemPtr>())
				{
					contact->setContactCurrRow(_last_index.row());
					contact->setContactIsHovered(false);
					emit model->dataChanged(_last_index, _last_index);
				}
			}
		}
		_last_index = item_index;
		if (_last_index.isValid())
		{
			const auto contact = _last_index.data(ContactModel::ChatRole).value<contactItemPtr>();
			contact->setContactIsHovered(true);
			emit model->dataChanged(_last_index, _last_index);
		}
	}
	QListView::mouseMoveEvent(event);
}

void ContactView::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (const auto& model = qobject_cast<ContactModel*>(this->model()))
	{
		auto const& item_index = indexAt(event->pos());
		if (item_index.isValid())
		{
			const auto& contact = item_index.data(ContactModel::ChatRole).value<contactItemPtr>();
			const auto& contact_rects = contact->getContactRoomCurrBox();
			if (contact_rects.contains(event->pos()))
			{
				Q_EMIT contactClicked(contact);
			}
		}
	}
	QListView::mouseDoubleClickEvent(event);
}
