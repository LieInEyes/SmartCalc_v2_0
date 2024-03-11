/********************************************************************************
** Form generated from reading UI file 'randomx.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMX_H
#define UI_RANDOMX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RandomX
{
public:
    QLabel *label;
    QLineEdit *stringX;
    QPushButton *button_ok;

    void setupUi(QDialog *RandomX)
    {
        if (RandomX->objectName().isEmpty())
            RandomX->setObjectName(QString::fromUtf8("RandomX"));
        RandomX->resize(250, 120);
        label = new QLabel(RandomX);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 150, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        stringX = new QLineEdit(RandomX);
        stringX->setObjectName(QString::fromUtf8("stringX"));
        stringX->setGeometry(QRect(10, 40, 230, 25));
        stringX->setStyleSheet(QString::fromUtf8("font: 17pt \"Ubuntu\";\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';"));
        button_ok = new QPushButton(RandomX);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setGeometry(QRect(80, 80, 80, 25));
        button_ok->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));

        retranslateUi(RandomX);

        QMetaObject::connectSlotsByName(RandomX);
    } // setupUi

    void retranslateUi(QDialog *RandomX)
    {
        RandomX->setWindowTitle(QCoreApplication::translate("RandomX", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RandomX", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\205", nullptr));
        button_ok->setText(QCoreApplication::translate("RandomX", "\320\236\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomX: public Ui_RandomX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMX_H
