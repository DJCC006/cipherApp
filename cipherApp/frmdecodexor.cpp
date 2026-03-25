#include "frmdecodexor.h"
#include "ui_frmdecodexor.h"
#include "frmchoosedesc.h"


frmdecodexor::frmdecodexor(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodexor), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
    ui->boxKey->setEnabled(false);
}

frmdecodexor::~frmdecodexor()
{
    delete ui;
}

void frmdecodexor::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

