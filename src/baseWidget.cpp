#include "baseWidget.h"

#include <typeinfo>
#include <QString>

ios::BaseWidget::BaseWidget(QWidget * _parent) :
	QWidget(_parent)
{
	m_ident = -1;
}

ios::BaseWidget::~BaseWidget()
{
	//empty
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

void ios::BaseWidget::setValue(int _value) const
{
	//empty
}

void ios::BaseWidget::setValue(double) const
{
	//empty
}

void ios::BaseWidget::setUnit(const QString &) const
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

void ios::BaseWidget::setIdent(int _ident)
{
	m_ident = _ident;
}

int ios::BaseWidget::ident() const
{
	return m_ident;
}

void ios::BaseWidget::setName(const QString & _name)
{
	setObjectName(_name);
}

const QString & ios::BaseWidget::name() const
{
	return objectName();
}
