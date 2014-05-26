#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materialdialog.h"
#include "orderdialog.h"
#include "newcustomerdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_khgl_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_kcgl_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_wxgl_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tb_kccx_clicked()
{
   //库存查询
   MaterialDialog ld;
   ld.exec();

}

void MainWindow::on_tb_xjrkd_clicked()
{
   //新建入库单
}

void MainWindow::on_tb_rkdcx_clicked()
{
    //入库单查询
}


void MainWindow::on_tb_new_customer_clicked()
{
   NewCustomerDialog ncdl;
   ncdl.exec();
}


void MainWindow::on_tb_xj_order_clicked()
{
    OrderDialog od;
    od.exec();
}
