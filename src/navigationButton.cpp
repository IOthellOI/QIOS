#include "navigationButton.h"

#include <QPushButton>
#include <QToolButton>
#include <QButtonGroup>
#include <QLayout>

struct ios::NavigationButton::NavigationButtonData
{
	QToolButton * button;
	QHBoxLayout * layout;
	static QButtonGroup * buttonGroup;
};

QButtonGroup * ios::NavigationButton::NavigationButtonData::buttonGroup = new QButtonGroup;

ios::NavigationButton::NavigationButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new NavigationButtonData)
{
	data->button = new QToolButton;
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

	data->buttonGroup->addButton(data->button);

	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

ios::NavigationButton::~NavigationButton()
{
	delete data;
}

void ios::NavigationButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void ios::NavigationButton::setIcon(const QIcon & _icon) const
{
	data->button->setIcon(QIcon(_icon));
	QSize size(100, 100);
	data->button->setIconSize(size);
}

void ios::NavigationButton::slotClicked(bool _clicked)
{
	if (_clicked)
	{
		emit signalClicked();
	}
	else
	{
		setChecked(true);
	}
}
