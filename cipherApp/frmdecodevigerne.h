#ifndef FRMDECODEVIGERNE_H
#define FRMDECODEVIGERNE_H

#include <QDialog>

namespace Ui {
class frmdecodevigerne;
}

class frmdecodevigerne : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodevigerne(QWidget *parent = nullptr);
    ~frmdecodevigerne();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmdecodevigerne *ui;
};

#endif // FRMDECODEVIGERNE_H
