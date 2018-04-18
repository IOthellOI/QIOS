#include "faultIndex.h"
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

struct FaultIndexTableItem
{
	QLabel state;
	QLabel name;
	QTextEdit describe;
	QPushButton set;
	QPushButton add;
};

struct FaultIndex::FaultIndexPrivate
{
	QVBoxLayout * layout;
	QButtonGroup * buttonGroup;
	QStackedWidget * tableGroup;
	QVector<FaultIndexTableItem *> * vector;
};

FaultIndex::FaultIndex(QWidget * _parent) :
	QWidget(_parent),
	data(new FaultIndexPrivate)
{
	setObjectName("FaultIndex");
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	data->layout = new QVBoxLayout;
	data->layout->setMargin(0);
	data->layout->setSpacing(0);

	data->buttonGroup = new QButtonGroup;
	data->tableGroup = new QStackedWidget;
	data->vector = new QVector<FaultIndexTableItem *>;

	layout->addLayout(data->layout);
	layout->addWidget(data->tableGroup);

	connect(data->buttonGroup, SIGNAL(buttonClicked(int)), data->tableGroup, SLOT(setCurrentIndex(int)));
}

FaultIndex::~FaultIndex()
{
	delete data;
}

void FaultIndex::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());
	XmlRead xmlRead;
	xmlRead.loadFile(_path);
	
	QDomElement root = xmlRead.rootElement();
	QDomElement element = root.firstChildElement();
	QDomElement node = element.firstChildElement();
	QDomElement term = node.firstChildElement();
	
	QPushButton * button = nullptr;
	QTableWidget * table = nullptr;
	FaultIndexTableItem * item = nullptr;
	
	QStringList header;
	QVector<int> width;

	for (int i = 0; !node.isNull(); i++)
	{
		header << node.attribute("item");
		width.push_back(node.attribute("width").toInt());
		node = node.nextSiblingElement();
	}

	element = element.nextSiblingElement();
	node = element.firstChildElement();

	int buttonId = 0;
	while (!node.isNull())
	{
		button = new QPushButton;
		button->setObjectName("FaultIndexButton");
		button->setText(node.attribute("name"));
		button->setCheckable(true);
		button->setChecked(QVariant(node.attribute("checked")).toBool());
		data->layout->addWidget(button);
		data->buttonGroup->addButton(button, buttonId++);

		table = new QTableWidget;
		data->tableGroup->addWidget(table);
		table->setObjectName("FaultIndexTable");

		table->setObjectName("FaultIndexTable");
		table->horizontalHeader()->setObjectName("FaultIndex");
		table->verticalHeader()->setVisible(false);
		table->horizontalHeader()->setSectionsClickable(false);
		table->setEditTriggers(QAbstractItemView::NoEditTriggers);
		table->horizontalHeader()->setStretchLastSection(true);
		table->setShowGrid(false);
		table->setAlternatingRowColors(true);
		table->setSelectionMode(QAbstractItemView::NoSelection);
		table->setFocusPolicy(Qt::NoFocus);

		table->setColumnCount(width.count());
		table->setHorizontalHeaderLabels(header);
		table->verticalHeader()->setDefaultSectionSize(node.attribute("height").toInt());

		for (int i = 0; i < width.count(); i++)
		{
			table->setColumnWidth(i, width.at(i));
		}

		term = node.firstChildElement();

		int row = 0;
		int column = 0;
		while (!term.isNull())
		{
			table->setRowCount(row + 1);

			item = new FaultIndexTableItem;
			item->state.setObjectName("FaultIndexTableLabel");
			item->state.setAlignment(Qt::AlignCenter);
			item->state.setText(u8"未触发");
			table->setCellWidget(row, column++, &item->state);

			item->name.setObjectName("FaultIndexTableLabel");
			item->name.setAlignment(Qt::AlignCenter);
			item->name.setText(term.attribute("name"));
			table->setCellWidget(row, column++, &item->name);

			item->describe.setObjectName("FaultIndexTableTextEdit");
			item->describe.setReadOnly(true);
			item->describe.setText(term.attribute("describe"));
			table->setCellWidget(row, column++, &item->describe);

			QWidget * widget = new QWidget;
			QHBoxLayout * layout = new QHBoxLayout(widget);
			layout->addWidget(&item->set);
			item->set.setObjectName("FaultIndexTableButton");
			item->set.setText(u8"设置");
			table->setCellWidget(row, column++, widget);

			widget = new QWidget;
			layout = new QHBoxLayout(widget);
			layout->addWidget(&item->add);
			item->add.setObjectName("FaultIndexTableButton");
			item->add.setText(u8"加入");
			table->setCellWidget(row, column++, widget);
			
			row++;
			column = 0;
			term = term.nextSiblingElement();
		}
		node = node.nextSiblingElement();
	}
}
