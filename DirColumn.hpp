#ifndef DIRCOLUMN_HPP
#define DIRCOLUMN_HPP

#include <QAbstractItemView>

class DirColumn : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit DirColumn(QWidget *parent = nullptr);

signals:

};

#endif // DIRCOLUMN_HPP
