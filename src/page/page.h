#pragma once
#ifndef PAGE_H
#define PAGE_H

#include <QWidget>

class Page : public QWidget
{
	Q_OBJECT
public:
	explicit Page(QWidget * _parent = nullptr);
	virtual ~Page();

public:
	void loadConfig(const QString  & _path);
	void setName(const QString & _name);
	QString name();

public:
	struct PagePrivate;
	PagePrivate * data;
};

#endif // !PAGE_H
