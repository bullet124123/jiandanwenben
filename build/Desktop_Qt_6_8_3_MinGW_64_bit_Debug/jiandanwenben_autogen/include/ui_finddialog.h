/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditFind;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkCase;
    QCheckBox *checkWhole;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnFindNext;
    QPushButton *btnFindPrev;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        FindDialog->resize(230, 86);
        widget = new QWidget(FindDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 226, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEditFind = new QLineEdit(widget);
        lineEditFind->setObjectName("lineEditFind");

        horizontalLayout->addWidget(lineEditFind);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        checkCase = new QCheckBox(widget);
        checkCase->setObjectName("checkCase");

        horizontalLayout_2->addWidget(checkCase);

        checkWhole = new QCheckBox(widget);
        checkWhole->setObjectName("checkWhole");

        horizontalLayout_2->addWidget(checkWhole);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnFindNext = new QPushButton(widget);
        btnFindNext->setObjectName("btnFindNext");

        horizontalLayout_3->addWidget(btnFindNext);

        btnFindPrev = new QPushButton(widget);
        btnFindPrev->setObjectName("btnFindPrev");

        horizontalLayout_3->addWidget(btnFindPrev);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName("btnClose");

        horizontalLayout_3->addWidget(btnClose);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        label->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        checkCase->setText(QCoreApplication::translate("FindDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        checkWhole->setText(QCoreApplication::translate("FindDialog", "\345\205\250\345\255\227\345\214\271\351\205\215", nullptr));
        btnFindNext->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        btnFindPrev->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\344\270\212\344\270\200\344\270\252", nullptr));
        btnClose->setText(QCoreApplication::translate("FindDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
