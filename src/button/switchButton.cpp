#include "switchButton.h"

#include <QColor>
#include <QPainter>

struct SwitchButton::SwitchButtonPrivate
{
	bool checked;
	QColor backgroundColorOff;
	QColor backgroundColorOn;
	QColor sliderColorOff;
	QColor sliderColorOn;
	QColor textColorOff;
	QColor textColorOn;
	QString textOff;
	QString textOn;
	int space;
	int rectRadius;
	int step;
	int startX;
	int endX;
	QTimer * timer;
};

SwitchButton::SwitchButton(QWidget * _parent) :
	QWidget(_parent),
	data(new SwitchButtonPrivate)
{
	data->checked = false;
	data->backgroundColorOff = QColor(225, 225, 225);
	data->backgroundColorOn = QColor(250, 250, 250);
	data->sliderColorOff = QColor(100, 100, 100);
	data->sliderColorOn = QColor(100, 184, 255);
	data->textColorOff = QColor(255, 255, 255);
	data->textColorOn = QColor(10, 10, 10);
	data->textOff = "¹Ø±Õ";
	data->textOn = "¿ªÆô";

	data->space = 2;
	data->rectRadius = 5;

	data->step = width() / 50;
	data->startX = 0;
	data->endX = 0;

	data->timer = new QTimer(this);
	data->timer->setInterval(5);

	connect(data->timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

SwitchButton::~SwitchButton()
{
}

void SwitchButton::mousePressEvent(QMouseEvent *)
{
	data->checked = !data->checked;
	emit checkedChanged(data->checked);

	data->step = width() / 50;

	if (data->checked) 
	{
		data->endX = width() - width() / 2;
	}
	else
	{
		data->endX = 0;
	}

	data->timer->start();
}

void SwitchButton::resizeEvent(QResizeEvent *)
{
	data->step = width() / 50;

	if (data->checked)
	{
		data->endX = width() - width() / 2;
	}
	else
	{
		data->endX = 0;
	}

	update();
}

void SwitchButton::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	drawBackground(&painter);
	drawSlider(&painter);
	drawText(&painter);
}

void SwitchButton::drawBackground(QPainter * _painter)
{
	_painter->save();
	_painter->setPen(Qt::NoPen);

	if (!data->checked) {
		_painter->setBrush(data->backgroundColorOff);
	}
	else {
		_painter->setBrush(data->backgroundColorOn);
	}
	
	_painter->drawRoundedRect(rect(), data->rectRadius, data->rectRadius);

	_painter->restore();
}

void SwitchButton::drawSlider(QPainter * painter)
{
}

void SwitchButton::drawText(QPainter * painter)
{
}

void SwitchButton::drawImage(QPainter * painter)
{
}
