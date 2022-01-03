#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSignalMapper>
#include "api_signal.hpp"

class MenuBar : public QMenuBar
{
    Q_OBJECT

    QSignalMapper *signalMap;
    QMenu *menus[6];
    QAction *sidePanelAction;

private slots:
    void triggerSignal(int);

public:
    explicit MenuBar(QWidget *parent = nullptr);
    virtual ~MenuBar();
    void setSidePanelStat(bool show);

signals:
    void click(enum ApiSignal);
};

#endif // MENUBAR_H
