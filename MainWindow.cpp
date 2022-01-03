#include "MainWindow.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    menuBar = new MenuBar(this);
    statusBar = new QStatusBar(this);
    splitter = new QSplitter(this);
    aside = new SidePanel(this);
    content = new QWidget(this);
    mainLayout = new QVBoxLayout(content);
    toolBar = new ToolBar(content);
    tabFrame = new TabFrame(content);
    setBaseSize(800, 600);

    setWindowTitle(tr("file express"));

    // 菜单栏
    setMenuBar(menuBar);
    connect(menuBar, SIGNAL(click(ApiSignal)), this, SLOT(api(ApiSignal)));

    // 工具栏面板
//    addToolBar(Qt::ToolBarArea::LeftToolBarArea, aside);

//    // 状态栏
    setStatusBar(statusBar);

    // 主内容区
    setCentralWidget(splitter);
    splitter->addWidget(aside);
    splitter->addWidget(content);

    content->setLayout(mainLayout);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(tabFrame);

//    aside->setHidden(isShow);
    menuBar->setSidePanelStat(!aside->isHidden());
    addTab(tr("Home"));
}

void MainWindow::addTab(const QString &title)
{
    DirList *dirList = new DirList(tabFrame);
    tabFrame->addTab(dirList, title);
}

void MainWindow::closeTab(int idx)
{
    if (1 == tabFrame->count())
    {
        showMinimized();
        return;
    }
    tabFrame->removeTab(idx);
}

void MainWindow::api(enum ApiSignal act)
{
    bool isShow;
    DirList *dirList;

    switch (act)
    {
        case SHOW_SIDE_PANEL:
            isShow = !aside->isHidden();
            aside->setHidden(isShow);
            menuBar->setSidePanelStat(!isShow);
            break;
        case NEW_TAB:
            addTab(tr("Home"));
            break;
        case CLOSE_TAB:
            closeTab(tabFrame->currentIndex());
            break;
        case SELECT_ALL:
            dirList = (DirList *)tabFrame->currentWidget();
            dirList->selectAll();
            break;
        default:
            std::cout << act << std::endl;
            break;
    }
}

MainWindow::~MainWindow()
{
    delete menuBar;
    delete aside;
    delete statusBar;
    delete mainLayout;
    delete content;
}
