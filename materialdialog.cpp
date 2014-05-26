#include "materialdialog.h"
#include "ui_materialdialog.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
MaterialDialog::MaterialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaterialDialog)
{
    ui->setupUi(this);
    createTableMode();
        std::cout<<"ddd"<<std::endl;
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

}

MaterialDialog::~MaterialDialog()
{
        std::cout<<"xxx"<<std::endl;
   // ui->tableView->
    delete model;
    delete ui;
}
void MaterialDialog::createTableMode()
{
    model = new QSqlTableModel(this);
    model->setTable("material");
 //   model->setFilter(QObject::tr("name like '%好%'"));
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    connect(model,SIGNAL(dataChanged(const QModelIndex & , const QModelIndex & )),this,SLOT(dataChanged(const QModelIndex &, const QModelIndex &)));
    ui->tableView->setModel(model);
}


void MaterialDialog::on_ph_cx_clicked()
{
//    model->setSort(1,Qt::DescendingOrder);

    QString str = ui->cxtj->text();


    QString name = "name like '%"+str+"%'";
    QString supplier = "supplier like '%"+str+"%'";
    QString id = "product_id like '%"+str+"%'";

    QString ft = "(" +name
                     +" or "
                     + supplier
                     +" or "
                     + id +
                 ")";


    //model->setFilter(QObject::tr("name like '%好%'"));

    std::cout<<ft.toUtf8().data()<<std::endl;
    model->setFilter(ft);
    model->select();

}
void MaterialDialog::dataChanged(const QModelIndex &lt, const QModelIndex &rb)
{
    std::cout<<"changed"<<std::endl;
    //std::cout<<"dirty = "<<model->isDirty(lt)<<std::endl;
    //std::cout<<"dirty = "<<model->isDirty(rb)<<std::endl;

    ui->bcxg->setEnabled(true);
    ui->cxxg->setEnabled(true);
}


void MaterialDialog::on_bcxg_clicked()
{
   // QTextCodec*pCodec=QTextCodec::codecForName("System");//获取系统字体编码
   // QTextCodec::setCodecForLocale(pCodec);
   // QTextCodec::setCodecForCStrings(pCodec);
   // QTextCodec::setCodecForTr(pCodec);
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    int ret = QMessageBox::question(this,QObject::tr("确认保存"),QObject::tr("是否确认保存修改"), QObject::tr("取消"), QObject::tr("确定"));

    std::cout<<"box select "<<ret<<std::endl;
    if(ret == 1)
    {
        model->database().transaction(); //开始事务操作
        if (model->submitAll()) // 提交所有被修改的数据到数据库中
        {
            model->database().commit(); //提交成功，事务将真正修改数据库数据
            QMessageBox::information(this, QObject::tr("提示信息"),QObject::tr("保存成功"), QObject::tr("确定"));
        } else {
            model->database().rollback(); //提交失败，事务回滚
            QMessageBox::warning(this, tr("提示信息"),tr("保存失败 数据库错误: %1").arg(model->lastError().text()),QObject::tr("确定"));
           QSqlError error = model->lastError();
           error.text();
            //QMessageBox::warning(this, tr("tableModel"),tr("数据库错误:"));
        }

        model->submitAll();
    }
}

void MaterialDialog::on_cxxg_clicked()
{

    model->revertAll();
    ui->bcxg->setEnabled(false);
    ui->cxxg->setEnabled(false);
}
