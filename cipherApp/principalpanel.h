#ifndef PRINCIPALPANEL_H
#define PRINCIPALPANEL_H

#include <QDialog>

namespace Ui {
class principalPanel;
}

class principalPanel : public QDialog
{
    Q_OBJECT

public:
    explicit principalPanel(QWidget *parent = nullptr);
    ~principalPanel();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::principalPanel *ui;
};

#endif // PRINCIPALPANEL_H
