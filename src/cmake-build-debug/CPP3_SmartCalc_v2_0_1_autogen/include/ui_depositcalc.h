/********************************************************************************
** Form generated from reading UI file 'depositcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITCALC_H
#define UI_DEPOSITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositCalc
{
public:
    QFrame *frame;
    QLabel *label_deposit_sum;
    QLabel *label_deposit_term;
    QLabel *label_percent_rate;
    QLabel *label_select_periodicity;
    QLabel *label_deposit_withdrawal;
    QLabel *label_deposit_refill;
    QLabel *label_capitalization;
    QLabel *label_currency_deposit_sum;
    QLineEdit *deposit_sum;
    QLineEdit *deposit_term;
    QLineEdit *percent_rate;
    QLabel *label_percent_rate_unit;
    QCheckBox *check_box_capitalization;
    QLabel *label_currency_deposit_refill;
    QLabel *label_currency_deposit_withdrawal;
    QLineEdit *deposit_refill;
    QLineEdit *deposit_withdrawal;
    QComboBox *select_periodicity;
    QComboBox *select_refill;
    QComboBox *select_withdrawal;
    QLabel *label_tax_rate;
    QLineEdit *tax_rate;
    QLabel *label_tax_rate_unit;
    QCheckBox *check_box_refill;
    QCheckBox *check_box_withdrawal;
    QLabel *label_term_unit;
    QFrame *frame_2;
    QLabel *label_percent_accrued;
    QLabel *label_nalog;
    QLabel *label_total_sum;
    QLabel *label_currency_percent_accrued;
    QLabel *label_currency_nalog;
    QLabel *label_currency_total_deposit_sum;
    QLabel *percent_accrued;
    QLabel *nalog;
    QLabel *total_sum_end_term;
    QPushButton *button_calculate;
    QPushButton *button_clear;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DepositCalc)
    {
        if (DepositCalc->objectName().isEmpty())
            DepositCalc->setObjectName(QString::fromUtf8("DepositCalc"));
        DepositCalc->resize(600, 443);
        DepositCalc->setMinimumSize(QSize(600, 443));
        DepositCalc->setMaximumSize(QSize(1230, 443));
        frame = new QFrame(DepositCalc);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 581, 261));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_deposit_sum = new QLabel(frame);
        label_deposit_sum->setObjectName(QString::fromUtf8("label_deposit_sum"));
        label_deposit_sum->setGeometry(QRect(10, 10, 127, 25));
        QFont font;
        font.setPointSize(14);
        label_deposit_sum->setFont(font);
        label_deposit_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_deposit_term = new QLabel(frame);
        label_deposit_term->setObjectName(QString::fromUtf8("label_deposit_term"));
        label_deposit_term->setGeometry(QRect(10, 40, 161, 25));
        label_deposit_term->setFont(font);
        label_deposit_term->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_percent_rate = new QLabel(frame);
        label_percent_rate->setObjectName(QString::fromUtf8("label_percent_rate"));
        label_percent_rate->setGeometry(QRect(10, 70, 171, 25));
        label_percent_rate->setFont(font);
        label_percent_rate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_select_periodicity = new QLabel(frame);
        label_select_periodicity->setObjectName(QString::fromUtf8("label_select_periodicity"));
        label_select_periodicity->setGeometry(QRect(10, 130, 211, 25));
        label_select_periodicity->setFont(font);
        label_select_periodicity->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_deposit_withdrawal = new QLabel(frame);
        label_deposit_withdrawal->setObjectName(QString::fromUtf8("label_deposit_withdrawal"));
        label_deposit_withdrawal->setGeometry(QRect(10, 220, 161, 25));
        label_deposit_withdrawal->setFont(font);
        label_deposit_withdrawal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_deposit_refill = new QLabel(frame);
        label_deposit_refill->setObjectName(QString::fromUtf8("label_deposit_refill"));
        label_deposit_refill->setGeometry(QRect(10, 190, 211, 25));
        label_deposit_refill->setFont(font);
        label_deposit_refill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_capitalization = new QLabel(frame);
        label_capitalization->setObjectName(QString::fromUtf8("label_capitalization"));
        label_capitalization->setGeometry(QRect(10, 160, 241, 25));
        label_capitalization->setFont(font);
        label_capitalization->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_currency_deposit_sum = new QLabel(frame);
        label_currency_deposit_sum->setObjectName(QString::fromUtf8("label_currency_deposit_sum"));
        label_currency_deposit_sum->setGeometry(QRect(540, 10, 36, 25));
        label_currency_deposit_sum->setFont(font);
        label_currency_deposit_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        deposit_sum = new QLineEdit(frame);
        deposit_sum->setObjectName(QString::fromUtf8("deposit_sum"));
        deposit_sum->setGeometry(QRect(270, 10, 261, 25));
        QFont font1;
        font1.setPointSize(12);
        deposit_sum->setFont(font1);
        deposit_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        deposit_term = new QLineEdit(frame);
        deposit_term->setObjectName(QString::fromUtf8("deposit_term"));
        deposit_term->setGeometry(QRect(270, 40, 261, 25));
        deposit_term->setFont(font1);
        deposit_term->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        percent_rate = new QLineEdit(frame);
        percent_rate->setObjectName(QString::fromUtf8("percent_rate"));
        percent_rate->setGeometry(QRect(270, 70, 261, 25));
        percent_rate->setFont(font1);
        percent_rate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        label_percent_rate_unit = new QLabel(frame);
        label_percent_rate_unit->setObjectName(QString::fromUtf8("label_percent_rate_unit"));
        label_percent_rate_unit->setGeometry(QRect(540, 70, 36, 25));
        label_percent_rate_unit->setFont(font);
        label_percent_rate_unit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        check_box_capitalization = new QCheckBox(frame);
        check_box_capitalization->setObjectName(QString::fromUtf8("check_box_capitalization"));
        check_box_capitalization->setGeometry(QRect(270, 160, 16, 25));
        label_currency_deposit_refill = new QLabel(frame);
        label_currency_deposit_refill->setObjectName(QString::fromUtf8("label_currency_deposit_refill"));
        label_currency_deposit_refill->setGeometry(QRect(540, 190, 36, 25));
        label_currency_deposit_refill->setFont(font);
        label_currency_deposit_refill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_currency_deposit_withdrawal = new QLabel(frame);
        label_currency_deposit_withdrawal->setObjectName(QString::fromUtf8("label_currency_deposit_withdrawal"));
        label_currency_deposit_withdrawal->setGeometry(QRect(540, 220, 36, 25));
        label_currency_deposit_withdrawal->setFont(font);
        label_currency_deposit_withdrawal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        deposit_refill = new QLineEdit(frame);
        deposit_refill->setObjectName(QString::fromUtf8("deposit_refill"));
        deposit_refill->setGeometry(QRect(370, 190, 161, 25));
        deposit_refill->setFont(font1);
        deposit_refill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        deposit_withdrawal = new QLineEdit(frame);
        deposit_withdrawal->setObjectName(QString::fromUtf8("deposit_withdrawal"));
        deposit_withdrawal->setGeometry(QRect(370, 220, 161, 25));
        deposit_withdrawal->setFont(font1);
        deposit_withdrawal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        select_periodicity = new QComboBox(frame);
        select_periodicity->addItem(QString());
        select_periodicity->addItem(QString());
        select_periodicity->setObjectName(QString::fromUtf8("select_periodicity"));
        select_periodicity->setGeometry(QRect(270, 130, 261, 25));
        select_periodicity->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        select_refill = new QComboBox(frame);
        select_refill->addItem(QString());
        select_refill->addItem(QString());
        select_refill->setObjectName(QString::fromUtf8("select_refill"));
        select_refill->setGeometry(QRect(270, 190, 91, 25));
        select_refill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        select_withdrawal = new QComboBox(frame);
        select_withdrawal->addItem(QString());
        select_withdrawal->addItem(QString());
        select_withdrawal->setObjectName(QString::fromUtf8("select_withdrawal"));
        select_withdrawal->setGeometry(QRect(270, 220, 91, 25));
        select_withdrawal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_tax_rate = new QLabel(frame);
        label_tax_rate->setObjectName(QString::fromUtf8("label_tax_rate"));
        label_tax_rate->setGeometry(QRect(10, 100, 171, 25));
        label_tax_rate->setFont(font);
        label_tax_rate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tax_rate = new QLineEdit(frame);
        tax_rate->setObjectName(QString::fromUtf8("tax_rate"));
        tax_rate->setGeometry(QRect(270, 100, 261, 25));
        tax_rate->setFont(font1);
        tax_rate->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        label_tax_rate_unit = new QLabel(frame);
        label_tax_rate_unit->setObjectName(QString::fromUtf8("label_tax_rate_unit"));
        label_tax_rate_unit->setGeometry(QRect(540, 100, 36, 25));
        label_tax_rate_unit->setFont(font);
        label_tax_rate_unit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        check_box_refill = new QCheckBox(frame);
        check_box_refill->setObjectName(QString::fromUtf8("check_box_refill"));
        check_box_refill->setGeometry(QRect(240, 190, 16, 25));
        check_box_withdrawal = new QCheckBox(frame);
        check_box_withdrawal->setObjectName(QString::fromUtf8("check_box_withdrawal"));
        check_box_withdrawal->setGeometry(QRect(240, 220, 16, 25));
        label_term_unit = new QLabel(frame);
        label_term_unit->setObjectName(QString::fromUtf8("label_term_unit"));
        label_term_unit->setGeometry(QRect(540, 40, 36, 25));
        label_term_unit->setFont(font);
        label_term_unit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame_2 = new QFrame(DepositCalc);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 320, 581, 111));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_percent_accrued = new QLabel(frame_2);
        label_percent_accrued->setObjectName(QString::fromUtf8("label_percent_accrued"));
        label_percent_accrued->setGeometry(QRect(10, 10, 221, 25));
        label_percent_accrued->setFont(font);
        label_percent_accrued->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_nalog = new QLabel(frame_2);
        label_nalog->setObjectName(QString::fromUtf8("label_nalog"));
        label_nalog->setGeometry(QRect(10, 40, 61, 25));
        label_nalog->setFont(font);
        label_nalog->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_total_sum = new QLabel(frame_2);
        label_total_sum->setObjectName(QString::fromUtf8("label_total_sum"));
        label_total_sum->setGeometry(QRect(10, 70, 281, 25));
        label_total_sum->setFont(font);
        label_total_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_currency_percent_accrued = new QLabel(frame_2);
        label_currency_percent_accrued->setObjectName(QString::fromUtf8("label_currency_percent_accrued"));
        label_currency_percent_accrued->setGeometry(QRect(540, 10, 36, 25));
        label_currency_percent_accrued->setFont(font);
        label_currency_percent_accrued->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_currency_nalog = new QLabel(frame_2);
        label_currency_nalog->setObjectName(QString::fromUtf8("label_currency_nalog"));
        label_currency_nalog->setGeometry(QRect(540, 40, 36, 25));
        label_currency_nalog->setFont(font);
        label_currency_nalog->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_currency_total_deposit_sum = new QLabel(frame_2);
        label_currency_total_deposit_sum->setObjectName(QString::fromUtf8("label_currency_total_deposit_sum"));
        label_currency_total_deposit_sum->setGeometry(QRect(540, 70, 36, 25));
        label_currency_total_deposit_sum->setFont(font);
        label_currency_total_deposit_sum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        percent_accrued = new QLabel(frame_2);
        percent_accrued->setObjectName(QString::fromUtf8("percent_accrued"));
        percent_accrued->setGeometry(QRect(300, 10, 231, 25));
        percent_accrued->setFont(font);
        percent_accrued->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        nalog = new QLabel(frame_2);
        nalog->setObjectName(QString::fromUtf8("nalog"));
        nalog->setGeometry(QRect(300, 40, 231, 25));
        nalog->setFont(font);
        nalog->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        total_sum_end_term = new QLabel(frame_2);
        total_sum_end_term->setObjectName(QString::fromUtf8("total_sum_end_term"));
        total_sum_end_term->setGeometry(QRect(300, 70, 231, 25));
        total_sum_end_term->setFont(font);
        total_sum_end_term->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        button_calculate = new QPushButton(DepositCalc);
        button_calculate->setObjectName(QString::fromUtf8("button_calculate"));
        button_calculate->setGeometry(QRect(100, 280, 170, 30));
        button_calculate->setFont(font);
        button_calculate->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);\n"
"color: rgb(0, 0, 0);"));
        button_clear = new QPushButton(DepositCalc);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));
        button_clear->setGeometry(QRect(320, 280, 170, 30));
        button_clear->setFont(font);
        button_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);\n"
"color: rgb(0, 0, 0);"));
        tableWidget = new QTableWidget(DepositCalc);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(610, 10, 610, 421));

        retranslateUi(DepositCalc);

        QMetaObject::connectSlotsByName(DepositCalc);
    } // setupUi

    void retranslateUi(QDialog *DepositCalc)
    {
        DepositCalc->setWindowTitle(QCoreApplication::translate("DepositCalc", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_deposit_sum->setText(QCoreApplication::translate("DepositCalc", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_deposit_term->setText(QCoreApplication::translate("DepositCalc", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_percent_rate->setText(QCoreApplication::translate("DepositCalc", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_select_periodicity->setText(QCoreApplication::translate("DepositCalc", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_deposit_withdrawal->setText(QCoreApplication::translate("DepositCalc", "\320\247\320\260\321\201\321\202\320\270\321\207\320\275\321\213\320\265 \321\201\320\275\321\217\321\202\320\270\321\217", nullptr));
        label_deposit_refill->setText(QCoreApplication::translate("DepositCalc", "\320\247\320\260\321\201\321\202\320\270\321\207\320\275\321\213\320\265 \320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_capitalization->setText(QCoreApplication::translate("DepositCalc", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_currency_deposit_sum->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        deposit_sum->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        deposit_term->setText(QCoreApplication::translate("DepositCalc", "0", nullptr));
        percent_rate->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        label_percent_rate_unit->setText(QCoreApplication::translate("DepositCalc", "%", nullptr));
        check_box_capitalization->setText(QCoreApplication::translate("DepositCalc", "CheckBox", nullptr));
        label_currency_deposit_refill->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        label_currency_deposit_withdrawal->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        deposit_refill->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        deposit_withdrawal->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        select_periodicity->setItemText(0, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        select_periodicity->setItemText(1, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        select_refill->setItemText(0, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        select_refill->setItemText(1, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        select_withdrawal->setItemText(0, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        select_withdrawal->setItemText(1, QCoreApplication::translate("DepositCalc", "\321\200\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        label_tax_rate->setText(QCoreApplication::translate("DepositCalc", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        tax_rate->setText(QCoreApplication::translate("DepositCalc", "13.0", nullptr));
        label_tax_rate_unit->setText(QCoreApplication::translate("DepositCalc", "%", nullptr));
        check_box_refill->setText(QCoreApplication::translate("DepositCalc", "CheckBox", nullptr));
        check_box_withdrawal->setText(QCoreApplication::translate("DepositCalc", "CheckBox", nullptr));
        label_term_unit->setText(QCoreApplication::translate("DepositCalc", "\320\274\320\265\321\201.", nullptr));
        label_percent_accrued->setText(QCoreApplication::translate("DepositCalc", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_nalog->setText(QCoreApplication::translate("DepositCalc", "\320\235\320\260\320\273\320\276\320\263", nullptr));
        label_total_sum->setText(QCoreApplication::translate("DepositCalc", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265 \320\272 \320\272\320\276\320\275\321\206\321\203 \321\201\321\200\320\276\320\272\320\260", nullptr));
        label_currency_percent_accrued->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        label_currency_nalog->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        label_currency_total_deposit_sum->setText(QCoreApplication::translate("DepositCalc", "\321\200\321\203\320\261.", nullptr));
        percent_accrued->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        nalog->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        total_sum_end_term->setText(QCoreApplication::translate("DepositCalc", "0.0", nullptr));
        button_calculate->setText(QCoreApplication::translate("DepositCalc", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        button_clear->setText(QCoreApplication::translate("DepositCalc", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositCalc: public Ui_DepositCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITCALC_H
