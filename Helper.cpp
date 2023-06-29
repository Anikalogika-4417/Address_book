#include "Helper.h"

Helper::Helper() : 
	file(QCoreApplication::applicationDirPath() + "/book.txt")
{
}

QSharedPointer<Helper> Helper::helpPtr = nullptr;

QSharedPointer<Helper> Helper::instance()
{
    if (helpPtr.isNull())
    {
        helpPtr.reset(new Helper);
    }
    return helpPtr;
}

void Helper::AddLine(const contactItemPtr new_contact_)
{
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        emit FileEroor("Failed to open file for writing");
        return;
    }

    QTextStream out(&file);

    auto a = file.fileName();
    QStringList line;

    if (!new_contact_->getContactId().isEmpty() && !new_contact_->getContactName().isEmpty() && !new_contact_->getContactPhone().isEmpty()) {
        line << new_contact_->getContactId();
        line << new_contact_->getContactName();
        line << new_contact_->getContactPhone();
        line << new_contact_->getContactWork();
    }
    else {
        emit FileEroor("Not all fileds filled");
        return;
    }

    out << line.join(",") << "\n";
    file.close();
    emit ContactAdded(new_contact_);

}

contactItemPtr Helper::ReadLine(const QString&)
{
    return contactItemPtr();
}

contactItemPtr Helper::DeleteFile(const QString&)
{
	return contactItemPtr();
}
