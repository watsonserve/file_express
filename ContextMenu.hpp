#ifndef CONTEXTMENU_HPP
#define CONTEXTMENU_HPP

#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QMenu>
#include <QSignalMapper>
#include <QModelIndex>
#include "api_signal.hpp"

class ContextMenu : public QObject
{
    Q_OBJECT
    QMenu *contextMenu[2];
    QSignalMapper *signalMap;
    QModelIndex idx;
    QAction *pasteAction;
private slots:
    void triggerSignal(int);
public:
    explicit ContextMenu(QWidget *parent = nullptr);
    virtual ~ContextMenu();
    void popup(int, const QPoint &, QModelIndex &);
signals:
    void trigger(enum ApiSignal, QModelIndex &);
};

#endif // CONTEXTMENU_HPP
