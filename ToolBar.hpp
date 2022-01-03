#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include <QWidget>
#include <QPushButton>
#include "AddressInput.hpp"

class ToolBar : public QWidget
{
    Q_OBJECT

    QHBoxLayout *h_layout;
    QPushButton *back;
    QPushButton *forward;
    AddressInput *input;

public:
    explicit ToolBar(QWidget *parent = nullptr);
    virtual ~ToolBar();
};

#endif // TOOLBAR_HPP
