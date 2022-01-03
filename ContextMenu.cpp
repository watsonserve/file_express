#include "ContextMenu.hpp"
#include <iostream>

ContextMenu::ContextMenu(QWidget *parent)
{
    contextMenu[0] = new QMenu(parent);
    contextMenu[1] = new QMenu(parent);
    signalMap = new QSignalMapper(parent);

    signalMap->setMapping(contextMenu[0]->addAction(tr("&New File"), signalMap, SLOT(map())), CTX_NEW_FILE);
    signalMap->setMapping(contextMenu[0]->addAction(tr("&New Folder"), signalMap, SLOT(map())), CTX_NEW_DIR);
    contextMenu[0]->addSeparator();
    signalMap->setMapping(contextMenu[0]->addAction(tr("&Info"), signalMap, SLOT(map())), CTX_INFO);
    contextMenu[0]->addSeparator();
    pasteAction = contextMenu[0]->addAction(tr("&Paste"), signalMap, SLOT(map()));
    signalMap->setMapping(pasteAction, CTX_PASTE);
    contextMenu[0]->addSeparator();
    signalMap->setMapping(contextMenu[0]->addAction(tr("&Open Terminal"), signalMap, SLOT(map())), CTX_TERMINAL);


    signalMap->setMapping(contextMenu[1]->addAction(tr("&Open"), signalMap, SLOT(map())), CTX_OPEN);
    contextMenu[0]->addSeparator();
    signalMap->setMapping(contextMenu[1]->addAction(tr("&Rename"), signalMap, SLOT(map())), CTX_RENAME);
    signalMap->setMapping(contextMenu[1]->addAction(tr("&Cut"), signalMap, SLOT(map())), CTX_CUT);
    signalMap->setMapping(contextMenu[1]->addAction(tr("&Copy"), signalMap, SLOT(map())), CTX_COPY);
    signalMap->setMapping(contextMenu[1]->addAction(tr("&Move to Trash"), signalMap, SLOT(map())), CTX_TRASH);

    connect(signalMap, SIGNAL(mappedInt(int)), this, SLOT(triggerSignal(int)));
}

ContextMenu::~ContextMenu()
{
    delete contextMenu[0];
    delete contextMenu[1];
    delete signalMap;
}

void ContextMenu::triggerSignal(int sig)
{
    emit trigger((enum ApiSignal)sig, idx);
}

void ContextMenu::popup(int idx, const QPoint &pos, QModelIndex &modelIdx)
{
    this->idx = modelIdx;
    if (!idx)
    {
        pasteAction->setDisabled(!QApplication::clipboard()->mimeData()->urls().size());
    }
    contextMenu[idx]->popup(pos);
}
