#ifndef TABFRAME_HPP
#define TABFRAME_HPP

#include <QTabWidget>

class TabFrame : public QTabWidget
{
    Q_OBJECT
private slots:
    void closeTab(int idx);
public:
    explicit TabFrame(QWidget *parent = nullptr);
signals:

};

#endif // TABFRAME_HPP
