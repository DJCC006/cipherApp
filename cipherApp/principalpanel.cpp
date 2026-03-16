#include "principalpanel.h"
#include "ui_principalpanel.h"
#include "mainventana.h"

principalPanel::principalPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::principalPanel)
{
    ui->setupUi(this);
}

principalPanel::~principalPanel()
{
    delete ui;
}

void principalPanel::on_pushButton_4_clicked()
{
    auto w = new mainventana();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

