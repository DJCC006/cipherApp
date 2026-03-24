#ifndef FRMDECODECESAR_H
#define FRMDECODECESAR_H

#include <QDialog>

namespace Ui {
class frmdecodecesar;
}

class frmdecodecesar : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodecesar(QWidget *parent = nullptr);
    ~frmdecodecesar();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmdecodecesar *ui;
};

#endif // FRMDECODECESAR_H
