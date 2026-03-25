#ifndef FRMDECODEXOR_H
#define FRMDECODEXOR_H

#include <QDialog>
#include "cipherModule.h"

namespace Ui {
class frmdecodexor;
}

class frmdecodexor : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodexor(cipherModule* module, QWidget *parent = nullptr);
    ~frmdecodexor();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmdecodexor *ui;
    cipherModule* mModule;
};

#endif // FRMDECODEXOR_H
