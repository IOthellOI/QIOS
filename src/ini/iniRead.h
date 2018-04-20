#pragma once
#ifndef INIREAD_H
#define INIREAD_H

#include <QObject>
#include <QSize>

class IniRead : public QObject
{
	Q_OBJECT
public:
	explicit IniRead(QObject * _prent = nullptr);
	virtual ~IniRead();

public:
	void loadIni(const QString & _path);
	static QSize windowFormSize();

	static QStringList dabaBaseMessage();

	struct IniReadPrivate;
	static IniReadPrivate * data;
};

#endif // !INIREAD_H