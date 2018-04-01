#pragma once
#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QRadioButton>

class RadioButton : public QRadioButton
{
	Q_OBJECT
public:
	explicit RadioButton(QWidget * _parent = nullptr);
	virtual ~RadioButton();
};

#endif // !RADIOBUTTON_H
