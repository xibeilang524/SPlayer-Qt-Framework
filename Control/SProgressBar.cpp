#include "SProgressBar.h"
#include <QPainter>

SProgressBar::SProgressBar(QWidget *parent):BaseWidget(parent)
  ,m_currentProgress(0)
{

}

SProgressBar::~SProgressBar()
{

}

void SProgressBar::SetCurrentProgress(int currentProgress)
{
    m_currentProgress = currentProgress;

    update();
}

void SProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter objPainter(this);
    objPainter.setRenderHint(QPainter::Antialiasing);
    //绘背景
    objPainter.fillRect(rect(),QColor(31,31,31));
    //绘内容区背景
    objPainter.fillRect(contentsRect(),QColor(78,78,78));
    int nWidth = contentsRect().width() * m_currentProgress /100;
    //绘进度条背景;
    objPainter.fillRect(contentsRect().x(),contentsRect().y(),nWidth,contentsRect().height(),QColor(26,158,255));

    BaseWidget::paintEvent(event);
}
