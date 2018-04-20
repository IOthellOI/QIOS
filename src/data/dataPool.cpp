#include "dataPool.h"
#include "xmlRead.h"

#include <QString>
#include <cassert>

struct DataPool::DataPoolPrivate
{
	QMap<QString, InternalData *> * internalMap;
	QMap<QString, ExternalData *> * externalMap;
};

DataPool::DataPoolPrivate * DataPool::data = new DataPool::DataPoolPrivate;

DataPool::DataPool(QObject * _parent) :
	QObject(_parent)
{
	data->internalMap = new QMap<QString, InternalData *>;
    data->externalMap = new QMap<QString, ExternalData *>;
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
		else if (element.nodeName().toUpper() == "EXTERNALDATA")
		{
			loadExternalData(element.attribute("path"));
		}
		element = element.nextSiblingElement();
	}
}


const QMap<QString, InternalData*>* DataPool::internalDataMap()
{
	return data->internalMap;
}

const QMap<QString, ExternalData*>* DataPool::externalDataMap()
{
	return data->externalMap;
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
		internalData->setValue(element.attribute("init"));
		data->internalMap->insert(internalData->name(), internalData);	

		element = element.nextSiblingElement();
	}
}

void DataPool::loadExternalData(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	ExternalData * externalData = nullptr;

	while (!element.isNull())
	{
		externalData = new ExternalData;
		externalData->setName(element.attribute("name"));
		externalData->setType(element.attribute("type"));
		externalData->setValue(element.attribute("init"));
		externalData->setUnit(element.attribute("unit"));
		externalData->setMinValue(element.attribute("min"));
		externalData->setMaxValue(element.attribute("max"));
		externalData->setAddress(element.attribute("address").toInt());
		data->externalMap->insert(externalData->name(), externalData);

		element = element.nextSiblingElement();
	}
}
