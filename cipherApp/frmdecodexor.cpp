#include "frmdecodexor.h"
#include "ui_frmdecodexor.h"
#include "frmchoosedesc.h"


frmdecodexor::frmdecodexor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodexor)
{
    ui->setupUi(this);
}

frmdecodexor::~frmdecodexor()
{
    delete ui;
}

void frmdecodexor::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

