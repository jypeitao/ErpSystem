#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_khgl_clicked();

    void on_kcgl_clicked();

    void on_wxgl_clicked();

    void on_tb_kccx_clicked();

    void on_tb_xjrkd_clicked();

    void on_tb_rkdcx_clicked();


    void on_tb_new_customer_clicked();


    void on_tb_xj_order_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
