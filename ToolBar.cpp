#include "ToolBar.hpp"

ToolBar::ToolBar(QWidget *parent) : QToolBar(parent)
{
    back = new QPushButton(tr("back"));
    forward = new QPushButton(tr("forward"));
    input = new AddressInput();

    back->setStyleSheet("padding:0;background:transparent");

    addWidget(back);
    addWidget(forward);
    addWidget(input);
    setFloatable(false);
    setAllowedAreas(Qt::ToolBarArea::TopToolBarArea | Qt::ToolBarArea::BottomToolBarArea);
}

ToolBar::~ToolBar()
{
    delete input;
    delete back;
    delete forward;
}
