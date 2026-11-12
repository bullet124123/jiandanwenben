#include "finddialog.h"
#include "ui_finddialog.h"
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
    if(!m_textEdit->find(text, getFlags()))
    {
        QMessageBox::information(this, "提示", "已搜索到末尾，没有找到！");
        m_textEdit->moveCursor(QTextCursor::Start);
    }
}

void FindDialog::on_btnFindPrev_clicked()
{
    QString text = ui->lineEditFind->text();
    if(text.isEmpty()) return;
    QTextDocument::FindFlags flag = getFlags();
    flag |= QTextDocument::FindBackward;
    if(!m_textEdit->find(text, flag))
    {
        QMessageBox::information(this, "提示", "已搜索到开头，没有找到！");
        m_textEdit->moveCursor(QTextCursor::End);
    }
}

void FindDialog::on_btnClose_clicked()
{
    this->close();
}
