#ifndef PREVIEW_HPP
#define PREVIEW_HPP

#include <QWidget>
#include <QLabel>
#include <QFileInfo>
#include <QLayout>
#include <QIcon>
#include <QTableWidget>
#include <QHeaderView>

class Preview : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QTableWidget *table;
    QLabel *tp[6];
    QLabel *icon, *fileName, *desc;
public:
    explicit Preview(QWidget *parent = nullptr);
    virtual ~Preview();
    void setFileInfo(const QFileInfo &, const QIcon &);
signals:

};

#endif // PREVIEW_HPP
