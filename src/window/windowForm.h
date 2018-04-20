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

public slots:
    void slotTitleConmmond(const QString & _text);

private:
    struct WindowFormPrivate;
    WindowFormPrivate * data;
};

#endif // !WINDOWFORM_H

