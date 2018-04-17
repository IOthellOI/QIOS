#pragma once
#ifndef PAGINATIONBUTTON_H
#define PAGINATIONBUTTON_H

#include <QToolButton>

class PaginationButton : public QToolButton
{
	Q_OBJECT
public:
	explicit PaginationButton(QWidget * _parent = nullptr);
	virtual ~PaginationButton();

public:
	void setBindPage(const QString & _page);
	QString bindPage();

private:
	struct PaginationButtonPrivate;
	PaginationButtonPrivate * data;
};


#endif // !PAGINATIONBUTTON_H
