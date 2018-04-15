#pragma once
#ifndef SOUNDTABLE_H
#define SOUNDTABLE_H

#include <QTableWidget>

class SoundTable : public QTableWidget
{
	Q_OBJECT
public:
	explicit SoundTable(QWidget * _parent = nullptr);
	virtual ~SoundTable();

public:
	void loadConfig(const QString  & _path);

private:
	struct SoundTablePrivate;
	SoundTablePrivate * data;
};

#endif // !SOUNDTABLE_H