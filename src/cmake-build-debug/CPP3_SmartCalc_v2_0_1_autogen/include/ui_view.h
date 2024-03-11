/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QLineEdit *user_input;
    QPushButton *number_0;
    QPushButton *number_1;
    QPushButton *number_2;
    QPushButton *number_3;
    QPushButton *button_minus;
    QPushButton *button_point;
    QPushButton *button_plus;
    QPushButton *number_4;
    QPushButton *number_5;
    QPushButton *number_6;
    QPushButton *button_division;
    QPushButton *number_7;
    QPushButton *button_AC;
    QPushButton *button_sqrt;
    QPushButton *button_log;
    QPushButton *button_bracket_f;
    QPushButton *number_8;
    QPushButton *number_9;
    QPushButton *button_bracket_r;
    QPushButton *button_asin;
    QPushButton *button_acos;
    QPushButton *button_scale;
    QPushButton *button_mult;
    QPushButton *button_atan;
    QPushButton *button_sin;
    QPushButton *button_cos;
    QPushButton *button_tan;
    QPushButton *button_ln;
    QPushButton *button_back_space;
    QPushButton *button_deposit;
    QPushButton *button_credit;
    QPushButton *button_result;
    QPushButton *button_graph;
    QPushButton *button_x;
    QPushButton *button_mod;
    QPushButton *button_E;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(500, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(View->sizePolicy().hasHeightForWidth());
        View->setSizePolicy(sizePolicy);
        View->setMinimumSize(QSize(500, 320));
        View->setMaximumSize(QSize(500, 320));
        View->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(246, 245, 244);"));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        user_input = new QLineEdit(centralwidget);
        user_input->setObjectName(QString::fromUtf8("user_input"));
        user_input->setGeometry(QRect(10, 10, 481, 41));
        user_input->setCursor(QCursor(Qt::PointingHandCursor));
        user_input->setStyleSheet(QString::fromUtf8("font: 17pt \"Ubuntu\";\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';\n"
""));
        number_0 = new QPushButton(centralwidget);
        number_0->setObjectName(QString::fromUtf8("number_0"));
        number_0->setGeometry(QRect(10, 260, 61, 51));
        number_0->setCursor(QCursor(Qt::PointingHandCursor));
        number_0->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_1 = new QPushButton(centralwidget);
        number_1->setObjectName(QString::fromUtf8("number_1"));
        number_1->setGeometry(QRect(10, 210, 61, 51));
        number_1->setCursor(QCursor(Qt::PointingHandCursor));
        number_1->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_2 = new QPushButton(centralwidget);
        number_2->setObjectName(QString::fromUtf8("number_2"));
        number_2->setGeometry(QRect(70, 210, 61, 51));
        number_2->setCursor(QCursor(Qt::PointingHandCursor));
        number_2->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_3 = new QPushButton(centralwidget);
        number_3->setObjectName(QString::fromUtf8("number_3"));
        number_3->setGeometry(QRect(130, 210, 61, 51));
        number_3->setCursor(QCursor(Qt::PointingHandCursor));
        number_3->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_minus = new QPushButton(centralwidget);
        button_minus->setObjectName(QString::fromUtf8("button_minus"));
        button_minus->setGeometry(QRect(190, 210, 61, 51));
        button_minus->setCursor(QCursor(Qt::PointingHandCursor));
        button_minus->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_point = new QPushButton(centralwidget);
        button_point->setObjectName(QString::fromUtf8("button_point"));
        button_point->setGeometry(QRect(70, 260, 61, 51));
        button_point->setCursor(QCursor(Qt::PointingHandCursor));
        button_point->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_plus = new QPushButton(centralwidget);
        button_plus->setObjectName(QString::fromUtf8("button_plus"));
        button_plus->setGeometry(QRect(190, 260, 61, 51));
        button_plus->setCursor(QCursor(Qt::PointingHandCursor));
        button_plus->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        number_4 = new QPushButton(centralwidget);
        number_4->setObjectName(QString::fromUtf8("number_4"));
        number_4->setGeometry(QRect(10, 160, 61, 51));
        number_4->setCursor(QCursor(Qt::PointingHandCursor));
        number_4->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_5 = new QPushButton(centralwidget);
        number_5->setObjectName(QString::fromUtf8("number_5"));
        number_5->setGeometry(QRect(70, 160, 61, 51));
        number_5->setCursor(QCursor(Qt::PointingHandCursor));
        number_5->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_6 = new QPushButton(centralwidget);
        number_6->setObjectName(QString::fromUtf8("number_6"));
        number_6->setGeometry(QRect(130, 160, 61, 51));
        number_6->setCursor(QCursor(Qt::PointingHandCursor));
        number_6->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_division = new QPushButton(centralwidget);
        button_division->setObjectName(QString::fromUtf8("button_division"));
        button_division->setGeometry(QRect(190, 160, 61, 51));
        button_division->setCursor(QCursor(Qt::PointingHandCursor));
        button_division->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        number_7 = new QPushButton(centralwidget);
        number_7->setObjectName(QString::fromUtf8("number_7"));
        number_7->setGeometry(QRect(10, 110, 61, 51));
        number_7->setCursor(QCursor(Qt::PointingHandCursor));
        number_7->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_AC = new QPushButton(centralwidget);
        button_AC->setObjectName(QString::fromUtf8("button_AC"));
        button_AC->setGeometry(QRect(10, 60, 61, 51));
        button_AC->setCursor(QCursor(Qt::PointingHandCursor));
        button_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 97, 81);\n"
""));
        button_sqrt = new QPushButton(centralwidget);
        button_sqrt->setObjectName(QString::fromUtf8("button_sqrt"));
        button_sqrt->setGeometry(QRect(310, 260, 61, 51));
        button_sqrt->setCursor(QCursor(Qt::PointingHandCursor));
        button_sqrt->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_log = new QPushButton(centralwidget);
        button_log->setObjectName(QString::fromUtf8("button_log"));
        button_log->setGeometry(QRect(310, 60, 61, 51));
        button_log->setCursor(QCursor(Qt::PointingHandCursor));
        button_log->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_bracket_f = new QPushButton(centralwidget);
        button_bracket_f->setObjectName(QString::fromUtf8("button_bracket_f"));
        button_bracket_f->setGeometry(QRect(70, 60, 61, 51));
        button_bracket_f->setCursor(QCursor(Qt::PointingHandCursor));
        button_bracket_f->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);\n"
""));
        number_8 = new QPushButton(centralwidget);
        number_8->setObjectName(QString::fromUtf8("number_8"));
        number_8->setGeometry(QRect(70, 110, 61, 51));
        number_8->setCursor(QCursor(Qt::PointingHandCursor));
        number_8->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        number_9 = new QPushButton(centralwidget);
        number_9->setObjectName(QString::fromUtf8("number_9"));
        number_9->setGeometry(QRect(130, 110, 61, 51));
        number_9->setCursor(QCursor(Qt::PointingHandCursor));
        number_9->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_bracket_r = new QPushButton(centralwidget);
        button_bracket_r->setObjectName(QString::fromUtf8("button_bracket_r"));
        button_bracket_r->setGeometry(QRect(130, 60, 61, 51));
        button_bracket_r->setCursor(QCursor(Qt::PointingHandCursor));
        button_bracket_r->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_asin = new QPushButton(centralwidget);
        button_asin->setObjectName(QString::fromUtf8("button_asin"));
        button_asin->setGeometry(QRect(310, 110, 61, 51));
        button_asin->setCursor(QCursor(Qt::PointingHandCursor));
        button_asin->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_acos = new QPushButton(centralwidget);
        button_acos->setObjectName(QString::fromUtf8("button_acos"));
        button_acos->setGeometry(QRect(310, 160, 61, 51));
        button_acos->setCursor(QCursor(Qt::PointingHandCursor));
        button_acos->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_scale = new QPushButton(centralwidget);
        button_scale->setObjectName(QString::fromUtf8("button_scale"));
        button_scale->setGeometry(QRect(250, 260, 61, 51));
        button_scale->setCursor(QCursor(Qt::PointingHandCursor));
        button_scale->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_mult = new QPushButton(centralwidget);
        button_mult->setObjectName(QString::fromUtf8("button_mult"));
        button_mult->setGeometry(QRect(190, 110, 61, 51));
        button_mult->setCursor(QCursor(Qt::PointingHandCursor));
        button_mult->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_atan = new QPushButton(centralwidget);
        button_atan->setObjectName(QString::fromUtf8("button_atan"));
        button_atan->setGeometry(QRect(310, 210, 61, 51));
        button_atan->setCursor(QCursor(Qt::PointingHandCursor));
        button_atan->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_sin = new QPushButton(centralwidget);
        button_sin->setObjectName(QString::fromUtf8("button_sin"));
        button_sin->setGeometry(QRect(250, 110, 61, 51));
        button_sin->setCursor(QCursor(Qt::PointingHandCursor));
        button_sin->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_cos = new QPushButton(centralwidget);
        button_cos->setObjectName(QString::fromUtf8("button_cos"));
        button_cos->setGeometry(QRect(250, 160, 61, 51));
        button_cos->setCursor(QCursor(Qt::PointingHandCursor));
        button_cos->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_tan = new QPushButton(centralwidget);
        button_tan->setObjectName(QString::fromUtf8("button_tan"));
        button_tan->setGeometry(QRect(250, 210, 61, 51));
        button_tan->setCursor(QCursor(Qt::PointingHandCursor));
        button_tan->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_ln = new QPushButton(centralwidget);
        button_ln->setObjectName(QString::fromUtf8("button_ln"));
        button_ln->setGeometry(QRect(250, 60, 61, 51));
        button_ln->setCursor(QCursor(Qt::PointingHandCursor));
        button_ln->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_back_space = new QPushButton(centralwidget);
        button_back_space->setObjectName(QString::fromUtf8("button_back_space"));
        button_back_space->setGeometry(QRect(430, 60, 61, 51));
        button_back_space->setCursor(QCursor(Qt::PointingHandCursor));
        button_back_space->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 190, 111);"));
        button_deposit = new QPushButton(centralwidget);
        button_deposit->setObjectName(QString::fromUtf8("button_deposit"));
        button_deposit->setGeometry(QRect(370, 110, 121, 51));
        button_deposit->setCursor(QCursor(Qt::PointingHandCursor));
        button_deposit->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_credit = new QPushButton(centralwidget);
        button_credit->setObjectName(QString::fromUtf8("button_credit"));
        button_credit->setGeometry(QRect(370, 160, 121, 51));
        button_credit->setCursor(QCursor(Qt::PointingHandCursor));
        button_credit->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_result = new QPushButton(centralwidget);
        button_result->setObjectName(QString::fromUtf8("button_result"));
        button_result->setGeometry(QRect(370, 260, 121, 51));
        button_result->setCursor(QCursor(Qt::PointingHandCursor));
        button_result->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"\n"
"\n"
""));
        button_graph = new QPushButton(centralwidget);
        button_graph->setObjectName(QString::fromUtf8("button_graph"));
        button_graph->setGeometry(QRect(370, 210, 121, 51));
        button_graph->setCursor(QCursor(Qt::PointingHandCursor));
        button_graph->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_x = new QPushButton(centralwidget);
        button_x->setObjectName(QString::fromUtf8("button_x"));
        button_x->setGeometry(QRect(130, 260, 61, 51));
        button_x->setCursor(QCursor(Qt::PointingHandCursor));
        button_x->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        button_mod = new QPushButton(centralwidget);
        button_mod->setObjectName(QString::fromUtf8("button_mod"));
        button_mod->setGeometry(QRect(190, 60, 61, 51));
        button_mod->setCursor(QCursor(Qt::PointingHandCursor));
        button_mod->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        button_E = new QPushButton(centralwidget);
        button_E->setObjectName(QString::fromUtf8("button_E"));
        button_E->setGeometry(QRect(370, 60, 61, 51));
        button_E->setCursor(QCursor(Qt::PointingHandCursor));
        button_E->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 190, 111);"));
        View->setCentralWidget(centralwidget);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "Calculator", nullptr));
        user_input->setText(QString());
        number_0->setText(QCoreApplication::translate("View", "0", nullptr));
        number_1->setText(QCoreApplication::translate("View", "1", nullptr));
        number_2->setText(QCoreApplication::translate("View", "2", nullptr));
        number_3->setText(QCoreApplication::translate("View", "3", nullptr));
        button_minus->setText(QCoreApplication::translate("View", "-", nullptr));
        button_point->setText(QCoreApplication::translate("View", ".", nullptr));
        button_plus->setText(QCoreApplication::translate("View", "+", nullptr));
        number_4->setText(QCoreApplication::translate("View", "4", nullptr));
        number_5->setText(QCoreApplication::translate("View", "5", nullptr));
        number_6->setText(QCoreApplication::translate("View", "6", nullptr));
        button_division->setText(QCoreApplication::translate("View", "/", nullptr));
        number_7->setText(QCoreApplication::translate("View", "7", nullptr));
        button_AC->setText(QCoreApplication::translate("View", "A/C", nullptr));
        button_sqrt->setText(QCoreApplication::translate("View", "sqrt", nullptr));
        button_log->setText(QCoreApplication::translate("View", "log", nullptr));
        button_bracket_f->setText(QCoreApplication::translate("View", "(", nullptr));
        number_8->setText(QCoreApplication::translate("View", "8", nullptr));
        number_9->setText(QCoreApplication::translate("View", "9", nullptr));
        button_bracket_r->setText(QCoreApplication::translate("View", ")", nullptr));
        button_asin->setText(QCoreApplication::translate("View", "asin", nullptr));
        button_acos->setText(QCoreApplication::translate("View", "acos", nullptr));
        button_scale->setText(QCoreApplication::translate("View", "^", nullptr));
        button_mult->setText(QCoreApplication::translate("View", "*", nullptr));
        button_atan->setText(QCoreApplication::translate("View", "atan", nullptr));
        button_sin->setText(QCoreApplication::translate("View", "sin", nullptr));
        button_cos->setText(QCoreApplication::translate("View", "cos", nullptr));
        button_tan->setText(QCoreApplication::translate("View", "tan", nullptr));
        button_ln->setText(QCoreApplication::translate("View", "ln", nullptr));
        button_back_space->setText(QCoreApplication::translate("View", "<-", nullptr));
        button_deposit->setText(QCoreApplication::translate("View", "deposit", nullptr));
        button_credit->setText(QCoreApplication::translate("View", "credit", nullptr));
        button_result->setText(QCoreApplication::translate("View", "=", nullptr));
        button_graph->setText(QCoreApplication::translate("View", "graph", nullptr));
        button_x->setText(QCoreApplication::translate("View", "x", nullptr));
        button_mod->setText(QCoreApplication::translate("View", "mod", nullptr));
        button_E->setText(QCoreApplication::translate("View", "E", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
