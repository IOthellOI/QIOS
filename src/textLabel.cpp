#include "textLabel.h"

#include <QLayout>
#include <QLabel>

struct ios::TextLabel::TextLabelData
{
	QLabel * label;
	QHBoxLayout * layout;
};

ios::TextLabel::TextLabel(QWidget * _parent) :
	BaseWidget(_parent),
	data(new TextLabelData)
{
	data->label = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->label);
	data->layout->setMargin(0);

	setLayout(data->layout);
}

ios::TextLabel::~TextLabel()
{
	delete data;
}

void ios::TextLabel::setText(const QString & _text) const
{
	data->label->setText(_text);
}
