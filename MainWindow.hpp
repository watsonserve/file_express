#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLayout>
#include <QStatusBar>
#include "api_signal.hpp"
#include "MenuBar.hpp"
#include "ToolBar.hpp"
#include "DirList.hpp"
#include "SidePanel.hpp"
#include "TabFrame.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QVBoxLayout *mainLayout;
    MenuBar *menuBar;
    ToolBar *toolBar;
    QStatusBar *statusBar;
    QWidget *content;
    SidePanel *aside;
    TabFrame *tabFrame;

protected slots:
    void api(enum ApiSignal act);
    void addTab(const QString &);
    void closeTab(int idx);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_HPP
