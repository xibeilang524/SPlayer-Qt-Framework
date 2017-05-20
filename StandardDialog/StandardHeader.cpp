#include <QHBoxLayout>
#include <QPainter>
#include "StandardHeader.h"

StandardHeader::StandardHeader(QWidget *parent) : BaseWidget(parent)
{
    QImage image;
    m_pLogo = new SButton(this);
    image = QImage(":/Image/Resource/headicon.png");
    m_pLogo->AppendImage(image);
    m_pLogo->setFixedSize(image.width()/4,image.height());
    m_pTitle = new QLabel(this);
    m_pTitle->setMouseTracking(true);
    m_pSkin = new SButton(this);
    image = QImage(":/Image/Resource/headskin.png");
    m_pSkin->AppendImage(image);
    m_pSkin->setFixedSize(image.width()/4,image.height());
    m_pMin = new SButton(this);
    image = QImage(":/Image/Resource/headmin.png");
    m_pMin->AppendImage(image);
    m_pMin->setFixedSize(image.width()/4,image.height());
    m_pMax = new SButton(this);
    image = QImage(":/Image/Resource/headmax.png");
    m_pMax->AppendImage(image);
    m_pMax->setFixedSize(image.width()/4,image.height());
    m_pClose = new SButton(this);
    image = QImage(":/Image/Resource/headclose.png");
    m_pClose->AppendImage(image);
    m_pClose->setFixedSize(image.width()/4,image.height());

    CreateLayout();

    connect(m_pLogo,SIGNAL(Signal_Clicked()),this,SIGNAL(Signal_LogoClicked()));
    connect(m_pSkin,SIGNAL(Signal_Clicked()),this,SIGNAL(Signal_SkinClicked()));
    connect(m_pMin,SIGNAL(Signal_Clicked()),this,SIGNAL(Signal_MinClicked()));
    connect(m_pMax,SIGNAL(Signal_Clicked()),this,SIGNAL(Signal_MaxClicked()));
    connect(m_pClose,SIGNAL(Signal_Clicked()),this,SIGNAL(Signal_CloseClicked()));
}

StandardHeader::~StandardHeader()
{

}

void StandardHeader::SetLogoVisible(bool bVisible)
{
    m_pLogo->setVisible(bVisible);
}

void StandardHeader::SetTitleText(const QString &str)
{
    m_pTitle->setText(str);
}

void StandardHeader::SetTitleCenter(bool bCenter)
{
    if(bCenter)
    {
        m_pTitle->setAlignment(Qt::AlignCenter);
    }
    else
    {
        m_pTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }
}

void StandardHeader::SetSkinVisible(bool bVisible)
{
    m_pSkin->setVisible(bVisible);
}

void StandardHeader::SetMinVisible(bool bVisible)
{
    m_pMin->setVisible(bVisible);
}

void StandardHeader::SetMaxVisible(bool bVisible)
{
    m_pMax->setVisible(bVisible);
}

void StandardHeader::SetCloseVisible(bool bVisible)
{
    m_pClose->setVisible(bVisible);
}

void StandardHeader::SetMaxImage()
{
    m_pMax->ChangeImage(0,QImage(":/Image/Resource/headmax.png"));
}

void StandardHeader::SetRestoreImage()
{
    m_pMax->ChangeImage(0,QImage(":/Image/Resource/headrestore.png"));
}

void StandardHeader::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit Signal_MouseDoubleClicked();
    BaseWidget::mouseDoubleClickEvent(event);
}

void StandardHeader::CreateLayout()
{
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);
    pHBoxLayout->setContentsMargins(10,0,10,0);
    pHBoxLayout->setSpacing(10);
    pHBoxLayout->addWidget(m_pLogo);
    pHBoxLayout->addWidget(m_pTitle);
    pHBoxLayout->addWidget(m_pSkin);
    pHBoxLayout->addWidget(m_pMin);
    pHBoxLayout->addWidget(m_pMax);
    pHBoxLayout->addWidget(m_pClose);
}




