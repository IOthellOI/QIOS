#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class Database : public QObject
{
	Q_OBJECT
public:
	explicit Database(QObject * _parent = nullptr);
	virtual ~Database();

private:
	struct DatabasePrivate;
	DatabasePrivate * data;
};

#endif // !DATABASE_H
