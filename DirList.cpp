#include "DirList.hpp"
#include <stdlib.h>
#include <iostream>

DirList::DirList(QWidget *parent) : QColumnView(parent)
{
    dirModel = new DirModel(this);
    previewer = new Preview();
    contextMenu = new ContextMenu();

    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    // preview
    setPreviewWidget(previewer);
    setModel(dirModel);

    setAcceptDrops(true);
    setDragEnabled(true);
    setDragDropMode(InternalMove);
    setEditTriggers(SelectedClicked | EditKeyPressed);
    setFocusPolicy(Qt::FocusPolicy::WheelFocus);
    setSelectionBehavior(SelectRows);
    setSelectionMode(ExtendedSelection);
    setTabKeyNavigation(true);
    setTextElideMode(Qt::TextElideMode::ElideMiddle);

    itemSelectionModel = selectionModel();
    QString home = QDir::homePath();
    QModelIndex homeDirIdx = dirModel->index(home);
    dirModel->setRootPath(home);
    setRootIndex(homeDirIdx);

    connect(contextMenu, SIGNAL(trigger(enum ApiSignal, QModelIndex &)), this, SLOT(api(enum ApiSignal, QModelIndex &)));

    // preview
    connect(this, SIGNAL(updatePreviewWidget(QModelIndex)), this, SLOT(previewUpdated(QModelIndex)));

    // double click
    connect(this, SIGNAL(activated(QModelIndex)), this, SLOT(open(QModelIndex)));

    // context menu
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ctxMenu(QPoint)));

//    void selectionChanged    (const QItemSelection &selected, const QItemSelection &deselected);
//    void currentChanged      (const QModelIndex &current, const QModelIndex &previous);
//    void currentRowChanged   (const QModelIndex &current, const QModelIndex &previous);
//    void currentColumnChanged(const QModelIndex &current, const QModelIndex &previous);
    connect(itemSelectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(handleSelection(const QItemSelection &, const QItemSelection &)));
//    connect(itemSelectionModel, SIGNAL(currentColumnChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(handleChange(const QModelIndex &, const QModelIndex &)));
}

bool DirList::event(QEvent *ev)
{
//    std::cout << ev->type() << std::endl;
    return QColumnView::event(ev);
}

void DirList::handleSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QList<QModelIndex> addList, subList;
    QList<std::string> adds, subs;

    for (int i = 0; i < selected.length(); i++)
    {
        addList += selected[i].indexes();
    }

    for (int i = 0; i < deselected.length(); i++)
    {
        subList += deselected[i].indexes();
    }

    for (int i = 0; i < addList.length(); i++)
    {
        std::string filePath = dirModel->filePath(addList[i]).toStdString();
        if (-1 == ::find<std::string>(filePath, adds))
            adds.push_back(filePath);
    }

    for (int i = 0; i < subList.length(); i++)
    {
        std::string filePath = dirModel->filePath(subList[i]).toStdString();
        if (-1 == ::find<std::string>(filePath, subs))
            subs.push_back(filePath);
    }
    std::cout << "+: ";
    for (int i = 0; i < adds.length(); i++)
    {
        std::cout << adds[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-: ";
    for (int i = 0; i < subs.length(); i++)
    {
        std::cout << subs[i] << " ";
    }
    std::cout << std::endl;
}

void DirList::open(QModelIndex idx)
{
    dirModel->open(idx);
}

QModelIndexList DirList::selectedIndexes() const
{
    QModelIndexList ret, idxList = itemSelectionModel->selectedIndexes();
    QModelIndex parentDir = currentIndex().parent();
    for (int i = 0; i < idxList.length(); i++)
    {
        if (idxList[i].parent() == parentDir)
            ret.push_back(idxList[i]);
    }
    return ret;
}

void DirList::api(enum ApiSignal sig, QModelIndex &idx)
{
    QMimeData mime2;
    QModelIndexList idxList;
    idxList = this->selectedIndexes();

    switch (sig) {
    case CTX_OPEN:
        dirModel->open(idx);
        break;
    case CTX_RENAME:
        edit(idx);
        break;
    case CTX_COPY:
        dirModel->setClip(idxList);
        break;
    case CTX_PASTE:
        dirModel->paste(idx);
        break;
    case CTX_NEW_FILE:
        edit(dirModel->mkfile(idx, tr("New File")));
        break;
    case CTX_NEW_DIR:
        edit(dirModel->mkdir(idx, tr("New Folder")));
        break;
    case CTX_TRASH:
        dirModel->moveToTrash(idxList);
        break;
    default:
        break;
    }
}

void DirList::previewUpdated(QModelIndex idx)
{
    QFileInfo info = dirModel->fileInfo(idx);
    QIcon ico = dirModel->fileIcon(idx);
    previewer->setFileInfo(info, ico);
}

void DirList::ctxMenu(QPoint pos)
{
    QModelIndex idx = indexAt(pos);
    int valid = idx.isValid();
    // dir column
    if (!valid)
        idx = ((QListView *)(this->childAt(pos)->parentWidget()))->rootIndex();
    contextMenu->popup(valid, mapToGlobal(pos), idx);
}

QAbstractItemView * DirList::createColumn(const QModelIndex &index)
{
    DirColumn *view = new DirColumn(viewport());

    initializeColumn(view);

    view->setRootIndex(index);
    if (model()->canFetchMore(index))
        model()->fetchMore(index);

    return view;
}

DirList::~DirList()
{
    delete contextMenu;
    delete dirModel;
}
