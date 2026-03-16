#include "initialwindow.h"
#include "ui_initialwindow.h"
#include "mainventana.h"


initialWindow::initialWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::initialWindow)
{
    ui->setupUi(this);
}

initialWindow::~initialWindow()
{
    delete ui;
}

void initialWindow::on_signInbtt_clicked()
{
    auto w= new mainventana();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void initialWindow::on_salirBtt_clicked()
{
    close();
}

