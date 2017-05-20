#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QTabWidget>
#include <QPushButton>
#include "StandardDialog/StandardDialog.h"
#include "Control/BaseWidget.h"

class ConfigPage : public BaseWidget
{
public:
    ConfigPage(QWidget *parent = 0);
    virtual ~ConfigPage();
private:
    QTabWidget *m_pTabWidget;
};

class ConfigBottom : public BaseWidget
{
public:
    ConfigBottom(QWidget *parent);
    virtual ~ConfigBottom();

private:
    QPushButton *m_pOK;
    QPushButton *m_pCancle;
    QPushButton *m_pApply;
};

//设置界面,继承于StandardDialog
class ConfigDialog : public StandardDialog
{

public:
    ConfigDialog(QWidget *parent = 0);
    virtual ~ConfigDialog();

private:
    ConfigPage *m_pConfigPage;
    ConfigBottom *m_pConfigBottom;
};

#endif // CONFIGDIALOG_H
