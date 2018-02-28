#include "statusMonitor.h"

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
	setMaximumHeight(300);
	setMinimumHeight(300);

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

}

ios::StatusMonitor::~StatusMonitor()
{
	delete data;
}
