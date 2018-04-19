#include "faultBrowseTable.h"
#include "xmlRead.h"
#include "dataPool.h"

#include <cassert>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QVector>
#include <QVariant>
#include <QTextEdit>

struct FaultBrowseItem
{
	QLabel state;
	QLabel name;
	QTextEdit describe;
	QPushButton clean;
};

struct FaultBrowseTable::FaultBrowseTablePrivate
{
	QVector<FaultBrowseItem *> * vector;
};

FaultBrowseTable::FaultBrowseTable(QWidget * _parent) :
	QTableWidget(_parent),
	data(new FaultBrowseTablePrivate)
{
	setObjectName("FaultBrowseTable");
	horizontalHeader()->setObjectName("FaultBrowseTable");
	verticalHeader()->setVisible(false);
	horizontalHeader()->setSectionsClickable(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	horizontalHeader()->setStretchLastSection(true);
	setShowGrid(false);
	setAlternatingRowColors(true);
	setSelectionMode(QAbstractItemView::NoSelection);
	setFocusPolicy(Qt::NoFocus);

	data->vector = new QVector<FaultBrowseItem *>;
}

FaultBrowseTable::~FaultBrowseTable()
{
	delete data;
}

void FaultBrowseTable::loadConfig(const QString & _path)
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

	FaultBrowseItem * item = nullptr;

	int row = 0;
	int column = 0;

	while (!node.isNull())
	{
		setRowCount(row + 1);

		item = new FaultBrowseItem;

		item->state.setObjectName("FaultBrowseTableLabel");
		item->state.setAlignment(Qt::AlignCenter);
		item->state.setText(u8"Œ¥¥•∑¢");
		setCellWidget(row, column++, &item->state);

		item->name.setObjectName("FaultBrowseTableLabel");
		item->name.setAlignment(Qt::AlignCenter);
		item->name.setText(node.attribute("name"));
		setCellWidget(row, column++, &item->name);

		item->describe.setObjectName("FaultBrowseTableTextEdit");
		item->describe.setReadOnly(true);
		item->describe.setText(node.attribute("describe"));
		setCellWidget(row, column++, &item->describe);

		QWidget * widget = new QWidget;
		QHBoxLayout * layout = new QHBoxLayout(widget);
		layout->addWidget(&item->clean);
		item->clean.setObjectName("FaultBrowseTableButton");
		item->clean.setText(u8"…Ë÷√");
		setCellWidget(row, column++, widget);

		++row;
		column = 0;
		node = node.nextSiblingElement();
	}
}
