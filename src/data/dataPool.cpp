#include "dataPool.h"
#include "xmlRead.h"

#include <QString>
#include <cassert>

struct DataPool::DataPoolPrivate
{
	QMap<QString, InternalData *> * internalMap;
};

DataPool::DataPoolPrivate * DataPool::data = new DataPool::DataPoolPrivate;

DataPool::DataPool(QObject * _parent) :
	QObject(_parent)
{
	data->internalMap = new QMap<QString, InternalData *>;
	loadConfig("./data/data/dataPool.xml");
}

DataPool::~DataPool()
{
}

void DataPool::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	while (!element.isNull())
	{
		if (element.nodeName().toUpper() == "INTERNALDATA")
		{
			loadInternalData(element.attribute("path"));
		}

		element = element.nextSiblingElement();
	}
}

const QMap<QString, InternalData*>* DataPool::internalDataMap()
{
	return data->internalMap;
}

void DataPool::loadInternalData(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	InternalData * internalData = nullptr;
	
	while (!element.isNull())
	{
		internalData = new InternalData;
		internalData->setName(element.attribute("name"));
		internalData->setType(element.attribute("type"));
		internalData->setValue(element.attribute("value"));

		data->internalMap->insert(internalData->name(), internalData);	

		element = element.nextSiblingElement();
	}
}
