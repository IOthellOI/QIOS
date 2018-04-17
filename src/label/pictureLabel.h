#pragma once
#ifndef PICTURELABEL_H
#define PICTURELABEL_H

#include <QLabel>

class PictureLabel : public QLabel
{
	Q_OBJECT
public:
	explicit PictureLabel(QWidget * _parent = nullptr);
	virtual ~PictureLabel();

};

#endif // !PICTURELABEL_H