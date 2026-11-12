#include "finddialog.h"
#include "ui_finddialog.h"
#include <QTextCursor>
#include <QMessageBox>

FindDialog::FindDialog(QWidget *parent, QPlainTextEdit *edit) :
    QDialog(parent),
    ui(new Ui::FindDialog),
    m_textEdit(edit)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

QTextDocument::FindFlags FindDialog::getFlags()
{
    QTextDocument::FindFlags flag;
    if(ui->checkCase->isChecked())
        flag |= QTextDocument::FindCaseSensitively;
    if(ui->checkWhole->isChecked())
        flag |= QTextDocument::FindWholeWords;
    return flag;
}

void FindDialog::on_btnFindNext_clicked()
{
    QString text = ui->lineEditFind->text();
    if(text.isEmpty()) return;
    bool ok = m_textEdit->find(text, getFlags());
    if(!ok)
    {
        QMessageBox::information(this, "提示", "已搜索到文档末尾！");
    }
}

void FindDialog::on_btnFindPrev_clicked()
{
    QString text = ui->lineEditFind->text();
    if(text.isEmpty()) return;
    bool ok = m_textEdit->find(text, getFlags() | QTextDocument::FindBackward);
    if(!ok)
    {
        QMessageBox::information(this, "提示", "已搜索到文档开头！");
    }
}

void FindDialog::on_btnClose_clicked()
{
    this->close();
}
