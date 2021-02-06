/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *Caso1;
    QPushButton *Caso2;
    QPushButton *Caso3;
    QPushButton *Caso4;
    QPushButton *Caso5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *HO;
    QLineEdit *HD;
    QLineEdit *D;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 661, 381));
        Caso1 = new QPushButton(centralwidget);
        Caso1->setObjectName(QString::fromUtf8("Caso1"));
        Caso1->setGeometry(QRect(20, 140, 75, 23));
        Caso2 = new QPushButton(centralwidget);
        Caso2->setObjectName(QString::fromUtf8("Caso2"));
        Caso2->setGeometry(QRect(20, 170, 75, 23));
        Caso3 = new QPushButton(centralwidget);
        Caso3->setObjectName(QString::fromUtf8("Caso3"));
        Caso3->setGeometry(QRect(20, 200, 75, 23));
        Caso4 = new QPushButton(centralwidget);
        Caso4->setObjectName(QString::fromUtf8("Caso4"));
        Caso4->setGeometry(QRect(20, 230, 75, 23));
        Caso5 = new QPushButton(centralwidget);
        Caso5->setObjectName(QString::fromUtf8("Caso5"));
        Caso5->setGeometry(QRect(20, 260, 75, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 50, 75, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 80, 75, 23));
        HO = new QLineEdit(centralwidget);
        HO->setObjectName(QString::fromUtf8("HO"));
        HO->setGeometry(QRect(110, 20, 51, 20));
        HD = new QLineEdit(centralwidget);
        HD->setObjectName(QString::fromUtf8("HD"));
        HD->setGeometry(QRect(110, 50, 51, 20));
        D = new QLineEdit(centralwidget);
        D->setObjectName(QString::fromUtf8("D"));
        D->setGeometry(QRect(110, 80, 51, 20));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 110, 91, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Caso1->setText(QApplication::translate("MainWindow", "Caso 1", nullptr));
        Caso2->setText(QApplication::translate("MainWindow", "Caso2", nullptr));
        Caso3->setText(QApplication::translate("MainWindow", "Caso3", nullptr));
        Caso4->setText(QApplication::translate("MainWindow", "Caso4", nullptr));
        Caso5->setText(QApplication::translate("MainWindow", "Caso5", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "HO", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "HD", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "d:Distancia", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Confirme Datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
