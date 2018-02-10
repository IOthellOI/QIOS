#include "toggleButton.h"

#include <QPushButton>
#include <QLayout>

struct ios::ToggleButton::ToggleButtonData
{
	QPushButton * button;
	QHBoxLayout * layout;
};

ios::ToggleButton::ToggleButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new ToggleButtonData)
{
	data->button = new QPushButton;
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);
	data->button->setCheckable(true);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->button);
	data->layout->setContentsMargins(0, 0, 0, 0);
	data->layout->setMargin(0);
	setLayout(data->layout);

	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotToggled(bool)));
}

ios::ToggleButton::~ToggleButton()
{
}

void ios::ToggleButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void ios::ToggleButton::setChecked(bool _checked) const
{
	data->button->setChecked(_checked);
}

void ios::ToggleButton::slotClicked(bool _clicked)
{
	bool a = _clicked;
	emit signalClicked(_clicked);
}