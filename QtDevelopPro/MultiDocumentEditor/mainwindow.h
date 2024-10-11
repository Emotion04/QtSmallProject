#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QSignalMapper>
#include <QSettings>//提供平台无关的永久保存应用程序设置的方法
#include <QCloseEvent>
#include "mdichild.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event);


private slots:
    void on_actionNew_triggered();

    void updateMenus();//更新菜单

    MdiChild *createMdiChild();//创建子窗口

    void setActiveSubWindow(QWidget* window);//设置活动子窗口

    void on_actionOpen_triggered();

    void updateWindowMenu();//更新窗口菜单

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionClose_triggered();

    void on_actionCloseAll_triggered();

    void on_actionTile_triggered();

    void on_actionCascade_triggered();

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_actionExit_triggered();

    void showTextRowAndCol();//显示文本行号和列号
private:
    Ui::MainWindow *ui;

    QAction* actionSeparator;//间隔器
    MdiChild* activeMdiChild();//活动窗口

    QMdiSubWindow* findMdiChild(const QString &fileName);//查找子窗口

    QSignalMapper* windowMapper; //信号映射器

    void readSettings();//读取窗口位置
    void writeSettings();//写入窗口位置

    void initWindow(); //初始化窗口
};
#endif // MAINWINDOW_H
