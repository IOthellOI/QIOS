#pragma once
#ifndef EXTERNALDATA_H
#define EXTERNALDATA_H

#include <QObject>

class ExternalData : public QObject
{
	Q_OBJECT
public:
	explicit ExternalData(QObject * _parent = nullptr);
	virtual ~ExternalData();

public:
	void setName(const QString & _name);
	QString name();
	void setType(const QString & _type);
	QString type();
	void setValue(const QString & _value);
	QString value();
	void setUnit(const QString & _unit);
	QString unit();
	void setMinValue(const QString & _min);
	QString minValue();
	void setMaxValue(const QString & _max);
	QString maxValue();
	void setAddress(int _address);
	int address();	

signals:
	void signalDataUpdate(const QString & _value);
	void signalDataUpdate(unsigned short _value);
	void signalDataUpdate(int _value);
	void signalDataUpdate(float _value);
	void signalDataUpdate(double _value);

public slots:
	void slotDataUpdate(const QString & _value);
	void slotDataUpdate(unsigned short _value);
	void slotDataUpdate(int _value);
	void slotDataUpdate(float _value);
	void slotDataUpdate(double _value);

private:
	struct ExternalDataPrivate;
	ExternalDataPrivate * data;
};

#endif // !EXTERNALDATA_H


