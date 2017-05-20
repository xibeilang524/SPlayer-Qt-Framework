#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include "Control/BaseWidget.h"
#include "Control/SButton.h"

class LogoWidget : public BaseWidget
{
public:
    LogoWidget(QWidget *parent = 0);
    virtual ~LogoWidget();

public:
    void SetLogoImage(const QString &imageFilePath);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    QImage m_logoImage;
    SButton *m_pOpenFile;

};

#endif // LOGOWIDGET_H
