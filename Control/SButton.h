#ifndef SBUTTON_H
#define SBUTTON_H

#include "BaseWidget.h"

//特定的图片按钮控件抽象
class SButton : public BaseWidget
{
public:
    SButton(QWidget *parent = 0);
    virtual ~SButton();

    //增加以及替换图片
public:
    void AppendImage(const QImage &image);
    void ChangeImage(int index,const QImage &image);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private:
    QList<QImage> m_listImage;
};

#endif // SBUTTON_H
