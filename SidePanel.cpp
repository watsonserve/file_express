#include "SidePanel.hpp"

SidePanel::SidePanel(QWidget *parent) : QWidget(parent)
{
//    setAllowedAreas(Qt::ToolBarArea::LeftToolBarArea | Qt::ToolBarArea::RightToolBarArea);
//    setFloatable(false);
    setMinimumWidth(128);
    setBaseSize(128, parent->height());
    setStyleSheet(QString("background: #666"));
}
