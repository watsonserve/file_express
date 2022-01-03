#include "MenuBar.hpp"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    QString menuNames[] = { tr("&File"), tr("&Edit"), tr("&View"), tr("&Go"), tr("&Window"), tr("&Help") };
    signalMap = new QSignalMapper();
    QMenu *curr_menu;
    int i;

    for (i = 0; i < 6; i++)
    {
        curr_menu = addMenu(menuNames[i]);
        curr_menu->setParent(this);
        menus[i] = curr_menu;
    }

    // file menu

    signalMap->setMapping(menus[0]->addAction(tr("&New Tab"), signalMap, SLOT(map()), QKeySequence::StandardKey::AddTab), NEW_TAB);
    signalMap->setMapping(menus[0]->addAction(tr("&Close Tab"), signalMap, SLOT(map()), QKeySequence::StandardKey::Close), CLOSE_TAB);

    // eidt menu

    signalMap->setMapping(menus[1]->addAction(tr("&Undo"), signalMap, SLOT(map()), QKeySequence::StandardKey::Undo), UNDO);
    signalMap->setMapping(menus[1]->addAction(tr("&Redo"), signalMap, SLOT(map()), QKeySequence::StandardKey::Redo), REDO);
    menus[1]->addSeparator();
    signalMap->setMapping(menus[1]->addAction(tr("&Cut"), signalMap, SLOT(map()), QKeySequence::StandardKey::Cut), CUT);
    signalMap->setMapping(menus[1]->addAction(tr("&Copy"), signalMap, SLOT(map()), QKeySequence::StandardKey::Copy), COPY);
    signalMap->setMapping(menus[1]->addAction(tr("&Paste"), signalMap, SLOT(map()), QKeySequence::StandardKey::Paste), PASTE);
    signalMap->setMapping(menus[1]->addAction(tr("&Delete"), signalMap, SLOT(map()), QKeySequence::StandardKey::Delete), DELETE);
    signalMap->setMapping(menus[1]->addAction(tr("&Rename"), signalMap, SLOT(map()), QKeySequence::StandardKey::Delete), RENAME);
    menus[1]->addSeparator();
    signalMap->setMapping(menus[1]->addAction(tr("&Select All"), signalMap, SLOT(map()), QKeySequence::StandardKey::SelectAll), SELECT_ALL);

    // view menu

    sidePanelAction = menus[2]->addAction(tr("&Show Side Panel"), signalMap, SLOT(map()));
    sidePanelAction->setCheckable(true);
    sidePanelAction->setChecked(true);
    signalMap->setMapping(sidePanelAction, SHOW_SIDE_PANEL);

    connect(signalMap, SIGNAL(mappedInt(int)), this, SLOT(triggerSignal(int)));
}

void MenuBar::setSidePanelStat(bool isShow)
{
    sidePanelAction->setChecked(isShow);
}

void MenuBar::triggerSignal(int act)
{
    emit click((enum ApiSignal)(act));
}

MenuBar::~MenuBar()
{
    delete sidePanelAction;
    delete signalMap;
}
