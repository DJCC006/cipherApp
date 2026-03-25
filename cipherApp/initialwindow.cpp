#include "initialwindow.h"
#include "ui_initialwindow.h"
#include "mainventana.h"
#include "frmaccion.h"


initialWindow::initialWindow(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::initialWindow), mModule(module)
{
    ui->setupUi(this);
}

initialWindow::~initialWindow()
{
    delete ui;
}

void initialWindow::on_signInbtt_clicked()
{
    auto w= new frmaccion(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void initialWindow::on_salirBtt_clicked()
{
    delete mModule;
    mModule=nullptr;
    close();
}

