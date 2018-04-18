#pragma once
#ifndef SYSTEMTIMER_H
#define SYSTEMTIMER_H

#include <QObject>
#include <QTimer>

class SystemTimer : public QObject
{
	Q_OBJECT
public:
	explicit SystemTimer(QObject * _parent = nullptr);
	virtual ~SystemTimer();

public:
	static QTimer * timer(const QString & _timer);
	static QTimer * creatTimer(const QString &  _timer);

private:
	struct SystemTimerPrivate;
	static SystemTimerPrivate * data;
};

#endif // !SYSTEMTIMER_H