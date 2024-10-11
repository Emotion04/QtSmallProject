#include "mdichild.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>

MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{
    //设置子窗口关闭时销毁这个类的对象
    setAttribute(Qt::WA_DeleteOnClose);

    //初始化isUntitled为true
    isUntitled=true;
}

void MdiChild::newFile()
{
    //设置窗口编号，因为编号要一直保存
    static int sequenceNumber=1;

    //新建文档没有被保存过
    isUntitled=true;

    curFile=tr("未命名文档%1.txt").arg(sequenceNumber++);

    //这个标题可以配合下面的槽函数里面的函数进行使用，可以进行*号的展示
    setWindowTitle(curFile+"[*]"+tr(" - 多文档编辑器"));

    connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法读取文件 %1：\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }

    //新建文本流对象
    QTextStream in(&file);
    //设置鼠标为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //读取文件的全部文本内容，并添加到编辑器中
    setPlainText(in.readAll());
    //恢复鼠标状态
    QApplication::restoreOverrideCursor();
    //设置当前文件
    setCurrentFile(fileName);
    connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);

    return true;
}

bool MdiChild::save()
{
    if(isUntitled){
        return saveAs();
    }
    else{
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty()){
        return false;
    }
    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法写入文件%1:\n%2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //以存文本文件写入
    out<<toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return QFileInfo(curFile).fileName();
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if(maybeSave()){
        event->accept();
    }
    else{
        event->ignore();
    }
}

void MdiChild::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu* menu=new QMenu;
    QAction* undo=menu->addAction(tr("撤销(&U)"),this,&MdiChild::undo,QKeySequence::Undo);
    undo->setEnabled(document()->isUndoAvailable());

    QAction* redo=menu->addAction(tr("恢复(&R)"),this,&MdiChild::redo,QKeySequence::Redo);
    redo->setEnabled(document()->isUndoAvailable());
    menu->addSeparator();

    QAction* cut=menu->addAction(tr("剪切(&T)"),this,&MdiChild::cut,QKeySequence::Cut);
    cut->setEnabled(textCursor().hasSelection());

    QAction* copy=menu->addAction(tr("复制(&T)"),this,&MdiChild::copy,QKeySequence::Copy);
    copy->setEnabled(textCursor().hasSelection());

    menu->addAction(tr("粘贴(&P)"),this,&MdiChild::paste,QKeySequence::Paste);
    QAction* clear=menu->addAction(tr("清空"),this,&MdiChild::clear);
    clear->setEnabled(!document()->isEmpty());
    menu->addSeparator();

    QAction* select=menu->addAction(tr("全选(&T)"),this,&MdiChild::selectAll,QKeySequence::SelectAll);
    select->setEnabled(!document()->isEmpty());

    menu->exec(e->globalPos());//获取鼠标位置，在这个位置显示菜单

    delete menu;


}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    if(document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr("是否保存对%1的更改？").arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);

        //添加按钮
        QPushButton* yesBtn=box.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton* canceBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);

        box.exec();

        if(box.clickedButton()==yesBtn){
            return save();
        }
        else if(box.clickedButton()==canceBtn)
            return false;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    //后面的函数可以去除路径中的符号连接"."和".."等符号
    curFile=QFileInfo(fileName).canonicalFilePath();
    //文档已经被保存过了
    isUntitled=false;
    //文档没有被更改过
    document()->setModified(false);
    //窗口不显示被更改标志
    setWindowModified(false);
    //设置窗口标题，userFriendlyCurrentFile()这个函数是返回文件名
    setWindowTitle(userFriendlyCurrentFile()+"[*]");
}
