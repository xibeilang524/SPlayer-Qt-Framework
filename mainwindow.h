#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWidget>
#include <QMenu>
#include "StandardDialog/StandardDialog.h"
#include "LogoWidget.h"
#include "Control/SProgressBar.h"
#include "Control/SButton.h"
#include "WindowBottom.h"
#include "ConfigDialog.h"

class MainWindow : public StandardDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //创建菜单
    void CreateMainMenu();
    //创建Logo视图
    void CreateLogoWidget(QWidget *parent);

protected:
    //覆盖resizeEvent函数，用于手动定位控件位置
    virtual void resizeEvent(QResizeEvent *event);

protected slots:
    virtual void Slot_LogoClicked();
    void Slot_OptionActToggled(bool);

    //控件成员
private:
    QOpenGLWidget *m_pCenterWidget;
    LogoWidget *m_pLogoWidget;
    SProgressBar *m_pProgressBar;
    SButton *m_pBackward;
    SButton *m_pForward;
    WindowBottom *m_pWindowBottom;
    QMenu *m_pMainMenu;
    ConfigDialog *m_pConfigDialog;
};
#endif // MAINWINDOW_H
