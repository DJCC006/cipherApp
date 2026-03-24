#ifndef FRMCRYPTXOR_H
#define FRMCRYPTXOR_H

#include <QDialog>

namespace Ui {
class frmcryptXOR;
}

class frmcryptXOR : public QDialog
{
    Q_OBJECT

public:
    explicit frmcryptXOR(QWidget *parent = nullptr);
    ~frmcryptXOR();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmcryptXOR *ui;
};

#endif // FRMCRYPTXOR_H
