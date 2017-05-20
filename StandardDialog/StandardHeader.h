#ifndef STANDARDHEADER_H
#define STANDARDHEADER_H

#include <QLabel>
#include "Control/BaseWidget.h"
#include "Control/SButton.h"

class StandardHeader : public BaseWidget
{
    Q_OBJECT
public:
    explicit StandardHeader(QWidget *parent = 0);
    virtual ~StandardHeader();

public:
    void SetLogoVisible(bool bVisible);
    void SetTitleText(const QString &str);
    void SetTitleCenter(bool bCenter);
    void SetSkinVisible(bool bVisible);
    void SetMinVisible(bool bVisible);
    void SetMaxVisible(bool bVisible);
    void SetCloseVisible(bool bVisible);
    void SetMaxImage();
    void SetRestoreImage();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void Signal_LogoClicked();
    void Signal_SkinClicked();
    void Signal_MinClicked();
    void Signal_MaxClicked();
    void Signal_CloseClicked();
    void Signal_MouseDoubleClicked();

private:
    void CreateLayout();

private:
    SButton *m_pLogo;
    QLabel *m_pTitle;
    SButton *m_pSkin;
    SButton *m_pMin;
    SButton *m_pMax;
    SButton *m_pClose;
    QColor m_backgroundColor;
};

#endif // STANDARDHEADER_H
