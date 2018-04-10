#include "page.h"
#include "xmlRead.h"

#include <QLayout>
#include <cassert>

struct Page::PagePrivate
{
	QGridLayout * layout;
	QString * name;
};

Page::Page(QWidget * _parent):
	QWidget(_parent),
	data(new PagePrivate)
{
	setObjectName("Page");
	data->layout = new QGridLayout(this);
	data->layout->setMargin(0);
	data->layout->setSpacing(9);
}

Page::~Page()
{
	delete data;
}

void Page::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	while (!element.isNull())
	{
		element = element.nextSiblingElement();
	}
}
