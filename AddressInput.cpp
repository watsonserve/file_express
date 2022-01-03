#include <QAction>
#include "AddressInput.hpp"

AddressInput::AddressInput(QWidget *parent) : QWidget(parent)
{
    v_layout = new QVBoxLayout();
    input = new QLineEdit();
    input->setFocusPolicy(Qt::StrongFocus);

    setLayout(v_layout);
    v_layout->addWidget(input);
}

AddressInput::~AddressInput()
{
    delete v_layout;
}
