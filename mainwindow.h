#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QTextDocument>
#include <QTextCursor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();

    void on_actionAutoWrap_triggered(bool checked);
    void on_actionFont_triggered();
    void on_actionFontColor_triggered();
    void on_actionEditorBg_triggered();

    void on_actionFind_triggered();
    void on_actionReplace_triggered();
    void on_actionAbout_triggered();

    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFileName;
};

#endif // MAINWINDOW_H
