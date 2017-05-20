#include "SButton.h"
#include <QPainter>
#include <QMouseEvent>

SButton::SButton(QWidget *parent):BaseWidget(parent)
{

}

SButton::~SButton()
{

}

void SButton::AppendImage(const QImage &image)
{
    m_listImage.append(image);
    update();
}

void SButton::ChangeImage(int index,const QImage &image)
{
    if(index >= m_listImage.size())
    {
        Q_ASSERT(false);
        return;
    }

    m_listImage[index] = image;

    update();
}

void SButton::mouseMoveEvent(QMouseEvent *event)
{
    BaseWidget::mouseMoveEvent(event);
    //event->accept();
}

void SButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    BaseWidget::mouseDoubleClickEvent(event);
    event->accept();
}

//按钮的不同状态，变换图片显示
void SButton::paintEvent(QPaintEvent *event)
{
    BaseWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    //nStateIndex 按钮状态表示
    int nStateIndex = -1;

    if(!isEnabled())
    {
        nStateIndex = 3; //Disable
    }
    else
    {
        if(m_bEnter)
        {
            nStateIndex = 1; //Enter
        }
        else if(m_bPress)
        {
            nStateIndex = 2; //Press
        }
        else
        {
            nStateIndex = 0; //Normal
        }
    }
    if(nStateIndex < 0 )
    {
        Q_ASSERT(false);
    }

    //一个状态用图片的1/4来显示
    int imageCount = m_listImage.size();

    for(int i=0; i<imageCount;++i)
    {
        QImage sourceImage = m_listImage.at(i);

        float fInterval = ((float)sourceImage.width())/4;

        QImage destImage = sourceImage.copy( fInterval*nStateIndex ,0,fInterval,sourceImage.height());

        int ptX =  (float(width()))/imageCount *i + ((float(width()))/imageCount-destImage.width())/2;

        int ptY = (height()-destImage.height())/2;
        //画图
        painter.drawImage(ptX,ptY,destImage);
    }

}
