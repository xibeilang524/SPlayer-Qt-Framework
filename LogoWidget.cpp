#include "LogoWidget.h"
#include <QPainter>

LogoWidget::LogoWidget(QWidget *parent):BaseWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    m_pOpenFile = new SButton(this);
    QImage image(":/Image/Resource/openfile.png");
    m_pOpenFile->setFixedHeight(image.height());
    m_pOpenFile->setFixedWidth(image.width()/4);
    m_pOpenFile->AppendImage(image);
}

LogoWidget::~LogoWidget()
{

}

void LogoWidget::SetLogoImage(const QString &imageFilePath)
{
    m_logoImage = QImage(imageFilePath);
    update();
}

void LogoWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawImage(QPoint(0,0),m_logoImage.scaled(size()));

    BaseWidget::paintEvent(event);
}

void LogoWidget::resizeEvent(QResizeEvent *event)
{
    m_pOpenFile->move(rect().center().x() - m_pOpenFile->width()/2,rect().center().y() + m_pOpenFile->height()+10);
    BaseWidget::resizeEvent(event);
}
