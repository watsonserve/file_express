#include "TabFrame.hpp"

TabFrame::TabFrame(QWidget *parent) : QTabWidget(parent)
{
    setTabBarAutoHide(true);
    setDocumentMode(true);
    setTabsClosable(true);
    setMovable(true);
    setAcceptDrops(true);
    setElideMode(Qt::TextElideMode::ElideMiddle);
    setUpdatesEnabled(true);
    setUsesScrollButtons(true);

    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

void TabFrame::closeTab(int idx)
{
    removeTab(idx);
}
