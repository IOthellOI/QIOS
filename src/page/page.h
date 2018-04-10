#pragma once
#ifndef PAGE_H
#define PAGE_H

#include <QWidget>

class Page : public QWidget
{
public:
	explicit Page(QWidget * _parent = nullptr);
	virtual ~Page();

public:
	void loadConfig(const QString  & _path);

public:
	struct PagePrivate;
	PagePrivate * data;
};

#endif // !PAGE_H
