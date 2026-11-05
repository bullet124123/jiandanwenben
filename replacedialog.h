#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

signals:
    void findNextSig(QString findStr,bool down,bool caseSensitive);
    void replaceSig(QString findStr,QString repStr,bool caseSensitive);
    void replaceAllSig(QString findStr,QString repStr,bool caseSensitive);

private slots:
    void on_btnFindNext_clicked();
    void on_btnReplace_clicked();
    void on_btnReplaceAll_clicked();

private:
    Ui::ReplaceDialog *ui;
};

#endif // REPLACEDIALOG_H
