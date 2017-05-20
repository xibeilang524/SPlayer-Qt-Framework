#include "ConfigDialog.h"
#include <QVBoxLayout>

ConfigPage::ConfigPage(QWidget *parent):BaseWidget(parent)
{
    m_pTabWidget = new QTabWidget(this);
    BaseWidget *pNormalSetting = new BaseWidget();
    m_pTabWidget->addTab(pNormalSetting,tr("Normal Setting"));
    BaseWidget *pPlaySetting = new BaseWidget();
    m_pTabWidget->addTab(pPlaySetting,tr("Play Setting"));

    QVBoxLayout *pBoxLayout = new QVBoxLayout(this);
    pBoxLayout->setContentsMargins(0,0,0,0);
    pBoxLayout->setSpacing(0);

    QLabel *lineTop = new QLabel(this);
    lineTop->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    lineTop->setFixedHeight(1);
    QPalette palette = lineTop->palette();
    palette.setColor(QPalette::Background,QColor(37,36,41));
    lineTop->setPalette(palette);
    lineTop->setAutoFillBackground(true);
    pBoxLayout->addWidget(lineTop);
    pBoxLayout->addWidget(m_pTabWidget);
    QLabel *lineBottom = new QLabel(this);
    lineBottom->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    lineBottom->setFixedHeight(1);
    lineBottom->setPalette(palette);
    lineBottom->setAutoFillBackground(true);
    pBoxLayout->addWidget(lineBottom);
}

ConfigPage::~ConfigPage()
{

}

ConfigBottom::ConfigBottom(QWidget *parent):BaseWidget(parent)
{
    //OK按钮
    m_pOK = new QPushButton(tr("OK"),this);
    //Cancel按钮
    m_pCancle = new QPushButton(tr("Cancle"),this);
    //Apply按钮
    m_pApply = new QPushButton(tr("Apply"),this);
    //使用布局
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);
    pHBoxLayout->setContentsMargins(0,0,10,0);
    pHBoxLayout->setSpacing(10);
    pHBoxLayout->addStretch(1);
    pHBoxLayout->addWidget(m_pOK);
    pHBoxLayout->addWidget(m_pCancle);
    pHBoxLayout->addWidget(m_pApply);
}

ConfigBottom::~ConfigBottom()
{
}


ConfigDialog::ConfigDialog(QWidget *parent):StandardDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Background,QColor(55,58,65));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    //设置头部以及底部属性
    GetHeader()->SetTitleText(tr("Option"));
    GetHeader()->SetTitleCenter(false);
    GetHeader()->SetLogoVisible(false);
    GetHeader()->SetSkinVisible(false);
    GetHeader()->SetMinVisible(false);
    GetHeader()->SetMaxVisible(false);
    GetHeader()->GetBgColor().SetAllState(QColor(56,58,66));
    GetHeader()->setFixedHeight(40);
    GetBottom()->GetBgColor().SetAllState(QColor(56,58,66));
    GetBottom()->setFixedHeight(50);
    //设置为不能对窗口进行伸缩
    SetFixed(true);

    m_pConfigPage = new ConfigPage(this);

    SetCenterWidget(m_pConfigPage);

    m_pConfigBottom = new ConfigBottom(this);

    SetBottomWidget(m_pConfigBottom);
}

ConfigDialog::~ConfigDialog()
{

}
