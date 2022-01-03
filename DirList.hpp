#ifndef DIRLIST_HPP
#define DIRLIST_HPP

#include <QColumnView>
#include <QStandardPaths>
#include <QListView>
#include <QModelIndex>
#include "api_signal.hpp"
#include "DirModel.hpp"
#include "ContextMenu.hpp"
#include "Preview.hpp"

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
        if (-1 == ::find<QModelIndex>(src[i], ret)) ret.push_back(src[i]);
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

    bool event(QEvent *ev);

private slots:
    void previewUpdated(QModelIndex);
    void ctxMenu(QPoint);
    void api(enum ApiSignal, QModelIndex &);
    void open(QModelIndex);
    void handleSelection(const QItemSelection &, const QItemSelection &);
public:
    explicit DirList(QWidget *parent = nullptr);
    virtual ~DirList();
    virtual QModelIndexList selectedIndexes() const;

signals:

};

#endif // DIRLIST_HPP
