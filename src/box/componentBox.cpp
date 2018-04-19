#include "componentBox.h"

#include <QLabel>
#include <QLayout>

struct ComponentBox::ComponentBoxPrivate
{
	QGridLayout * layout;
	QLabel * title;
};

ComponentBox::ComponentBox(QWidget * _parent) :
	QGroupBox(_parent),
	data(new ComponentBoxPrivate)
{
	setObjectName("ComponentBox");
	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	
	data->title = new QLabel;
	data->title->setObjectName("ComponentBox");
	layout->addWidget(data->title);

	data->title->setMinimumWidth(width());
	QSizePolicy policy = data->title->sizePolicy();
	policy.setHorizontalPolicy(QSizePolicy::Expanding);
	data->title->setSizePolicy(policy);

	QWidget * widget = new QWidget;
	data->layout = new QGridLayout(widget);
	policy = widget->sizePolicy();
	policy.setHorizontalPolicy(QSizePolicy::Expanding);
	policy.setVerticalPolicy(QSizePolicy::Expanding);
	widget->setSizePolicy(policy);
	data->layout->setMargin(10);
	layout->addWidget(widget);

	layout->setAlignment(Qt::AlignTop);
}

ComponentBox::~ComponentBox()
{
	delete data;
}

void ComponentBox::setTitle(const QString & _title)
{
	data->title->setText(_title);
}

QString ComponentBox::title()
{
	return data->title->text();
}

void ComponentBox::setSpacing(int _space)
{
	data->layout->setSpacing(_space);
}

void ComponentBox::setAlignmnet(const QString & _alignment)
{
	if (_alignment == "center")
	{
		data->layout->setAlignment(Qt::AlignCenter);
	}
	else if (_alignment == "top")
	{
		data->layout->setAlignment(Qt::AlignTop);
	}
	else if (_alignment == "bottom")
	{
		data->layout->setAlignment(Qt::AlignBottom);
	}
	else if (_alignment == "left")
	{
		data->layout->setAlignment(Qt::AlignLeft);
	}
	else if (_alignment == "right")
	{
		data->layout->setAlignment(Qt::AlignRight);
	}
}

void ComponentBox::addWidget(QWidget * _widget, int _row, int _column, int _rowSpan, int _columnSpan)
{
	data->layout->addWidget(_widget, _row, _column, _rowSpan, _columnSpan);
}
