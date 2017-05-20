#include "BaseWidget.h"
#include <QPainter>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
  ,m_margin(0,0,0,0)
  ,m_bEnter(false)
  ,m_bPress(false)
{
    setMouseTracking(true);
}

BaseWidget::~BaseWidget()
{

}

ObjectFourTuple<QColor> &BaseWidget::GetBgColor()
{
    return m_bgColor;
}

void BaseWidget::enterEvent(QEvent *event)
{
    //qDebug() << "BaseWidget::enterEvent";

    if(!m_bEnter)
    {
        ResetState();
        m_bEnter = true;
        update();
    }

    QWidget::enterEvent(event);
}

void BaseWidget::leaveEvent(QEvent *event)
{
    //qDebug() << "BaseWidget::leaveEvent";

    if(m_bEnter)
    {
        ResetState();
        update();
    }

    QWidget::leaveEvent(event);
}

void BaseWidget::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "BaseWidget::mousePressEvent";

    if(!m_bPress)
    {
        ResetState();
        m_bPress = true;
        update();
    }

    QWidget::mousePressEvent(event);
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
    //qDebug() << "BaseWidget::mouseReleaseEvent";

    if(m_bPress)
    {
        ResetState();
        update();
        emit Signal_Clicked();
    }

    QWidget::mouseReleaseEvent(event);
}

void BaseWidget::paintEvent(QPaintEvent *event)
{
    QColor  bgColor;
    QPen    borderPen;

    if(!isEnabled())
    {
        bgColor = m_bgColor.GetDisableState();
        borderPen = m_borderPen.GetDisableState();
    }
    else
    {
        if(m_bEnter)
        {
            bgColor = m_bgColor.GetOverState();
            borderPen = m_borderPen.GetOverState();
        }
        else if(m_bPress)
        {
            bgColor = m_bgColor.GetPressState();
            borderPen = m_borderPen.GetPressState();

        }
        else
        {
            bgColor = m_bgColor.GetNormalState();
            borderPen = m_borderPen.GetNormalState();
        }
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if(bgColor.isValid())
    {
        painter.fillRect(rect(),bgColor);
    }
    if(!m_margin.isNull())
    {
        painter.setPen(borderPen);
        painter.drawRect(rect().adjusted(m_margin.left(),m_margin.top(),-(m_margin.right()),-(m_margin.bottom())));
    }

    QWidget::paintEvent(event);
}

void BaseWidget::ResetState()
{
    m_bEnter = false;
    m_bPress = false;
}
