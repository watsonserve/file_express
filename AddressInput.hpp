#ifndef ADDRESSINPUT_HPP
#define ADDRESSINPUT_HPP

#include <QWidget>
#include <QLineEdit>
#include <QLayout>

class AddressInput : public QWidget
{
    Q_OBJECT

    QVBoxLayout *v_layout;
    QLineEdit *input;

public:
    explicit AddressInput(QWidget *parent = nullptr);
    virtual ~AddressInput();
};

#endif // ADDRESSINPUT_HPP
