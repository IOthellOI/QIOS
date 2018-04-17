#pragma once
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QFrame>

class TitleBar : public QFrame
{
	Q_OBJECT
public:
	explicit TitleBar(QFrame * _parent = nullptr);
	virtual ~TitleBar();

public:
	void loadConfig(const QString & _path);

private:
	struct TitleBarPrivate;
	TitleBarPrivate * data;
};

#endif // !TITLEBAR_H


