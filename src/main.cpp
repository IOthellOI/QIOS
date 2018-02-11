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
#include "progressBar.h"
#include "entryBar.h"

#pragma execution_character_set("utf-8")

using namespace ios;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	QWidget w; 
	w.setWindowFlags(Qt::FramelessWindowHint);
	QHBoxLayout l;	
	EntryBar d;
	d.setText("»º”Õ”‡¡ø");
	d.setValue(20);
	d.setUnit("kg");
	l.addWidget(&d);

	w.setLayout(&l);
	w.show();
	return a.exec();
}