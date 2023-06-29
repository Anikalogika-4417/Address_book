#pragma once

#include <QFile>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "ContactItem.h"

class Helper : public QObject
{
	Q_OBJECT;
public:
	static QSharedPointer<Helper> instance();

public Q_SLOTS:
	void AddLine(const contactItemPtr);
	contactItemPtr ReadLine(const QString&);
	contactItemPtr DeleteFile(const QString&);
Q_SIGNALS:
	void FileEroor(const QString& error_);
	void ContactAdded(const contactItemPtr new_contact_);
private:
	Helper();

	QFile file;
	static QSharedPointer<Helper> helpPtr;
};

