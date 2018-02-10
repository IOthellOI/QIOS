#include "baseWidget.h"

#include <typeinfo>
#include <QString>

struct ios::BaseWidget::BaseWidgetData
{
	int ident;
	QString name;
};

ios::BaseWidget::BaseWidget(QWidget * _parent) :
	QWidget(_parent),
	data(new BaseWidgetData)
{

}

ios::BaseWidget::~BaseWidget()
{
	delete data;
}

void ios::BaseWidget::setText(const QString &) const
{
	//empty
}

void ios::BaseWidget::setChecked(bool) const
{
	//empty
}

void ios::BaseWidget::setState(int) const
{
	//empty
}

void ios::BaseWidget::setValue(double _value) const
{
	//empty
}

void ios::BaseWidget::setUnit(const QString & _unit) const
{
	//empty
}

void ios::BaseWidget::loadConfig(const QString &) const
{
	//empty
}

void ios::BaseWidget::setImage(const QImage &) const
{
	//empty
}

void ios::BaseWidget::setIcon(const QIcon &) const
{
	//empty
}

void ios::BaseWidget::setGroup(int) const
{
	//empty
}

inline void ios::BaseWidget::setIdent(int _ident) const
{
	data->ident = _ident;
}

inline int ios::BaseWidget::ident() const
{
	return data->ident;
}

inline void ios::BaseWidget::setName(const QString & _name) const
{
	data->name = _name;
}

inline const QString & ios::BaseWidget::name() const
{
	return data->name;
}
