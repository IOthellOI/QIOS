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
	data->backgroundColorOff = QColor(210, 210, 210);
	data->backgroundColorOn = QColor(245, 245, 245);
	data->sliderColorOff = QColor(100, 100, 100);
	data->sliderColorOn = QColor(100, 240, 139);
	data->textColorOff = QColor(0, 0, 0);
	data->textColorOn = QColor(0, 0, 0);
	data->textOff = u8"´ò¿ª";
	data->textOn = u8"¹Ø±Õ";

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

void SwitchButton::updateValue()
{
	if (data->checked) {
		if (data->startX < data->endX) {
			data->startX = data->startX + data->step;
		}
		else {
			data->startX = data->endX;
			data->timer->stop();
		}
	}
	else {
		if (data->startX > data->endX) {
			data->startX = data->startX - data->step;
		}
		else {
			data->startX = data->endX;
			data->timer->stop();
		}
	}
	update();
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

void SwitchButton::drawSlider(QPainter * _painter)
{
	_painter->save();
	_painter->setPen(Qt::NoPen);
	if (!data->checked) {
		_painter->setBrush(data->sliderColorOff);
	}
	else {
		_painter->setBrush(data->sliderColorOn);
	}
	int sliderWidth = width() / 2 - data->space * 2;
	int sliderHeight = height() - data->space * 2;
	QRect sliderRect(data->startX + data->space, data->space, sliderWidth, sliderHeight);
	_painter->drawRoundedRect(sliderRect, data->rectRadius, data->rectRadius);

	_painter->restore();
}

void SwitchButton::drawText(QPainter * _painter)
{
	_painter->save();

	if (!data->checked) {
		_painter->setPen(data->textColorOff);
		_painter->drawText(width() / 2, 0, width() / 2 - data->space, height(), Qt::AlignCenter, data->textOff);
	}
	else {
		_painter->setPen(data->textColorOn);
		_painter->drawText(0, 0, width() / 2 + data->space * 2, height(), Qt::AlignCenter, data->textOn);
	}

	_painter->restore();
}
