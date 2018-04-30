#pragma once
#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include <QLabel>
#include <internalData.h>

class TextLabel : public QLabel
{
	Q_OBJECT
public:
	explicit TextLabel(QWidget * _parent = nullptr);
	virtual ~TextLabel();

public:
	void setColor(const QString & _color);
    void setData(InternalData * _data);

public slots:
    void slotTextUpdate(const QString & _text);

protected:
};

#endif // !TEXTLABEL_H
