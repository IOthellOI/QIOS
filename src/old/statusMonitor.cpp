#include "statusMonitor.h"
#include "xmlRead.h"
#include "componentFactory.h"

#include <Qlayout>
#include <QLabel>
#include <QTimer>
#include <QTime>

struct ios::StatusMonitor::StatusMonitorData
{
	QGridLayout * leftLayout;
	QVBoxLayout * rightLayout;
	QHBoxLayout * mainLayout;
	QTimer * timer;
	QLabel * time;
};

ios::StatusMonitor::StatusMonitor(QWidget * _parent):
	BaseWidget(_parent),
	data(new StatusMonitorData)
{
	//setMaximumWidth(800);
	//setMinimumWidth(800);
	setMaximumHeight(200);
	setMinimumHeight(200);

	data->leftLayout = new QGridLayout;
	data->rightLayout = new QVBoxLayout;
	data->mainLayout = new QHBoxLayout;
	data->mainLayout->addLayout(data->leftLayout);
	data->mainLayout->addLayout(data->rightLayout);

	QLabel * fault = new QLabel(u8"系统故障信息");
	fault->setAlignment(Qt::AlignCenter);
	data->time = new QLabel(u8"00:00:00");
	data->time->setAlignment(Qt::AlignCenter);

	data->rightLayout->addWidget(fault);
	data->rightLayout->addWidget(data->time);
	
	setLayout(data->mainLayout);

	data->timer = new QTimer;
	connect(data->timer, SIGNAL(timeout()), this, SLOT(slotUpdateTime()));
	data->timer->start(1000);
}

ios::StatusMonitor::~StatusMonitor()
{
	delete data;
}

void ios::StatusMonitor::loadConfig(const QString & _path)
{
	XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}
	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	BaseWidget * widget = nullptr;
	
	while (!element.isNull())
	{
		widget = ComponentFactory::create(element.attribute("type", "IndicationLabel"));

		if (element.hasAttribute("name"))
		{
			widget->setObjectName(element.attribute("name"));
		}
		if (element.hasAttribute("text"))
		{
			widget->setText(element.attribute("text"));
		}
		if (element.hasAttribute("width"))
		{
			widget->setFixedWidth(element.attribute("width").toInt());
		}
		if (element.hasAttribute("height"))
		{
			widget->setFixedHeight(element.attribute("height").toInt());
		}

		int row = element.attribute("row").toInt();
		int column = element.attribute("column").toInt();
		int rowSpan = element.attribute("rowSpan").toInt();
		int columnSpan = element.attribute("columnSpan").toInt();
		data->leftLayout->addWidget(widget, row, column, rowSpan, columnSpan);

		element = element.nextSiblingElement();
	}
}

void ios::StatusMonitor::slotUpdateTime()
{
	QString time;
	QDateTime datetime = QDateTime::currentDateTime();
	time = datetime.toString("yyyy-mm-dd hh::mm::ss");
	data->time->setText(time);
}