#include "soundTable.h"
#include "xmlRead.h"
#include "dataPool.h"

#include <cassert>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QVector>
#include <QLayout>

struct SoundTableItem
{
	QLabel name;
	QSlider slider;
	QLabel value;
};

struct SoundTable::SoundTablePrivate
{
	QVector<SoundTableItem *> * vector;
};

SoundTable::SoundTable(QWidget * _parent) :
	QTableWidget(_parent),
	data(new SoundTablePrivate)
{
	setObjectName("SoundTable");
	horizontalHeader()->setObjectName("SoundTable");
	verticalHeader()->setVisible(false);
	horizontalHeader()->setSectionsClickable(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	horizontalHeader()->setStretchLastSection(true);
	setShowGrid(false);
	setAlternatingRowColors(true);
	setSelectionMode(QAbstractItemView::NoSelection);
	setFocusPolicy(Qt::NoFocus);

	data->vector = new QVector<SoundTableItem *>;
}

SoundTable::~SoundTable()
{
	delete data;
}

void SoundTable::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());
	XmlRead xmlRead;
	xmlRead.loadFile(_path);
	QDomElement root = xmlRead.rootElement();
	QDomElement element = root.firstChildElement();
	QDomElement node = element.firstChildElement();

	QStringList header;


	for (int i = 0; !node.isNull(); i++)
	{
		setColumnCount(i + 1);
		header << node.attribute("item");
		setColumnWidth(i, node.attribute("width").toInt());
		node = node.nextSiblingElement();
	}

	setHorizontalHeaderLabels(header);

	element = element.nextSiblingElement();
	node = element.firstChildElement();

	verticalHeader()->setDefaultSectionSize(element.attribute("height").toInt());

	SoundTableItem * item = nullptr;

	int row = 0;
	int column = 0;
	while (!node.isNull())
	{
		setRowCount(row + 1);

		item = new SoundTableItem;
		item->name.setObjectName("SoundTableLabel");
		item->name.setAlignment(Qt::AlignCenter);
		item->name.setText(node.attribute("name"));
		setCellWidget(row, column++, &item->name);

		QWidget * widget = new QWidget;
		QHBoxLayout * layout = new QHBoxLayout(widget);
		layout->setAlignment(Qt::AlignCenter);
		layout->setMargin(0);
		layout->addWidget(&item->slider);
		item->slider.setObjectName("SoundTableSlider");
		item->slider.setOrientation(Qt::Horizontal);
		item->slider.setRange(
			DataPool::externalDataMap()->value(node.attribute("data"))->minValue().toInt(),
			DataPool::externalDataMap()->value(node.attribute("data"))->maxValue().toInt());
		item->slider.setValue(DataPool::externalDataMap()->value(node.attribute("data"))->value().toInt());
		connect(&item->slider,
			SIGNAL(valueChanged(int)),
			DataPool::externalDataMap()->value(node.attribute("data")),
			SLOT(slotDataUpdate(int)));

		setCellWidget(row, column++, widget);

		item->value.setObjectName("SoundTableLabel");
		item->value.setAlignment(Qt::AlignCenter);
		item->value.setText("0");
		connect(DataPool::externalDataMap()->value(node.attribute("data")),
			SIGNAL(signalDataUpdate(int)),
			&item->value,
			SLOT(setNum(int)));
		setCellWidget(row, column++, &item->value);

		++row;
		column = 0;
		node = node.nextSiblingElement();
	}
}