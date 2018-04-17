#pragma once
#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

class TextEdit : public QTextEdit
{
public:
	explicit TextEdit(QWidget * _parent = nullptr);
	virtual ~TextEdit();
};

#endif // !TEXTEDIT_H
