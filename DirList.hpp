#ifndef DIRLIST_HPP
#define DIRLIST_HPP

#include <QColumnView>
#include <QStandardPaths>
#include <QListView>
#include <QModelIndex>
#include <QMouseEvent>
#include "api_signal.hpp"
#include "DirModel.hpp"
#include "ContextMenu.hpp"
#include "Preview.hpp"
#include "DirColumn.hpp"

template<typename T>
int find(T &dst, QList<T> &pool)
{
    int off;
    for (off = pool.length() - 1; -1 < off && pool[off] != dst; off--);
    return off;
}

template<typename T>
QList<T> uniq(QList<T> &src)
{
    QList<T> ret;
    for (int i = 0; i < src.length(); i++)
    {
        if (-1 == ::find<T>(src[i], ret)) ret.push_back(src[i]);
    }
    return ret;
}

class DirList : public QColumnView
{
    Q_OBJECT

    DirModel *dirModel;
    ContextMenu *contextMenu;
    Preview *previewer;
    QItemSelectionModel *itemSelectionModel;

private slots:
    void previewUpdated(QModelIndex);
    void ctxMenu(QPoint);
    void api(enum ApiSignal, QModelIndex &);
    void open(QModelIndex);
    void handleSelection(const QItemSelection &, const QItemSelection &);
protected:
    QAbstractItemView *createColumn(const QModelIndex &) override;
    bool event(QEvent *ev) override;
public:
    explicit DirList(QWidget *parent = nullptr);
    virtual ~DirList();
    virtual QModelIndexList selectedIndexes() const override;

signals:

};

#endif // DIRLIST_HPP
