#include "mainventana.h"
#include "ui_mainventana.h"
#include "initialwindow.h"
#include "principalpanel.h"



mainventana::mainventana(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainventana)
{
    ui->setupUi(this);
}

mainventana::~mainventana()
{
    delete ui;
}

void mainventana::on_cesarBtt_clicked()
{
    auto w = new principalPanel();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_logoffBtt_clicked()
{
    auto w = new initialWindow();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

