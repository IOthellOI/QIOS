#pragma once
#ifndef COMPUTERTABLE_H
#define COMPUTERTABLE_H

#include <QTableWidget>

class ComputerTable : public QTableWidget
{
	Q_OBJECT
public:
	explicit ComputerTable(QWidget * _parent = nullptr);
	virtual ~ComputerTable();

public:
	void loadConfig(const QString  & _path);

private:
	struct ComputerTablePrivate;
	ComputerTablePrivate * data;
};

#endif // !COMPUTERTABLE_H