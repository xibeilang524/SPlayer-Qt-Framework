#ifndef SPROGRESSBAR_H
#define SPROGRESSBAR_H

#include "BaseWidget.h"

//进度条控件，总进度值为100
class SProgressBar : public BaseWidget
{
public:
    SProgressBar(QWidget *parent = 0);
    virtual ~SProgressBar();

public:
    //设置当前进度值，在0~100之间
    void SetCurrentProgress(int currentProgress);

protected:
    virtual void paintEvent(QPaintEvent *event);

public:
    int m_currentProgress;
};

#endif // SPROGRESSBAR_H
