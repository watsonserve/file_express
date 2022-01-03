#include "ToolBar.hpp"

ToolBar::ToolBar(QWidget *parent) : QWidget(parent)
{
    h_layout = new QHBoxLayout(this);
    h_layout->setContentsMargins(0, 0, 0, 0);
    h_layout->setSpacing(0);

    back = new QPushButton(tr("back"));
    forward = new QPushButton(tr("forward"));
    input = new AddressInput();

    back->setStyleSheet("padding:0;background:transparent");

    h_layout->addWidget(back);
    h_layout->addWidget(forward);
    h_layout->addWidget(input);
//    setAllowedAreas(Qt::ToolBarArea::TopToolBarArea | Qt::ToolBarArea::BottomToolBarArea);
//    setFloatable(false);
}

ToolBar::~ToolBar()
{
    delete input;
    delete back;
    delete forward;
}
