#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include <QToolBar>
#include <QPushButton>
#include "AddressInput.hpp"

class ToolBar : public QToolBar
{
    Q_OBJECT

    QPushButton *back;
    QPushButton *forward;
    AddressInput *input;

public:
    explicit ToolBar(QWidget *parent = nullptr);
    virtual ~ToolBar();
};

#endif // TOOLBAR_HPP
