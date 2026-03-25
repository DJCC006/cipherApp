#include "frmdecodecesar.h"
#include "ui_frmdecodecesar.h"
#include "frmchoosedesc.h"

frmdecodecesar::frmdecodecesar(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodecesar), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
}

frmdecodecesar::~frmdecodecesar()
{
    delete ui;
}

void frmdecodecesar::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

