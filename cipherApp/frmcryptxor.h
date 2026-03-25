#ifndef FRMCRYPTXOR_H
#define FRMCRYPTXOR_H

#include <QDialog>
#include "cipherModule.h"

namespace Ui {
class frmcryptXOR;
}

class frmcryptXOR : public QDialog
{
    Q_OBJECT

public:
    explicit frmcryptXOR(cipherModule* module, QWidget *parent = nullptr);
    ~frmcryptXOR();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::frmcryptXOR *ui;
    cipherModule* mModule;
};

#endif // FRMCRYPTXOR_H
