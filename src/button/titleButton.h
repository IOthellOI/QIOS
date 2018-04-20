#pragma once
#ifndef TITLEBUTTON_H
#define TITLEBUTTON_H

#include <QPushButton>

class TitleButton : public QPushButton
{
	Q_OBJECT
public:
	explicit TitleButton(QWidget * _parent = nullptr);
	virtual ~TitleButton();

signals:
    void signalTitleCommand(const QString & _command);

private slots:
    void slotButtonClick();

};

#endif // !TITLEBUTTON_H

