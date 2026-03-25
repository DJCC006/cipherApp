#ifndef FRMDECODEVIGERNE_H
#define FRMDECODEVIGERNE_H

#include <QDialog>
#include "cipherModule.h"
namespace Ui {
class frmdecodevigerne;
}

class frmdecodevigerne : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodevigerne(cipherModule* module, QWidget *parent = nullptr);
    ~frmdecodevigerne();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::frmdecodevigerne *ui;
    cipherModule* mModule;
};

#endif // FRMDECODEVIGERNE_H
