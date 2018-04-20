#pragma once
#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

class TextEdit : public QTextEdit
{
	Q_OBJECT
public:
	explicit TextEdit(QWidget * _parent = nullptr);
	virtual ~TextEdit();
};

#endif // !TEXTEDIT_H
