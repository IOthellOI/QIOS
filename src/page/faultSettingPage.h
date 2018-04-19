#pragma once
#ifndef FAULTSETTINGPAGE_H
#define FAULTSETTINGPAGE_H

#include <QWidget>

class FaultSettingPage : public QWidget
{
	Q_OBJECT
public:
	explicit FaultSettingPage(QWidget * _parent = nullptr);
	virtual ~FaultSettingPage();

private slots:
	void slotFrameShow(bool _show);
	
private:
	struct FaultSettingPagePrivate;
	FaultSettingPagePrivate * data;
};

#endif // !FAULTSETTINGPAGE_H