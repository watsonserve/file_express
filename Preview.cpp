#include "Preview.hpp"

Preview::Preview(QWidget *parent) : QWidget(parent)
{
    setMinimumWidth(400);
    table = new QTableWidget(this);
    table->setRowCount(3);
    table->setColumnCount(2);
    table->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    table->setShowGrid(false);
    table->setStyleSheet("border:0; QTableWidget::Item {border-bottom: 1px solid #666}");
    table->setFocusPolicy(Qt::NoFocus);
    table->horizontalHeader()->setVisible(false);
    table->verticalHeader()->setVisible(false);

    for (int i = 0; i < 3; i++)
    {
        tp[i] = new QLabel();
        tp[i]->setStyleSheet(QString("text-align:left"));
    }
    for (int i = 3; i < 6; i++)
    {
        tp[i] = new QLabel();
        tp[i]->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        tp[i]->setMinimumWidth(200);
    }
    tp[0]->setText(tr("Create Time"));
    tp[1]->setText(tr("Update Time"));
    tp[2]->setText(tr("Access Time"));

    table->setCellWidget(0, 0, tp[0]);
    table->setCellWidget(1, 0, tp[1]);
    table->setCellWidget(2, 0, tp[2]);
    table->setCellWidget(0, 1, tp[3]);
    table->setCellWidget(1, 1, tp[4]);
    table->setCellWidget(2, 1, tp[5]);

    icon = new QLabel(this);
    fileName = new QLabel(this);
    fileName->setStyleSheet(QString("font-size: 20px;font-weight: 700"));

    desc = new QLabel(this);
    desc->setStyleSheet(QString("color: #666"));

    mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignBottom);
    mainLayout->addWidget(icon);
    mainLayout->addWidget(fileName);
    mainLayout->addWidget(desc);
    mainLayout->addWidget(table);
}

Preview::~Preview()
{
    delete mainLayout;
}

void Preview::setFileInfo(const QFileInfo &info, const QIcon &ico)
{
    QWidget *p = (QWidget *)parent();
    p->setMinimumWidth(440);
    icon->setPixmap(ico.pixmap(QSize(200, 200)));
    fileName->setText(info.fileName());
    desc->setText(QString::number(info.size()) + "B");
    tp[3]->setText(info.birthTime().toString());
    tp[4]->setText(info.lastModified().toString());
    tp[5]->setText(info.lastRead().toString());
}
