#include "DirColumn.hpp"
#include <iostream>

DirColumn::DirColumn(QWidget *parent) : QListView(parent)
{
}

void DirColumn::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->position().toPoint();
    QModelIndex index = indexAt(pos);
    bool isEditing = state() == EditingState;
    QAbstractItemView::mouseReleaseEvent(event);

    if (isEditing || index.isValid()) return;

    emit clicked(this->rootIndex());
}
