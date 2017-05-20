#include "StandardBottom.h"

StandardBottom::StandardBottom(QWidget *parent):BaseWidget(parent)
{
    m_pHBoxLayout = new QHBoxLayout(this);
    m_pHBoxLayout->setContentsMargins(0,0,0,0);
    m_pHBoxLayout->setSpacing(0);
}

StandardBottom::~StandardBottom()
{

}

void StandardBottom::AddWidget(QWidget *pWidget)
{
    pWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pWidget->setMouseTracking(true);

    m_pHBoxLayout->addWidget(pWidget);
}
