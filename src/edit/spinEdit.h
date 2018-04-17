#pragma once
#ifndef SPINEDIT_H
#define SPINEDIT_H

#include <QSpinBox>

class SpinEdit : public QSpinBox
{
public:
	explicit SpinEdit(QWidget * _parent = nullptr);
	virtual ~SpinEdit();
};

#endif // !SPINEDIT_H