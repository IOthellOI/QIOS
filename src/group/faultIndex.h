#pragma once
#ifndef FAULTINDEX_H
#define FAULTINDEX_H

#include <QWidget>

class FaultIndex : public QWidget
{
	Q_OBJECT
public:
	explicit FaultIndex(QWidget * _parent = nullptr);
	virtual ~FaultIndex();

public:
	void loadConfig(const QString & _path);

private slots:


private:
	struct FaultIndexPrivate;
	FaultIndexPrivate * data;
};

#endif // !FAULTINDEX_H
