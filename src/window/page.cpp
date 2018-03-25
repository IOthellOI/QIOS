#include "navigationBar.h"
#include "navigationButton.h"
#include "xmlRead.h"

#include <cassert>
#include <QLayout>
#include <QButtonGroup>
#include <QStackedLayout>
#include <QVector>

struct NavigationBar::NavigationBarPrivate
{
	QVBoxLayout * oneLevelLayout;
	QStackedLayout * twoLevelLayout;
	QButtonGroup * oneLevelGroup;
	QVector<QButtonGroup *>  * twoLevelGroup;
};

NavigationBar::NavigationBar(QFrame * _parent) :
	QFrame(_parent),
	data(new NavigationBarPrivate)
{
	setMinimumWidth(200);
	setMaximumWidth(200);

	QHBoxLayout * layout = new QHBoxLayout;
	layout->setMargin(0);
	layout->setSpacing(0);

	data->oneLevelLayout = new QVBoxLayout;
	data->oneLevelLayout->setMargin(0);
	data->oneLevelLayout->setSpacing(0);
	data->oneLevelLayout->setAlignment(Qt::AlignTop);

	data->twoLevelLayout = new QStackedLayout;
	data->twoLevelLayout->setMargin(0);
	data->twoLevelLayout->setSpacing(0);
	data->twoLevelLayout->setAlignment(Qt::AlignTop);

	layout->addLayout(data->oneLevelLayout);
	layout->addLayout(data->twoLevelLayout);

	data->oneLevelGroup = new QButtonGroup;
	data->twoLevelGroup = new QVector<QButtonGroup *>;
	
	setLayout(layout);
}

NavigationBar::~NavigationBar()
{
	delete data;
}

void NavigationBar::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;	

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement oneLevelElement = root.firstChildElement();

	NavigationButton * button = nullptr;

	while (!oneLevelElement.isNull())
	{
		button = new NavigationButton;
		button->setText(oneLevelElement.attribute("text"));
		data->oneLevelLayout->addWidget(button);
		data->oneLevelGroup->addButton(button);

		QDomElement twoLevelElement = oneLevelElement.firstChildElement();

		QVBoxLayout * layout = new QVBoxLayout;
		layout->setMargin(0);
		layout->setSpacing(0);
		layout->setAlignment(Qt::AlignTop);

		QWidget * widget = new QWidget;
		widget->setLayout(layout);

		data->twoLevelLayout->addWidget(widget);
		while (!twoLevelElement.isNull())
		{
			button = new NavigationButton;
			button->setText(twoLevelElement.attribute("text"));
			layout->addWidget(button);
			twoLevelElement = twoLevelElement.nextSiblingElement();
		}
		oneLevelElement = oneLevelElement.nextSiblingElement();
	}


}
