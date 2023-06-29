#include "Helper.h"

Helper::Helper() : 
	file(QCoreApplication::applicationDirPath() + "/book.json")
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

    QJsonObject jsonObject;
    //jsonObject["id"] = new_contact_->getContactId();
    jsonObject["name"] = new_contact_->getContactName();
    jsonObject["nickname"] = new_contact_->getContactNickname();
    jsonObject["phone"] = new_contact_->getContactPhone();
    jsonObject["work"] = new_contact_->getContactWork();

    if (!new_contact_->getContactId().isEmpty() && !new_contact_->getContactName().isEmpty() && !new_contact_->getContactPhone().isEmpty()) {

        if (file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QByteArray fileData = file.readAll();

            QJsonDocument existingJsonDocument = QJsonDocument::fromJson(fileData);

            if (!existingJsonDocument.isNull() && existingJsonDocument.isObject()) {
                QJsonObject existingJsonObject = existingJsonDocument.object();
                existingJsonObject[new_contact_->getContactId()] = jsonObject;
                QJsonDocument updatedJsonDocument(existingJsonObject);
                file.seek(0);
                file.write(updatedJsonDocument.toJson());
            }
            else
            {
                file.seek(0);
                QJsonObject newJsonObject;
                newJsonObject[new_contact_->getContactId()] = jsonObject;
                QJsonDocument jsonDocument(newJsonObject);
                file.write(jsonDocument.toJson());
            }
            file.close();
            emit ContactAdded(new_contact_);
            return;
        }
        else
        {
            emit FileEroor("Failed to create or update data");
            return;
        }
    }
    else {
        emit FileEroor("Not all fileds filled!!!");
        return;
    }
}

contactItemPtr Helper::ReadLine(const QString&)
{
    return contactItemPtr();
}

contactItemPtr Helper::DeleteFile(const QString&)
{
	return contactItemPtr();
}
