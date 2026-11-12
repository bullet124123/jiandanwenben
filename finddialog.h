#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>
namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QWidget *parent = nullptr, QPlainTextEdit *edit = nullptr);
    ~FindDialog();

private slots:
    void on_btnFindNext_clicked();
    void on_btnFindPrev_clicked();
    void on_btnClose_clicked();

private:
    Ui::FindDialog *ui;
    QPlainTextEdit *m_textEdit;
    QTextDocument::FindFlags getFlags();
};

#endif // FINDDIALOG_H
