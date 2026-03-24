#include "frmdecodecesar.h"
#include "ui_frmdecodecesar.h"
#include "frmchoosedesc.h"

frmdecodecesar::frmdecodecesar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodecesar)
{
    ui->setupUi(this);
}

frmdecodecesar::~frmdecodecesar()
{
    delete ui;
}

void frmdecodecesar::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

