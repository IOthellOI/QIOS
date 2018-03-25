#include "navigationBar.h"
#include "navigationButton.h"
#include "xmlRead.h"
#include "dataPool.h"

#include <cassert>
#include <QLayout>
#include <QButtonGroup>

struct NavigationBar::NavigationBarPrivate
{
	QVBoxLayout * layout;
	QButtonGroup * group;
};

NavigationBar::NavigationBar(QFrame * _parent) :
	QFrame(_parent),
	data(new NavigationBarPrivate)
{
	setObjectName("NavigationBar");
	setMinimumWidth(120);
	setMaximumWidth(120);

	data->layout = new QVBoxLayout;
	data->layout->setMargin(0);
	data->layout->setSpacing(0);
	data->layout->setAlignment(Qt::AlignTop);

	data->group = new QButtonGroup;

	connect(data->group,
		SIGNAL(buttonClicked(int)),
		this,
		SLOT(slotNavigationChange(int)));

	setLayout(data->layout);
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

	auto b = DataPool::internalDataMap()->value(root.attribute("navigationData"));

	auto a = connect(this,
		SIGNAL(signalNavigationChange(const QString &)),
		DataPool::internalDataMap()->value(root.attribute("navigationData")),
		SLOT(slotDataUpdate(const QString &)));

	QDomElement element = root.firstChildElement();

	NavigationButton * button = nullptr;

	for (size_t i = 0; !element.isNull(); i++)
	{
		button = new NavigationButton;
		button->setText(element.attribute("text"));
		button->setIcon(QIcon(element.attribute("icon")));
		data->layout->addWidget(button);
		data->group->addButton(button,i);
		element = element.nextSiblingElement();
	}

	data->group->button(0)->setChecked(true);
}

void NavigationBar::slotNavigationChange(int _id)
{
	emit(signalNavigationChange(QString::number(data->group->checkedId())));
}
