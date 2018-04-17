#pragma once
#ifndef COMPONENTBOX_H
#define COMPONENTBOX_H

#include <QGroupBox>

class ComponentBox : public QGroupBox
{
	Q_OBJECT
public:
	explicit ComponentBox(QWidget * _parent = nullptr);
	virtual ~ComponentBox();

public:
	void setTitle(const QString & _title);
	void setSpacing(int _space);
	void addWidget(QWidget * _widget, int _row, int _column, int _rowSpan, int _columnSpan);

private:
	struct ComponentBoxPrivate;
	ComponentBoxPrivate * data;
};

#endif // !COMPONENTBOX_H

