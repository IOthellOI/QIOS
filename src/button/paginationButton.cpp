#include "paginationButton.h"

struct PaginationButton::PaginationButtonPrivate
{
	QString * bindPage;
};

PaginationButton::PaginationButton(QWidget * _parent) :
	QToolButton(_parent),
	data(new PaginationButtonPrivate)
{
	setObjectName("PaginationButton");

	setCheckable(true);

	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	data->bindPage = new QString;
}

PaginationButton::~PaginationButton()
{
	delete data;
}

void PaginationButton::setBindPage(const QString & _page)
{
	*data->bindPage = _page;
}

QString PaginationButton::bindPage()
{
	return *data->bindPage;
}

