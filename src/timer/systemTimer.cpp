#include "systemTimer.h"

#include <QTimer>

struct SystemTimer::SystemTimerPrivate
{
	QTimer * timer100ms;
	QTimer * timer1000ms;
};

SystemTimer::SystemTimerPrivate *  SystemTimer::data = new SystemTimerPrivate;

SystemTimer::SystemTimer(QObject * _parent) :
	QObject(_parent)	
{
	data->timer100ms = new QTimer;
	data->timer100ms->setInterval(100);
	data->timer100ms->start();
	data->timer1000ms = new QTimer;
	data->timer1000ms->setInterval(1000);
	data->timer1000ms->start();
}

SystemTimer::~SystemTimer()
{
	delete data;
}

QTimer * SystemTimer::timer(const QString & _timer)
{
	if (_timer == "100ms")
	{
		return data->timer100ms;
	}
	else if (_timer == "1000ms")
	{
		return data->timer1000ms;
	}
	else
	{
		return nullptr;
	}
}

QTimer * SystemTimer::creatTimer(const QString & _timer)
{
	if (_timer == "100ms")
	{
		static QTimer * timer = new QTimer;
		timer->setInterval(100);
		timer->start();
		return timer;
	}
	else if (_timer == "1000ms")
	{
		static QTimer * timer = new QTimer;
		timer->setInterval(1000);
		timer->start();
		return timer;
	}
	else
	{
		return nullptr;
	}
}
