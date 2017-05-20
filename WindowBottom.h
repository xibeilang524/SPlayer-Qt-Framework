#ifndef WINDOWBOTTOM_H
#define WINDOWBOTTOM_H

#include <QLabel>
#include "Control/SButton.h"
#include "Control/SProgressBar.h"
#include "Control/BaseWidget.h"

class WindowBottom : public BaseWidget
{
    Q_OBJECT

public:
    WindowBottom(QWidget *parent);
    virtual ~WindowBottom();

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    QLabel *m_pRunTimeLen;
    QLabel *m_pSign;
    QLabel *m_pTotalTimeLen;
    SButton *m_pStop;
    SButton *m_pPre;
    SButton *m_PPaly;
    SButton *m_pNext;
    SButton *m_pSound;
    SProgressBar *m_pProgressBar;
    SButton *m_pFull;
};

#endif // WINDOWBOTTOM_H
