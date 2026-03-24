#ifndef FRMDECODEXOR_H
#define FRMDECODEXOR_H

#include <QDialog>

namespace Ui {
class frmdecodexor;
}

class frmdecodexor : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodexor(QWidget *parent = nullptr);
    ~frmdecodexor();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmdecodexor *ui;
};

#endif // FRMDECODEXOR_H
