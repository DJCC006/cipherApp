#include "frmchoosedesc.h"
#include "ui_frmchoosedesc.h"
#include "frmaccion.h"
#include "frmdecodecesar.h"
#include "frmdecodevigerne.h"
#include "frmdecodexor.h"


frmChooseDesc::frmChooseDesc(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmChooseDesc), mModule(module)
{
    ui->setupUi(this);
}

frmChooseDesc::~frmChooseDesc()
{
    delete ui;
}

void frmChooseDesc::on_logoffBtt_clicked()
{
    auto w= new frmaccion(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmChooseDesc::on_xorbtt_clicked()
{
    auto w= new frmdecodexor(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmChooseDesc::on_vigenerebtt_clicked()
{
    auto w= new frmdecodevigerne(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmChooseDesc::on_cesarBtt_clicked()
{
    auto w= new frmdecodecesar(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

