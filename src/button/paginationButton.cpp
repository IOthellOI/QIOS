#include "paginationButton.h"

PaginationButton::PaginationButton(QWidget * _parent) :
	QToolButton(_parent)
{
	setObjectName("PaginationButton");

	setCheckable(true);

	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

PaginationButton::~PaginationButton()
{
	
}

