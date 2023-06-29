#pragma once

#include <QObject>
#include <QRect>

class ContactItem : public QObject
{
	Q_OBJECT;
public:
	ContactItem(
		QString	contact_name_,
		QString	contact_nickname_,
		QString	contact_phone,
		QString	contact_work) : QObject(nullptr),
		contact_name(std::move(contact_name_)),
		contact_nickname(std::move(contact_nickname_)),
		contact_phone(std::move(contact_phone)),
		contact_work(std::move(contact_work))
	{
		contact_id = 0;
	};

	[[nodiscard]] auto getContactId() { return contact_id; };

	[[nodiscard]] auto getContactName() { return contact_name; };
	void setContactName(const QString& contact_name_) { contact_name = contact_name_; };

	[[nodiscard]] auto getContactNickname() { return contact_nickname; };
	void setContactNickname(const QString& contact_nickname_) { contact_nickname = contact_nickname_; };

	[[nodiscard]] auto getContactPhone() { return contact_phone; };
	void setContactPhone(const QString& contact_phone_) { contact_phone = contact_phone_; };

	[[nodiscard]] auto getContactWork() { return contact_work; };
	void setContactWork(const QString& contact_work_) { contact_work = contact_work_; };

	[[nodiscard]] auto getContactIsHovered() { return is_hovered; };
	void setContactIsHovered(bool is_hovered_) { is_hovered = is_hovered_; };

	[[nodiscard]] auto getContactCurrRow() { return contact_current_row; };
	void setContactCurrRow(int curr_row_) { contact_current_row = curr_row_; };

	[[nodiscard]] auto const& getContactRoomCurrBox() const { return contact_current_box; }
	auto setContactRoomCurrBox(const QRect val) { contact_current_box = val; }

private:
	int			contact_id{0};
	QString		contact_name{};
	QString		contact_nickname{};
	QString		contact_phone{};
	QString		contact_work{};

	bool		is_hovered{ false };
	int			contact_current_row{ 0 };
	QRect		contact_current_box{};
};

using contactItemPtr = QSharedPointer<ContactItem>;
using contactList = QList<contactItemPtr>;
