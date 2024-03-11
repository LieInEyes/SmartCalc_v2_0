/********************************************************************************
** Form generated from reading UI file 'model_graph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_GRAPH_H
#define UI_MODEL_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QCustomPlot *widget;
    QLabel *label_x_max;
    QLineEdit *x_max;
    QLabel *label_y_max;
    QLineEdit *y_max;
    QLabel *label_3;
    QLabel *label_x_min;
    QLineEdit *x_min;
    QLabel *label_y_min;
    QLineEdit *y_min;
    QPushButton *buttonOk;

    void setupUi(QDialog *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);
        Graph->setMinimumSize(QSize(900, 600));
        Graph->setMaximumSize(QSize(900, 600));
        widget = new QCustomPlot(Graph);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 882, 491));
        label_x_max = new QLabel(Graph);
        label_x_max->setObjectName(QString::fromUtf8("label_x_max"));
        label_x_max->setGeometry(QRect(232, 534, 61, 17));
        x_max = new QLineEdit(Graph);
        x_max->setObjectName(QString::fromUtf8("x_max"));
        x_max->setGeometry(QRect(290, 530, 142, 25));
        label_y_max = new QLabel(Graph);
        label_y_max->setObjectName(QString::fromUtf8("label_y_max"));
        label_y_max->setGeometry(QRect(233, 560, 51, 17));
        y_max = new QLineEdit(Graph);
        y_max->setObjectName(QString::fromUtf8("y_max"));
        y_max->setGeometry(QRect(290, 560, 142, 25));
        label_3 = new QLabel(Graph);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 510, 211, 17));
        label_x_min = new QLabel(Graph);
        label_x_min->setObjectName(QString::fromUtf8("label_x_min"));
        label_x_min->setGeometry(QRect(12, 534, 61, 17));
        x_min = new QLineEdit(Graph);
        x_min->setObjectName(QString::fromUtf8("x_min"));
        x_min->setGeometry(QRect(70, 530, 142, 25));
        label_y_min = new QLabel(Graph);
        label_y_min->setObjectName(QString::fromUtf8("label_y_min"));
        label_y_min->setGeometry(QRect(13, 560, 51, 17));
        y_min = new QLineEdit(Graph);
        y_min->setObjectName(QString::fromUtf8("y_min"));
        y_min->setGeometry(QRect(70, 560, 142, 25));
        buttonOk = new QPushButton(Graph);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setGeometry(QRect(480, 530, 161, 51));

        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QDialog *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Function graph", nullptr));
        label_x_max->setText(QCoreApplication::translate("Graph", "X max =", nullptr));
        label_y_max->setText(QCoreApplication::translate("Graph", "Y max =", nullptr));
        label_3->setText(QCoreApplication::translate("Graph", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\276\320\261\320\273\320\260\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_x_min->setText(QCoreApplication::translate("Graph", "X min =", nullptr));
        label_y_min->setText(QCoreApplication::translate("Graph", "Y min =", nullptr));
        buttonOk->setText(QCoreApplication::translate("Graph", "\320\276\321\202\320\276\321\200\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_GRAPH_H
