#include "faultSettingPage.h"
#include "componentBox.h"

#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QRadioButton>

struct FaultSettingPage::FaultSettingPagePrivate
{
	QGridLayout * layout;
	ComponentBox * timeBox;
	ComponentBox * attitudeBox;
	ComponentBox * speedBox;
	QCheckBox * timeButton;
	QCheckBox * attitudeButton;
	QCheckBox * speedButton;
	QPushButton * okButton;

	QSpinBox * timeSetting;
	QSpinBox * attitudeSetting;
	QSpinBox * speedSetting;

	QRadioButton * attitudeGreater;
	QRadioButton * attitudeLess;
	QRadioButton * speedGreater;
	QRadioButton * speedLess;
};

FaultSettingPage::FaultSettingPage(QWidget * _parent) :
	QWidget(_parent),
	data(new FaultSettingPagePrivate)
{
	setMaximumWidth(300);
	setMinimumWidth(300);
	setObjectName("FaultSettingPage");
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

	data->layout = new QGridLayout(this);

	data->timeButton = new QCheckBox(u8"时间条件");
	data->timeButton->setObjectName("FaultSettingPageCheckBox");
	connect(data->timeButton, SIGNAL(clicked(bool)), this, SLOT(slotFrameShow(bool)));
	data->layout->addWidget(data->timeButton, 0, 0, 1, 1);

	data->attitudeButton = new QCheckBox(u8"高度条件");
	data->attitudeButton->setObjectName("FaultSettingPageCheckBox");
	connect(data->attitudeButton, SIGNAL(clicked(bool)), this, SLOT(slotFrameShow(bool)));
	data->layout->addWidget(data->attitudeButton, 0, 1, 1, 1);

	data->speedButton = new QCheckBox(u8"速度条件");
	data->speedButton->setObjectName("FaultSettingPageCheckBox");
	connect(data->speedButton, SIGNAL(clicked(bool)), this, SLOT(slotFrameShow(bool)));
	data->layout->addWidget(data->speedButton, 0, 2, 1, 1);

	data->timeBox = new ComponentBox;
	data->timeBox->setTitle(u8"时间条件");
	data->layout->addWidget(data->timeBox, 1, 0, 1, 3);
	data->timeBox->hide();
	QLabel * label = new QLabel(u8"延迟时间(s)");
	label->setObjectName("FaultSettingPageSpinBox");
	data->timeBox->addWidget(label, 0, 0, 1, 1);
	data->timeSetting = new QSpinBox;
	data->timeSetting->setObjectName("FaultSettingPageSpinBox");
	data->timeSetting->setRange(5, 1000);
	data->timeSetting->setValue(60);
	data->timeBox->addWidget(data->timeSetting, 0, 1, 1, 1);

	data->attitudeBox = new ComponentBox;
	data->attitudeBox->setTitle(u8"高度条件");
	data->layout->addWidget(data->attitudeBox, 2, 0, 1, 3);
	data->attitudeBox->hide();
	data->attitudeGreater = new QRadioButton(u8"大于高度(m)");
	data->attitudeGreater->setObjectName("FaultSettingPageRadioButton");
	data->attitudeBox->addWidget(data->attitudeGreater, 0, 0, 1, 1);
	data->attitudeLess = new QRadioButton(u8"小于高度(m)");
	data->attitudeLess->setObjectName("FaultSettingPageRadioButton");
	data->attitudeBox->addWidget(data->attitudeLess, 1, 0, 1, 1);
	data->attitudeSetting = new QSpinBox;
	data->attitudeSetting->setObjectName("FaultSettingPageSpinBox");
	data->attitudeSetting->setRange(-500, 25000);
	data->attitudeSetting->setValue(1000);
	data->attitudeBox->addWidget(data->attitudeSetting, 0, 1, 2, 1);
	
	data->speedBox = new ComponentBox;
	data->speedBox->setTitle(u8"速度条件");
	data->layout->addWidget(data->speedBox, 3, 0, 1, 3);
	data->speedBox->hide();
	data->speedGreater = new QRadioButton(u8"大于高度(m)");
	data->speedGreater->setObjectName("FaultSettingPageRadioButton");
	data->speedBox->addWidget(data->speedGreater, 0, 0, 1, 1);
	data->speedLess = new QRadioButton(u8"小于高度(m)");
	data->speedLess->setObjectName("FaultSettingPageRadioButton");
	data->speedBox->addWidget(data->speedLess, 1, 0, 1, 1);
	data->speedSetting = new QSpinBox;
	data->speedSetting->setObjectName("FaultSettingPageSpinBox");
	data->speedSetting->setRange(0, 1000);
	data->speedSetting->setValue(100);
	data->speedBox->addWidget(data->speedSetting, 0, 1, 2, 1);

	data->okButton = new QPushButton(u8"确定");
	data->okButton->setObjectName("FaultSettingPageButton");
	data->layout->addWidget(data->okButton, 4, 0, 1, 3);
}

FaultSettingPage::~FaultSettingPage()
{

}

void FaultSettingPage::slotFrameShow(bool _show)
{
	if (dynamic_cast<QCheckBox *>(sender())->text() == data->timeBox->title())
	{
		if (_show)
		{
			data->timeBox->show();
		}
		else
		{
			data->timeBox->hide();
		}
	}
	else if (dynamic_cast<QCheckBox *>(sender())->text() == data->attitudeBox->title())
	{
		if (_show)
		{
			data->attitudeBox->show();
		}
		else
		{
			data->attitudeBox->hide();
		}
	}
	else if (dynamic_cast<QCheckBox *>(sender())->text() == data->speedBox->title())
	{
		if (_show)
		{
			data->speedBox->show();
		}
		else
		{
			data->speedBox->hide();
		}
	}
	adjustSize();
}
