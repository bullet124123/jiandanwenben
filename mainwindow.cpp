#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QTextDocument>
#include <QTextCursor>
#include "finddialog.h"
#include "replacedialog.h"
#include "aboutdialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentFileName = "";
    // 默认不自动换行
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 新建
void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    currentFileName = "";
    this->setWindowTitle("简易文本编辑器");
}

// 打开
void MainWindow::on_actionOpen_triggered()
{
    QString fname = QFileDialog::getOpenFileName(this, "打开文件", "", "文本文件(*.txt);;所有文件(*.*)");
    if(fname.isEmpty()) return;
    QFile f(fname);
    if(!f.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,"错误","打开失败");
        return;
    }
    ui->plainTextEdit->setPlainText(f.readAll());
    f.close();
    currentFileName = fname;
    this->setWindowTitle(fname);
}

// 保存
void MainWindow::on_actionSave_triggered()
{
    if(currentFileName.isEmpty()){
        on_actionSaveAs_triggered();
        return;
    }
    QFile f(currentFileName);
    if(!f.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox::warning(this,"错误","保存失败");
        return;
    }
    f.write(ui->plainTextEdit->toPlainText().toUtf8());
    f.close();
    QMessageBox::information(this,"提示","保存成功");
}

// 另存为
void MainWindow::on_actionSaveAs_triggered()
{
    QString fname = QFileDialog::getSaveFileName(this, "另存为", "", "文本文件(*.txt);;所有文件(*.*)");
    if(fname.isEmpty()) return;
    QFile f(fname);
    if(!f.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox::warning(this,"错误","保存失败");
        return;
    }
    f.write(ui->plainTextEdit->toPlainText().toUtf8());
    f.close();
    currentFileName = fname;
    this->setWindowTitle(fname);
    QMessageBox::information(this,"提示","另存成功");
}

// 退出
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

// 自动换行（带勾选）
void MainWindow::on_actionAutoWrap_triggered(bool checked)
{
    if(checked){
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    }else{
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

// 字体
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok, ui->plainTextEdit->font(), this, "选择字体");
    if(ok){
        ui->plainTextEdit->setFont(f);
    }
}

// 字体颜色
void MainWindow::on_actionFontColor_triggered()
{
    QColor c = QColorDialog::getColor(Qt::black, this, "字体颜色");
    if(c.isValid()){
        QTextCharFormat fmt;
        fmt.setForeground(c);
        QTextCursor cur = ui->plainTextEdit->textCursor();
        if(cur.hasSelection()){
            cur.mergeCharFormat(fmt);
        }else{
            ui->plainTextEdit->setStyleSheet(QString("color:%1").arg(c.name()));
        }
    }
}

// 编辑器背景色
void MainWindow::on_actionEditorBg_triggered()
{
    QColor c = QColorDialog::getColor(Qt::white, this, "背景颜色");
    if(c.isValid()){
        ui->plainTextEdit->setStyleSheet(QString("background-color:%1").arg(c.name()));
    }
}

// 查找（使用自定义对话框，删掉原来QInputDialog版本）
void MainWindow::on_actionFind_triggered()
{
    FindDialog dlg(this, ui->plainTextEdit);
    dlg.exec();
}

// 替换（使用自定义对话框，删掉原来QInputDialog版本）
void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog dlg(this, ui->plainTextEdit);
    dlg.exec();
}

// 关于（使用自定义对话框，删掉原来QMessageBox版本）
void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}

// 撤销
void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}
// 重做
void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}
// 剪切
void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}
// 复制
void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}
// 粘贴
void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}
