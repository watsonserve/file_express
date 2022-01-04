#ifndef DIRCOLUMN_HPP
#define DIRCOLUMN_HPP

#include <QMouseEvent>
#include <QListView>
#include <QItemSelectionModel>

class DirColumn : public QListView
{
    Q_OBJECT
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
public:
    explicit DirColumn(QWidget *parent = nullptr);

signals:

};

#endif // DIRCOLUMN_HPP
