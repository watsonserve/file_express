#include "clipboard.hpp"

ClipBoard::ClipBoard(QObject *parent) : QObject(parent)
{
    clip = QApplication::clipboard();
}

ClipBoard::~ClipBoard()
{
//    delete clip;
}
