/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *lineEdit_dir;
    QPushButton *pushButton_opendir;
    QPushButton *pushButton_composite;
    QPushButton *pushButton_savepit;
    QLineEdit *lineEdit_R;
    QLineEdit *lineEdit_G;
    QLineEdit *lineEdit_B;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_exit;
    QLineEdit *lineEdit_rows;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 72, 15));
        lineEdit_dir = new QLineEdit(Widget);
        lineEdit_dir->setObjectName(QString::fromUtf8("lineEdit_dir"));
        lineEdit_dir->setGeometry(QRect(480, 20, 311, 21));
        pushButton_opendir = new QPushButton(Widget);
        pushButton_opendir->setObjectName(QString::fromUtf8("pushButton_opendir"));
        pushButton_opendir->setGeometry(QRect(600, 50, 93, 28));
        pushButton_composite = new QPushButton(Widget);
        pushButton_composite->setObjectName(QString::fromUtf8("pushButton_composite"));
        pushButton_composite->setGeometry(QRect(430, 470, 93, 28));
        pushButton_savepit = new QPushButton(Widget);
        pushButton_savepit->setObjectName(QString::fromUtf8("pushButton_savepit"));
        pushButton_savepit->setGeometry(QRect(560, 470, 93, 31));
        lineEdit_R = new QLineEdit(Widget);
        lineEdit_R->setObjectName(QString::fromUtf8("lineEdit_R"));
        lineEdit_R->setGeometry(QRect(680, 150, 113, 21));
        lineEdit_G = new QLineEdit(Widget);
        lineEdit_G->setObjectName(QString::fromUtf8("lineEdit_G"));
        lineEdit_G->setGeometry(QRect(680, 210, 113, 21));
        lineEdit_B = new QLineEdit(Widget);
        lineEdit_B->setObjectName(QString::fromUtf8("lineEdit_B"));
        lineEdit_B->setGeometry(QRect(680, 270, 113, 21));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(690, 120, 91, 20));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(691, 180, 101, 20));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(691, 240, 91, 20));
        pushButton_exit = new QPushButton(Widget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(670, 530, 93, 28));
        lineEdit_rows = new QLineEdit(Widget);
        lineEdit_rows->setObjectName(QString::fromUtf8("lineEdit_rows"));
        lineEdit_rows->setGeometry(QRect(680, 350, 113, 21));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(690, 320, 72, 15));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 80, 521, 361));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\345\220\210\346\210\220\347\273\223\346\236\234", nullptr));
        pushButton_opendir->setText(QApplication::translate("Widget", "open dir", nullptr));
        pushButton_composite->setText(QApplication::translate("Widget", "\345\233\276\347\211\207\345\220\210\346\210\220", nullptr));
        pushButton_savepit->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        label_3->setText(QApplication::translate("Widget", "R\351\200\232\351\201\223 \347\254\254\345\207\240\350\241\214", nullptr));
        label_4->setText(QApplication::translate("Widget", "G\351\200\232\351\201\223 \347\254\254\345\207\240\350\241\214", nullptr));
        label_5->setText(QApplication::translate("Widget", "B\351\200\232\351\201\223 \347\254\254\345\207\240\350\241\214", nullptr));
        pushButton_exit->setText(QApplication::translate("Widget", "EXIT", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\255\230\345\233\276\345\244\232\345\260\221\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
