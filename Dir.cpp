#include "Dir.hpp"

Dir::Dir(QString &title, QWidget *parent) : QWidget(parent)
{
    label = new QLabel(title);
    list = new QListWidget();
    h_layout = new QHBoxLayout();
    v_layout = new QVBoxLayout();
    border_right = new QWidget();

    setMinimumWidth(200);
    setBaseSize(200, 600);
    setLayout(h_layout);
    setStyleSheet(QString("font-size: 16px"));

    h_layout->setContentsMargins(0, 0, 0, 0);
    h_layout->setSpacing(0);
    h_layout->addLayout(v_layout);
    h_layout->addWidget(border_right);

    border_right->setStyleSheet(QString("background: #222"));
    border_right->setFixedWidth(5);

    label->setStyleSheet(QString("padding: 0 4px; color:#fff; font-size: 12px"));
    label->setFixedHeight(20);

    v_layout->setContentsMargins(0, 0, 0, 0);
    v_layout->setSpacing(0);
    v_layout->addWidget(label);
    v_layout->addWidget(list);

    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->addItem(QString("abc"));
    list->setSelectionMode(QAbstractItemView::ExtendedSelection);
    list->setViewMode(QListView::ListMode);
    list->setFlow(QListView::TopToBottom);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Dir::~Dir()
{
    delete h_layout;
}
