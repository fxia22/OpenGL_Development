/********************************************************************************
** Form generated from reading UI file 'xfWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XFWIDGET_H
#define UI_XFWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nehewidget
{
public:

    void setupUi(QWidget *Nehewidget)
    {
        if (Nehewidget->objectName().isEmpty())
            Nehewidget->setObjectName(QStringLiteral("Nehewidget"));
        Nehewidget->resize(400, 300);

        retranslateUi(Nehewidget);

        QMetaObject::connectSlotsByName(Nehewidget);
    } // setupUi

    void retranslateUi(QWidget *Nehewidget)
    {
        Nehewidget->setWindowTitle(QApplication::translate("Nehewidget", "Nehewidget", 0));
    } // retranslateUi

};

namespace Ui {
    class Nehewidget: public Ui_Nehewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XFWIDGET_H
