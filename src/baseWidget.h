//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   BaseWidget
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 8,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QImage>
#include <QIcon>

namespace ios
{
	class BaseWidget : public QWidget
	{
		Q_OBJECT
	public:
		explicit BaseWidget(QWidget * _parent = nullptr);
		virtual ~BaseWidget();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setChecked(bool _checked) const;
		virtual void setState(int _state) const;
		virtual void setValue(int _value) const;
		virtual void setValue(double _value) const;
		virtual void setUnit(const QString & _unit) const;
		virtual void loadConfig(const QString & _path) const;
		virtual void setImage(const QImage & _image) const;;
		virtual void setIcon(const QIcon & _icon) const;
		virtual void setGroup(int _group) const;
		
	public:
		void setIdent(int _ident);
		int ident() const;
		void setName(const QString & _name);
		const QString & name()const;

	private:
		int m_ident;
	};
}

#endif // !BASEWIDGET_H