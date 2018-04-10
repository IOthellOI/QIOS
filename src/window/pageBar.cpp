#include "pageBar.h"
#include "xmlRead.h"

#include <QStackedWidget>
#include <QLayout>
#include <cassert>

struct PageBar::PageBarPrivate
{
	QStackedWidget * group;
};

PageBar::PageBar(QFrame * _parent) :
	QFrame(_parent),
	data(new PageBarPrivate)
{
	setObjectName("PageBar");

	data->group = new QStackedWidget(this);

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(data->group);

	QFrame * frame = new QFrame;
	
	data->group->addWidget(frame);
}

PageBar::~PageBar()
{
	
}

void PageBar::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();
}
