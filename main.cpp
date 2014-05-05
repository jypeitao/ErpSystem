#include <QtGui/QApplication>
#include "mainwindow.h"
#include "logindialog.h"
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog loginDlg;
    QDesktopWidget *desk=QApplication::desktop();

    if(loginDlg.exec() == QDialog::Accepted)
    {
        w.move((desk->width() - w.width())/2,
                   (desk->height() - w.height())/2);
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
