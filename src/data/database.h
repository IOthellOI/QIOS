#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

class Database : public QObject
{
	Q_OBJECT
public:
	explicit Database(QObject * _parent = nullptr);
	virtual ~Database();

public:
    static QSqlTableModel * userDatabase();

	struct DatabasePrivate;
    static DatabasePrivate * data;
};

#endif // !DATABASE_H
