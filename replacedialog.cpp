#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_btnFindNext_clicked()
{
    emit findNextSig(ui->editFind->text(), ui->radioDown->isChecked(), ui->chkCase->isChecked());
}

void ReplaceDialog::on_btnReplace_clicked()
{
    emit replaceSig(ui->editFind->text(), ui->editReplace->text(), ui->chkCase->isChecked());
}

void ReplaceDialog::on_btnReplaceAll_clicked()
{
    emit replaceAllSig(ui->editFind->text(), ui->editReplace->text(), ui->chkCase->isChecked());
}
