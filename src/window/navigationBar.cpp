#include "navigationBar.h"

#include <QLayout>
#include <QStackedLayout>

struct NavigationBar::NavigationBarPrivate
{
	QVBoxLayout * oneLevelLayout;
	QStackedLayout * twoLevelLayout;
};

NavigationBar::NavigationBar(QFrame * _parent) :
	QFrame(_parent),
	data(new NavigationBarPrivate)
{
	setMinimumWidth(200);
	setMaximumWidth(200);

	QHBoxLayout * layout = new QHBoxLayout;
	data->oneLevelLayout = new QVBoxLayout;
	data->twoLevelLayout = new QStackedLayout;
	layout->addLayout(data->oneLevelLayout);
	layout->addLayout(data->twoLevelLayout);
	
	setLayout(layout);
}

NavigationBar::~NavigationBar()
{
	delete data;
}

void NavigationBar::loadConfig(const QString & _path)
{
	
}
