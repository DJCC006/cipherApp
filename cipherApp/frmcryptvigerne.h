#ifndef FRMCRYPTVIGERNE_H
#define FRMCRYPTVIGERNE_H

#include <QDialog>
#include "cipherModule.h"

namespace Ui {
class frmcryptvigerne;
}

class frmcryptvigerne : public QDialog
{
    Q_OBJECT

public:
    explicit frmcryptvigerne(cipherModule* module, QWidget *parent = nullptr);
    ~frmcryptvigerne();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::frmcryptvigerne *ui;
    cipherModule* mModule;
};

#endif // FRMCRYPTVIGERNE_H
