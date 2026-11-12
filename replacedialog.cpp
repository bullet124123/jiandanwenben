#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QTextCursor>
#include <QMessageBox>

ReplaceDialog::ReplaceDialog(QWidget *parent, QPlainTextEdit *edit) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog),
    m_textEdit(edit)
{
    ui->setupUi(this);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

QTextDocument::FindFlags ReplaceDialog::getFlags()
{
    QTextDocument::FindFlags flag;
    if(ui->checkCase->isChecked())
        flag |= QTextDocument::FindCaseSensitively;
    if(ui->checkWhole->isChecked())
        flag |= QTextDocument::FindWholeWords;
    return flag;
}

void ReplaceDialog::on_btnFindNext_clicked()
{
    QString text = ui->lineEditFind->text();
    if(text.isEmpty()) return;
    bool ok = m_textEdit->find(text, getFlags());
    if(!ok)
    {
        QMessageBox::information(this, "提示", "已搜索到文档末尾！");
    }
}

void ReplaceDialog::on_btnReplace_clicked()
{
    QTextCursor cursor = m_textEdit->textCursor();
    if(cursor.hasSelection())
    {
        cursor.insertText(ui->lineEditReplace->text());
        m_textEdit->setTextCursor(cursor);
    }
    on_btnFindNext_clicked();
}

void ReplaceDialog::on_btnReplaceAll_clicked()
{
    QString findStr = ui->lineEditFind->text();
    QString repStr = ui->lineEditReplace->text();
    if(findStr.isEmpty()) return;

    m_textEdit->moveCursor(QTextCursor::Start);
    int cnt = 0;
    while(m_textEdit->find(findStr, getFlags()))
    {
        QTextCursor cursor = m_textEdit->textCursor();
        cursor.insertText(repStr);
        m_textEdit->setTextCursor(cursor);
        cnt++;
    }
    QMessageBox::information(this, "替换完成", QString("一共替换了 %1 处").arg(cnt));
}

void ReplaceDialog::on_btnClose_clicked()
{
    this->close();
}
