#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMessageBox>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建间隔器动作并在其中设置间隔器
    actionSeparator=new QAction(this);
    actionSeparator->setSeparator(true);
    //更新菜单
    updateMenus();
    //当有活动窗口时更新菜单
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::updateMenus);

    //创建信号映射器
    windowMapper=new QSignalMapper(this);
    //映射器重新发送信号，根据信号设置活动窗口
    connect(windowMapper,SIGNAL(mapped(QWidget*)),this,SLOT(setActiveSubWindow(QWidget*)));
    //更新窗口菜单，并且设置当前窗口菜单将要显示的时候更新窗口菜单
    updateWindowMenu();
    connect(ui->menu_W,&QMenu::aboutToShow,this,&MainWindow::updateWindowMenu);

    readSettings();//初始化窗口时读取窗口设置信息
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //先执行多文档区域的关闭操作
    ui->mdiArea->closeAllSubWindows();

    //如果还有窗口没有关闭，侧忽略该事件
    if(ui->mdiArea->currentSubWindow()){
        event->ignore();
    }
    else{
        writeSettings();
        event->accept();
    }
}

void MainWindow::on_actionNew_triggered()
{
    MdiChild* child=createMdiChild();

    child->newFile();

    child->show();
}

void MainWindow::updateMenus()
{
    //根据是否有活动窗口来设置各个动作是否可用
    bool hasMdiChild=(activeMdiChild()!=0);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);

    //设置间隔器是否显示
    actionSeparator->setVisible(hasMdiChild);

    //有活动窗口且有被选择的文本，剪切复制才可用
    bool hasSelection=(activeMdiChild() && activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    //有活动窗口且文档有撤销操作使撤销动作可用
    ui->actionUndo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());
    //有活动窗口且文档有恢复操作时恢复动作可用
    ui->actionRedo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isRedoAvailable());
}

MdiChild *MainWindow::createMdiChild()
{
    //创建mdichild部件
    MdiChild* child=new MdiChild;
    ui->mdiArea->addSubWindow(child);

    //根据QTextEdit类的是否可以复制信号设置剪切赋值动作是否可用
    connect(child,&MdiChild::copyAvailable,ui->actionCut,&QAction::setEnabled);
    connect(child,&MdiChild::copyAvailable,ui->actionCopy,&QAction::setEnabled);

    //根据QTExtEdit类的是否可以撤销恢复信号设置撤销恢复动作是否可用
    connect(child,&MdiChild::undoAvailable,ui->actionUndo,&QAction::setEnabled);
    connect(child,&MdiChild::redoAvailable,ui->actionRedo,&QAction::setEnabled);

    connect(child,&MdiChild::cursorPositionChanged,this,&MainWindow::showTextRowAndCol);

    return child;
}

//将传递过来的窗口部件设置活动部件
void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));
}

MdiChild *MainWindow::activeMdiChild()
{
    //如果有活动窗口，则将其内的中心部件转换为mdiChild类型，没有侧直接返回0
    if(QMdiSubWindow* activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild*>(activeSubWindow->widget());
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath=QFileInfo(fileName).canonicalFilePath();
    //利用foreach语句遍历子窗口列表，如果其文件路径和要查找的路径相同，则返回该窗口
    foreach(QMdiSubWindow* window,ui->mdiArea->subWindowList()){
        MdiChild* mdiChild=qobject_cast<MdiChild*>(window->widget());
        if(mdiChild->currentFile()==canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::readSettings()
{
    QSettings settings("yafeilinux","myMdi");
    QPoint pos =settings.value("pos",QPoint(200,200)).toPoint();
    QSize size=settings.value("size",QSize(400,400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings("yafeilinux","myMdi");
    settings.setValue("pos",pos());
    settings.setValue("size",size());
}

void MainWindow::initWindow()
{
    setWindowTitle(tr("多文档编辑器"));

    ui->maintoolBar->setWindowTitle(tr("工具栏"));

    //设置滚动条
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"));

    QLabel *label=new QLabel(this);
    label->setFrameStyle(QFrame::Box |QFrame::Sunken);
    label->setText("多文档编辑器");

    label->setTextFormat(Qt::RichText);

    label->setOpenExternalLinks(true);//可以打开外部连接
    ui->statusbar->addPermanentWidget(label);
    ui->actionNew->setStatusTip(tr("创建一个文件"));
    //省略其他动作状态提示

}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this);

    if(!fileName.isEmpty()){
        QMdiSubWindow* existing=findMdiChild(fileName);

        //如果已经存在，则设置对应的子窗口设置为活动窗口
        if(existing){
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        //如果没有打开，创建子窗口
        MdiChild* child=createMdiChild();
        if(child->loadFile(fileName)){
            ui->statusbar->showMessage(tr("打开文件成功"),2000);
            child->show();
        }
        else{
            child->close();
        }
    }
}

void MainWindow::updateWindowMenu()
{
    //先清空菜单再添加各个菜单动作
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->actionClose);
    ui->menu_W->addAction(ui->actionCloseAll);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actionTile);
    ui->menu_W->addAction(ui->actionCascade);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->actionNext);
    ui->menu_W->addAction(ui->actionPrevious);
    ui->menu_W->addSeparator();

    //如果有活动窗口，则显示间隔器
    QList<QMdiSubWindow*> windows=ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());

    //遍历各个子窗口
    for(int i=0;i<windows.size();i++){
        MdiChild* child=qobject_cast<MdiChild*> (windows.at(i)->widget());
        QString text;
        //如果窗口小于9，则设置编号为快捷键
        if(i<9){
            text=tr("&%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }
        else {
            text=tr("%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }
        //添加动作到菜单，设置动作可以选择
        QAction* action=ui->menu_W->addAction(text);
        action->setCheckable(true);

        //设置当前窗口动作为选中状态
        action->setChecked(child==activeMdiChild());
        //关联动作的触发信号到信号映射器的map槽，这个槽会发射mapped信号
        connect(action,SIGNAL(triggered()),windowMapper,SLOT(map()));
        //将动作与相应窗口部件进行映射，在发射mapped信号是就会以这个窗口部件为参数
        windowMapper->setMapping(action,windows.at(i));
    }

}


void MainWindow::on_actionSave_triggered() // 保存菜单
{
    if(activeMdiChild() && activeMdiChild()->save())
        ui->statusbar->showMessage(tr("文件保存成功"),2000);
}

void MainWindow::on_actionSaveAs_triggered()  // 另存为菜单
{
    if(activeMdiChild() && activeMdiChild()->saveAs())
        ui->statusbar->showMessage(tr("文件保存成功"),2000);
}

void MainWindow::on_actionUndo_triggered() // 撤销菜单
{
    if(activeMdiChild()) activeMdiChild()->undo();
}

void MainWindow::on_actionRedo_triggered() // 恢复菜单
{
    if(activeMdiChild()) activeMdiChild()->redo();
}

void MainWindow::on_actionCut_triggered() // 剪切菜单
{
    if(activeMdiChild()) activeMdiChild()->cut();
}

void MainWindow::on_actionCopy_triggered() // 复制菜单
{
    if(activeMdiChild()) activeMdiChild()->copy();
}

void MainWindow::on_actionPaste_triggered() // 粘贴菜单
{
    if(activeMdiChild()) activeMdiChild()->paste();
}

void MainWindow::on_actionClose_triggered() // 关闭菜单
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionCloseAll_triggered() // 关闭所有窗口菜单
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actionTile_triggered() // 平铺菜单
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionCascade_triggered() // 层叠菜单
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actionNext_triggered() // 下一个菜单
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_actionPrevious_triggered() // 前一个菜单
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_actionAbout_triggered() // 关于菜单
{
    QMessageBox::about(this,tr("关于本软件"),tr("欢迎访问我们的网站：www.yafeilinux.com"));
}

void MainWindow::on_actionAboutQt_triggered() // 关于Qt菜单
{
    qApp->aboutQt(); // 这里的qApp是QApplication对象的全局指针，
        // 这行代码相当于QApplication::aboutQt();
}


void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void MainWindow::showTextRowAndCol()
{
    if(activeMdiChild()){
        int rowNum=activeMdiChild()->textCursor().blockNumber()+1;
        int colNum=activeMdiChild()->textCursor().columnNumber()+1;
        ui->statusbar->showMessage(tr("%1行 %2列").arg(rowNum).arg(colNum));
    }
}

