#ifndef WINDOWFORM_H
#define WINDOWFORM_H
#pragma once

#include <QWidget>

class WindowForm : public  QWidget
{
	Q_OBJECT
public:
	explicit WindowForm(QWidget * _parent = nullptr);
	virtual ~WindowForm();
};

#endif // !WINDOWFORM_H

