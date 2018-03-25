#include "navigationButton.h"

#include <QImage>
#include <QEvent>

struct NavigationButton::NavigationButtonPrivate
{
	QIcon * icon[2];
	bool state;
};

NavigationButton::NavigationButton(QWidget * _parent) :
	QToolButton(_parent),
	data(new NavigationButtonPrivate)
{
	setObjectName("NavigationButton");
	
	setCheckable(true);

	installEventFilter(this);

	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	QToolButton::setIconSize(QSize(80, 80));

	data->icon[0] = new QIcon;
	data->icon[0]->setThemeName("one");
	data->icon[1] = new QIcon;
	data->icon[1]->setThemeName("two");
	data->state = true;
}

NavigationButton::~NavigationButton()
{
}

static QImage toGray(QImage image);

void NavigationButton::setIcon(const QIcon & _icon)
{
	*data->icon[0] = _icon;

	QPixmap pixmap = _icon.pixmap(80,80);
	QImage image = toGray(pixmap.toImage());
	pixmap = QPixmap::fromImage(image);
	*data->icon[1] = QIcon(pixmap);

	QToolButton::setIcon(*data->icon[0]);
}

bool NavigationButton::eventFilter(QObject * _object, QEvent *)
{
	if (_object == this)
	{
		if (isChecked() && !data->state)
		{
			QToolButton::setIcon(*data->icon[0]);
			data->state = true;
		}
		else if (!isChecked() && data->state)
		{
			QToolButton::setIcon(*data->icon[1]);
			data->state = false;
		}
	}
	return false;
}

QImage toGray(QImage image)
{
	int height = image.height();
	int width = image.width();
	QImage ret(width, height, QImage::Format_Indexed8);
	ret.setColorCount(256);
	for (int i = 0; i < 256; i++)
	{
		ret.setColor(i, qRgb(i, i, i));
	}
	switch (image.format())
	{
	case QImage::Format_Indexed8:
		for (int i = 0; i < height; i++)
		{
			const uchar *pSrc = (uchar *)image.constScanLine(i);
			uchar *pDest = (uchar *)ret.scanLine(i);
			memcpy(pDest, pSrc, width);
		}
		break;
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32:
	case QImage::Format_ARGB32_Premultiplied:
		for (int i = 0; i < height; i++)
		{
			const QRgb *pSrc = (QRgb *)image.constScanLine(i);
			uchar *pDest = (uchar *)ret.scanLine(i);

			for (int j = 0; j < width; j++)
			{
				pDest[j] = qGray(pSrc[j]);
			}
		}
		break;
	}
	return ret;
}