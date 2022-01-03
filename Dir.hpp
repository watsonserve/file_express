#ifndef DIR_HPP
#define DIR_HPP

#include <QLayout>
#include <QLabel>
#include <QListWidget>
#include <QStandardItem>

class Dir : public QWidget
{
    Q_OBJECT

    QLabel *label;
    QHBoxLayout *h_layout;
    QVBoxLayout *v_layout;
    QListWidget *list;
    QWidget *border_right;

public:
    explicit Dir(QString &title, QWidget *parent = nullptr);
    virtual ~Dir();

signals:

};

#endif // DIR_HPP
