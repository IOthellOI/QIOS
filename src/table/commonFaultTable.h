#pragma once
#ifndef COMMONFAULTTABLE_H
#define COMMONFAULTTABLE_H

#include <QTableWidget>

class CommonFaultTable : public QTableWidget
{
	Q_OBJECT
public:
	explicit CommonFaultTable(QWidget * _parent = nullptr);
	virtual ~CommonFaultTable();

public:
	void loadConfig(const QString  & _path);

private:
	struct CommonFaultTablePrivate;
	CommonFaultTablePrivate * data;
};

#endif // !COMMONFAULTTABLE_H