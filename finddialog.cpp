#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_btnFindNext_clicked()
{
    QString text = ui->editFind->text();
    bool down = ui->radioDown->isChecked();
    bool caseSensitive = ui->chkCase->isChecked();
    emit findNext(text,down,caseSensitive);
}
