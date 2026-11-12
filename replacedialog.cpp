#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QMessageBox>
#include <QTextCursor>

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
    QString findStr = ui->lineEditFind->text();
    if(findStr.isEmpty()) return;
    if(!m_textEdit->find(findStr, getFlags()))
    {
        QMessageBox::information(this, "提示", "找不到内容！");
        m_textEdit->moveCursor(QTextCursor::Start);
    }
}

void ReplaceDialog::on_btnReplace_clicked()
{
    QString findStr = ui->lineEditFind->text();
    QString repStr = ui->lineEditReplace->text();
    if(findStr.isEmpty()) return;

    QTextCursor cursor = m_textEdit->textCursor();
    if(cursor.hasSelection() && cursor.selectedText() == findStr)
    {
        cursor.insertText(repStr);
        m_textEdit->setTextCursor(cursor);
    }
    on_btnFindNext_clicked();
}

void ReplaceDialog::on_btnReplaceAll_clicked()
{
    QString findStr = ui->lineEditFind->text();
    QString repStr = ui->lineEditReplace->text();
    if(findStr.isEmpty()) return;
    int count = 0;
    m_textEdit->moveCursor(QTextCursor::Start);
    while(m_textEdit->find(findStr, getFlags()))
    {
        QTextCursor cur = m_textEdit->textCursor();
        cur.insertText(repStr);
        count++;
    }
    QMessageBox::information(this, "结果", QString("一共替换 %1 处").arg(count));
}

void ReplaceDialog::on_btnClose_clicked()
{
    this->close();
}
