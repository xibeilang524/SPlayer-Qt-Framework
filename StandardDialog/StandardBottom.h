#ifndef STANDARDBOTTOM_H
#define STANDARDBOTTOM_H

#include <QHBoxLayout>
#include "Control/BaseWidget.h"

//界面底部基类
class StandardBottom : public BaseWidget
{
public:
    explicit StandardBottom(QWidget *parent = 0);
    virtual ~StandardBottom();

public:
    void AddWidget(QWidget *pWidget);

public:
    QHBoxLayout *m_pHBoxLayout;
};

#endif // STANDARDBOTTOM_H
