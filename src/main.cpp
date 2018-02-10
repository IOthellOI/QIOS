#include <QApplication>
#include <QLayout>
#include <QPixmap>
#include <QTextCodec>

#include "clickButton.h"
#include "toggleButton.h"
#include "mutexButton.h"
#include "navigationButton.h"
#include "textLabel.h"
#include "indicationLabel.h"
#include "dataSlider.h"
#include "dataLabel.h"

#pragma execution_character_set("utf-8")

using namespace ios;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	QWidget w;
	QHBoxLayout l;
	
	DataLabel d;
	l.addWidget(&d);
	d.setText("ËÙ¶È");
	d.setValue(12345.6789);
	d.setUnit("m/s");

	w.setLayout(&l);
	w.show();
	return a.exec();
}