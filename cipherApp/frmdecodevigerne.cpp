#include "frmdecodevigerne.h"
#include "ui_frmdecodevigerne.h"
#include "frmchoosedesc.h"

frmdecodevigerne::frmdecodevigerne(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodevigerne), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
    ui->boxKey->setEnabled(false);
}

frmdecodevigerne::~frmdecodevigerne()
{
    delete ui;
}

void frmdecodevigerne::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

