#pragma once
#ifndef FAULTBORWSETABLE_H
#define FAULTBORWSETABLE_H

#include <QTableWidget>

class FaultBrowseTable : public QTableWidget
{
	Q_OBJECT
public:
	explicit FaultBrowseTable(QWidget * _parent = nullptr);
	virtual ~FaultBrowseTable();

public:
	void loadConfig(const QString  & _path);

private:
	struct FaultBrowseTablePrivate;
	FaultBrowseTablePrivate * data;
};

#endif // !FAULTBORWSETABLE_H 