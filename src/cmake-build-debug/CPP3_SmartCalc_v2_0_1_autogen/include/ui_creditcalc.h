/********************************************************************************
** Form generated from reading UI file 'creditcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITCALC_H
#define UI_CREDITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditCalc
{
public:
    QPushButton *button_clear;
    QPushButton *button_calculate;
    QFrame *frame;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *percent_rate;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QRadioButton *radio_button;
    QLabel *label_3;
    QRadioButton *radio_button_2;
    QLineEdit *credit_term;
    QLineEdit *sum_credit;
    QLabel *label_8;
    QLabel *label_2;
    QFrame *frame_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *payment;
    QLabel *percent_accrued;
    QLabel *total_sum;
    QTableWidget *tableWidget;

    void setupUi(QDialog *CreditCalc)
    {
        if (CreditCalc->objectName().isEmpty())
            CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
        CreditCalc->resize(600, 380);
        CreditCalc->setMinimumSize(QSize(600, 380));
        CreditCalc->setMaximumSize(QSize(1600, 380));
        button_clear = new QPushButton(CreditCalc);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));
        button_clear->setGeometry(QRect(320, 220, 170, 30));
        QFont font;
        font.setPointSize(14);
        button_clear->setFont(font);
        button_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);\n"
"color: rgb(0, 0, 0);"));
        button_calculate = new QPushButton(CreditCalc);
        button_calculate->setObjectName(QString::fromUtf8("button_calculate"));
        button_calculate->setGeometry(QRect(100, 220, 170, 30));
        button_calculate->setFont(font);
        button_calculate->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);\n"
"color: rgb(0, 0, 0);"));
        frame = new QFrame(CreditCalc);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 581, 201));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 257, 25));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 149, 25));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        percent_rate = new QLineEdit(frame);
        percent_rate->setObjectName(QString::fromUtf8("percent_rate"));
        percent_rate->setGeometry(QRect(283, 100, 231, 25));
        QFont font1;
        font1.setPointSize(12);
        percent_rate->setFont(font1);
        percent_rate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(283, 10, 275, 25));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 172, 25));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 42, 36, 25));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(520, 102, 17, 25));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        radio_button = new QRadioButton(frame);
        radio_button->setObjectName(QString::fromUtf8("radio_button"));
        radio_button->setGeometry(QRect(10, 160, 145, 28));
        radio_button->setFont(font);
        radio_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 123, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        radio_button_2 = new QRadioButton(frame);
        radio_button_2->setObjectName(QString::fromUtf8("radio_button_2"));
        radio_button_2->setGeometry(QRect(169, 160, 232, 28));
        radio_button_2->setFont(font);
        radio_button_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);"));
        credit_term = new QLineEdit(frame);
        credit_term->setObjectName(QString::fromUtf8("credit_term"));
        credit_term->setGeometry(QRect(283, 70, 231, 25));
        credit_term->setFont(font1);
        credit_term->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        sum_credit = new QLineEdit(frame);
        sum_credit->setObjectName(QString::fromUtf8("sum_credit"));
        sum_credit->setGeometry(QRect(283, 40, 231, 25));
        sum_credit->setFont(font1);
        sum_credit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 72, 39, 25));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 137, 25));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_2 = new QFrame(CreditCalc);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 260, 581, 111));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 70, 172, 25));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(527, 10, 36, 25));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(527, 70, 41, 25));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 40, 231, 25));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(527, 40, 39, 25));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_18 = new QLabel(frame_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 10, 201, 25));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        payment = new QLabel(frame_2);
        payment->setObjectName(QString::fromUtf8("payment"));
        payment->setGeometry(QRect(283, 10, 231, 25));
        payment->setFont(font);
        payment->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        percent_accrued = new QLabel(frame_2);
        percent_accrued->setObjectName(QString::fromUtf8("percent_accrued"));
        percent_accrued->setGeometry(QRect(283, 40, 231, 25));
        percent_accrued->setFont(font);
        percent_accrued->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        total_sum = new QLabel(frame_2);
        total_sum->setObjectName(QString::fromUtf8("total_sum"));
        total_sum->setGeometry(QRect(283, 70, 231, 25));
        total_sum->setFont(font);
        total_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        tableWidget = new QTableWidget(CreditCalc);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(610, 10, 981, 361));
        frame->raise();
        frame_2->raise();
        tableWidget->raise();

        retranslateUi(CreditCalc);

        QMetaObject::connectSlotsByName(CreditCalc);
    } // setupUi

    void retranslateUi(QDialog *CreditCalc)
    {
        CreditCalc->setWindowTitle(QCoreApplication::translate("CreditCalc", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        button_clear->setText(QCoreApplication::translate("CreditCalc", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        button_calculate->setText(QCoreApplication::translate("CreditCalc", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("CreditCalc", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271:", nullptr));
        label->setText(QCoreApplication::translate("CreditCalc", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202 \321\200\320\260\321\201\321\207\320\265\321\202\320\260", nullptr));
        percent_rate->setText(QCoreApplication::translate("CreditCalc", "0.0", nullptr));
        label_4->setText(QCoreApplication::translate("CreditCalc", "\320\240\320\260\321\201\321\207\321\221\321\202 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\320\276\320\263\320\276 \320\277\320\273\320\260\321\202\320\265\320\266\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("CreditCalc", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("CreditCalc", "\321\200\321\203\320\261.", nullptr));
        label_9->setText(QCoreApplication::translate("CreditCalc", "%", nullptr));
        radio_button->setText(QCoreApplication::translate("CreditCalc", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("CreditCalc", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        radio_button_2->setText(QCoreApplication::translate("CreditCalc", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        credit_term->setText(QCoreApplication::translate("CreditCalc", "0", nullptr));
        sum_credit->setText(QCoreApplication::translate("CreditCalc", "0.0", nullptr));
        label_8->setText(QCoreApplication::translate("CreditCalc", "\320\274\320\265\321\201.", nullptr));
        label_2->setText(QCoreApplication::translate("CreditCalc", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("CreditCalc", "\320\224\320\276\320\273\320\263 + \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_14->setText(QCoreApplication::translate("CreditCalc", "\321\200\321\203\320\261.", nullptr));
        label_15->setText(QCoreApplication::translate("CreditCalc", "\321\200\321\203\320\261.", nullptr));
        label_16->setText(QCoreApplication::translate("CreditCalc", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_17->setText(QCoreApplication::translate("CreditCalc", "\321\200\321\203\320\261.", nullptr));
        label_18->setText(QCoreApplication::translate("CreditCalc", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        payment->setText(QCoreApplication::translate("CreditCalc", "0.0", nullptr));
        percent_accrued->setText(QCoreApplication::translate("CreditCalc", "0.0", nullptr));
        total_sum->setText(QCoreApplication::translate("CreditCalc", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditCalc: public Ui_CreditCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITCALC_H
