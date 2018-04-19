#include "commonFaultTable.h"
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

struct CommonFaultItem
{
	QLabel state;
	QLabel name;
	QTextEdit describe;
	QPushButton set;
	QPushButton take;
};

struct CommonFaultTable::CommonFaultTablePrivate
{
	QVector<CommonFaultItem *> * vector;
};

CommonFaultTable::CommonFaultTable(QWidget * _parent) :
	QTableWidget(_parent),
	data(new CommonFaultTablePrivate)
{
	setObjectName("CommonFaultTable");
	horizontalHeader()->setObjectName("CommonFaultTable");
	verticalHeader()->setVisible(false);
	horizontalHeader()->setSectionsClickable(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	horizontalHeader()->setStretchLastSection(true);
	setShowGrid(false);
	setAlternatingRowColors(true);
	setSelectionMode(QAbstractItemView::NoSelection);
	setFocusPolicy(Qt::NoFocus);

	data->vector = new QVector<CommonFaultItem *>;
}

CommonFaultTable::~CommonFaultTable()
{
	delete data;
}

void CommonFaultTable::loadConfig(const QString & _path)
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

	CommonFaultItem * item = nullptr;

	int row = 0;
	int column = 0;

	while (!node.isNull())
	{
		setRowCount(row + 1);

		item = new CommonFaultItem;

		item->state.setObjectName("CommonFaultTableLabel");
		item->state.setAlignment(Qt::AlignCenter);
		item->state.setText(u8"Î´´¥·¢");
		setCellWidget(row, column++, &item->state);

		item->name.setObjectName("CommonFaultTableLabel");
		item->name.setAlignment(Qt::AlignCenter);
		item->name.setText(node.attribute("name"));
		setCellWidget(row, column++, &item->name);

		item->describe.setObjectName("CommonFaultTableTextEdit");
		item->describe.setReadOnly(true);
		item->describe.setText(node.attribute("describe"));
		setCellWidget(row, column++, &item->describe);

		QWidget * widget = new QWidget;
		QHBoxLayout * layout = new QHBoxLayout(widget);
		layout->addWidget(&item->set);
		item->set.setObjectName("CommonFaultTableButton");
		item->set.setText(u8"ÉèÖÃ");
		setCellWidget(row, column++, widget);

		widget = new QWidget;
		layout = new QHBoxLayout(widget);
		layout->addWidget(&item->take);
		item->take.setObjectName("CommonFaultTableButton");
		item->take.setText(u8"ÒÆ³ý");
		setCellWidget(row, column++, widget);

		++row;
		column = 0;
		node = node.nextSiblingElement();
	}
}
