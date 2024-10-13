/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionTile;
    QAction *actionCascade;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actioncontact_ZJH_for_help;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *maintoolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(579, 447);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon2);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/saveAs.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveAs->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon4);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRedo->setIcon(icon6);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCut->setIcon(icon7);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/paste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPaste->setIcon(icon9);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionCloseAll = new QAction(MainWindow);
        actionCloseAll->setObjectName("actionCloseAll");
        actionTile = new QAction(MainWindow);
        actionTile->setObjectName("actionTile");
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName("actionCascade");
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName("actionNext");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNext->setIcon(icon10);
        actionPrevious = new QAction(MainWindow);
        actionPrevious->setObjectName("actionPrevious");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/previous.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPrevious->setIcon(icon11);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbout->setIcon(icon12);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName("actionAboutQt");
        actioncontact_ZJH_for_help = new QAction(MainWindow);
        actioncontact_ZJH_for_help->setObjectName("actioncontact_ZJH_for_help");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 579, 20));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu_E = new QMenu(menubar);
        menu_E->setObjectName("menu_E");
        menu_W = new QMenu(menubar);
        menu_W->setObjectName("menu_W");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        maintoolBar = new QToolBar(MainWindow);
        maintoolBar->setObjectName("maintoolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, maintoolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addSeparator();
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAs);
        menu_F->addSeparator();
        menu_F->addAction(actionExit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addSeparator();
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_W->addAction(actionClose);
        menu_W->addAction(actionCloseAll);
        menu_W->addSeparator();
        menu_W->addAction(actionTile);
        menu_W->addAction(actionCascade);
        menu_W->addSeparator();
        menu_W->addAction(actionNext);
        menu_W->addAction(actionPrevious);
        menu_H->addAction(actionAbout);
        menu_H->addAction(actionAboutQt);
        menu_H->addAction(actioncontact_ZJH_for_help);
        maintoolBar->addAction(actionNew);
        maintoolBar->addAction(actionOpen);
        maintoolBar->addSeparator();
        maintoolBar->addAction(actionSave);
        maintoolBar->addAction(actionSaveAs);
        maintoolBar->addSeparator();
        maintoolBar->addAction(actionCut);
        maintoolBar->addAction(actionCopy);
        maintoolBar->addAction(actionPaste);
        maintoolBar->addSeparator();
        maintoolBar->addAction(actionPrevious);
        maintoolBar->addAction(actionNext);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "new file(&N)", nullptr));
        actionNew->setIconText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "open file(&D)", nullptr));
        actionOpen->setIconText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\346\241\243(D)", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\346\241\243(D)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "save(&S)", nullptr));
        actionSave->setIconText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "saveAs(&A)", nullptr));
        actionSaveAs->setIconText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveAs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "exit(&X)", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo(&U)", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo(&E)", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut(&T)", nullptr));
        actionCut->setIconText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(T)", nullptr));
#if QT_CONFIG(tooltip)
        actionCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(T)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy(&C)", nullptr));
        actionCopy->setIconText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#if QT_CONFIG(tooltip)
        actionCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste(&P)", nullptr));
        actionPaste->setIconText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(P)", nullptr));
#if QT_CONFIG(tooltip)
        actionPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(P)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close(&O)", nullptr));
        actionCloseAll->setText(QCoreApplication::translate("MainWindow", "CloseAll(&A)", nullptr));
        actionTile->setText(QCoreApplication::translate("MainWindow", "Tile(&T)", nullptr));
        actionCascade->setText(QCoreApplication::translate("MainWindow", "Cascade(&C)", nullptr));
        actionNext->setText(QCoreApplication::translate("MainWindow", "Next(&X)", nullptr));
        actionNext->setIconText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(X)", nullptr));
#if QT_CONFIG(tooltip)
        actionNext->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(X)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNext->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrevious->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252(V)", nullptr));
        actionPrevious->setIconText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252(V)", nullptr));
#if QT_CONFIG(shortcut)
        actionPrevious->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "about(&A)", nullptr));
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "aboutQt(&Q)", nullptr));
        actioncontact_ZJH_for_help->setText(QCoreApplication::translate("MainWindow", "contact ZJH for help", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_W->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243(&W)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        maintoolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
