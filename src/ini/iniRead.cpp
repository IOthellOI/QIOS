#include "iniRead.h"

#include <QSettings>

struct IniRead::IniReadPrivate
{
	QSettings * iniRead;
};

IniRead::IniRead(QObject * _prent) :
	QObject(_prent),
	data(new IniReadPrivate)
{
	data->iniRead = new QSettings("data/config.ini");
}

IniRead::~IniRead()
{

}
