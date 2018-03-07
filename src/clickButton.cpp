#include "clickButton.h"

#include <QPushButton>
#include <QLayout>

struct ios::ClickButton::ClickButtonData
{
	QPushButton * button;
	QHBoxLayout * layout;
};

ios::ClickButton::ClickButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new ClickButtonData)
{
	data->button = new QPushButton;
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->button);
	data->layout->setMargin(0);
	setLayout(data->layout);

	setStyleSheet("border-image: url();");

	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

ios::ClickButton::~ClickButton()
{
	delete data;
}

void ios::ClickButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}
