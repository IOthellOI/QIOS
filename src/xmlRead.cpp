#include "xmlRead.h"

#include <QDomDocument>
#include <QFile>

struct ios::XmlRead::XmlReadData
{
	QFile * file;
	QDomDocument * document;
	QDomElement * element;
	QDomNode * node;
};

ios::XmlRead::XmlRead() : 
	data(new XmlReadData)
{
	//empty
}

ios::XmlRead::~XmlRead()
{
	delete data;
}

bool ios::XmlRead::loadFile(const QString & _path)
{
	if (_path.isEmpty())
	{
		return false;
	}
	else
	{
		data->file = new QFile(_path);
	}

	if (data->file == nullptr)
	{

	}


}