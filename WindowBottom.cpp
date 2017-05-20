#include "WindowBottom.h"

//播放、停止等主界面底部视图的效果呈现
WindowBottom::WindowBottom(QWidget *parent):BaseWidget(parent)
{
    QImage image;
    m_pRunTimeLen = new QLabel(this);
    m_pRunTimeLen->setText("00:00:00");
    m_pRunTimeLen->setMouseTracking(true);
    m_pSign = new QLabel(this);
    m_pSign->setText("/");
    m_pTotalTimeLen = new QLabel(this);
    m_pTotalTimeLen->setText("00:00:00");
    //图片按钮
    m_pStop = new SButton(this);
    image = QImage(":/Image/Resource/stop.png");
    m_pStop->setFixedSize(image.width()/4,image.height());
    m_pStop->AppendImage(image);

    m_pPre = new SButton(this);
    image = QImage(":/Image/Resource/pre.png");
    m_pPre->setFixedSize(image.width()/4,image.height());
    m_pPre->AppendImage(image);

    m_PPaly = new SButton(this);
    image = QImage(":/Image/Resource/play.png");
    m_PPaly->setFixedSize(image.width()/4,image.height());
    m_PPaly->AppendImage(image);

    m_pNext = new SButton(this);
    image = QImage(":/Image/Resource/next.png");
    m_pNext->setFixedSize(image.width()/4,image.height());
    m_pNext->AppendImage(image);

    m_pSound = new SButton(this);
    image = QImage(":/Image/Resource/sound.png");
    m_pSound->setFixedSize(image.width()/4,image.height());
    m_pSound->AppendImage(image);

    m_pProgressBar = new SProgressBar(this);
    m_pProgressBar->setFixedSize(60,4);
    m_pProgressBar->SetCurrentProgress(50);

    m_pFull = new SButton(this);
    image = QImage(":/Image/Resource/full.png");
    m_pFull->setFixedSize(image.width()/4,image.height());
    m_pFull->AppendImage(image);

    //水平布局
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);
    pHBoxLayout->setContentsMargins(10,0,10,0);
    pHBoxLayout->setSpacing(0);
    //依次添加Stretch以及Widget
    pHBoxLayout->addStretch(1);
    pHBoxLayout->addWidget(m_pStop);
    pHBoxLayout->addSpacing(10);
    pHBoxLayout->addWidget(m_pPre);
    pHBoxLayout->addWidget(m_PPaly);
    pHBoxLayout->addWidget(m_pNext);
    pHBoxLayout->addSpacing(10);
    pHBoxLayout->addWidget(m_pSound);
    pHBoxLayout->addStretch(1);
}

WindowBottom::~WindowBottom()
{

}

//自动布局与手动布局结合方式
void WindowBottom::resizeEvent(QResizeEvent *event)
{
    int textWidth = QFontMetrics(font()).width("00:00:00");
    int textHeight = QFontMetrics(font()).height();

    m_pRunTimeLen->setGeometry(10,(height()-textHeight)/2,textWidth,textHeight);
    m_pSign->setGeometry(m_pRunTimeLen->geometry().right()+5,m_pRunTimeLen->y(),QFontMetrics(font()).width("/"),textHeight);
    m_pTotalTimeLen->setGeometry(m_pSign->geometry().right()+5,m_pRunTimeLen->y(),textWidth,textHeight);

    m_pProgressBar->move(m_pSound->geometry().right(),(height()-4)/2);
    m_pFull->move(geometry().right()-10-m_pFull->width(),(height()-m_pFull->height())/2);

    QWidget::resizeEvent(event);
}
