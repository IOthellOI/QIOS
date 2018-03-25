#include "xmlRead.h"
#include <cassert>

#include <QFile>

struct XmlRead::XmlReadPrivate
{
	QFile * file;
	QDomDocument * document;
	QDomElement * element;
};

XmlRead::XmlRead() : 
	data(new XmlReadPrivate)
{
	//empty
}

XmlRead::~XmlRead()
{
	delete data;
}

void XmlRead::loadFile(const QString & _path)
{
	assert(!_path.isEmpty());

	data->file = new QFile(_path);

	assert(data->file != nullptr);

	data->file->open(QFile::ReadOnly);

	data->document = new QDomDocument;

	if (!data->document->setContent(data->file))
	{
		return;
	}

	data->element = new QDomElement;

	*data->element = data->document->documentElement();
}

QDomElement XmlRead::rootElement()
{
	return *data->element;
}
