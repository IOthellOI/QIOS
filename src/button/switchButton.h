#pragma once
#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QWidget>
#include <QTimer>

class SwitchButton : public QWidget
{
	Q_OBJECT
public:
	explicit SwitchButton(QWidget * _parent = nullptr);
	virtual ~SwitchButton();

signals:
	void checkedChanged(bool checked);

private slots:
	void updateValue();

protected:
	void mousePressEvent(QMouseEvent *);
	void resizeEvent(QResizeEvent *);
	void paintEvent(QPaintEvent *);
	void drawBackground(QPainter * _painter);
	void drawSlider(QPainter * _painter);
	void drawText(QPainter * _painter);

private:
	struct SwitchButtonPrivate;
	SwitchButtonPrivate * data;
};


#endif // !SWITCHBUTTON_H

