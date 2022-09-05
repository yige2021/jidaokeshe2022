/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *logo;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QComboBox *type;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *number;
    QPushButton *submit;
    QGroupBox *board;
    QLabel *track;
    QLabel *bus;
    QPushButton *test;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *step;
    QPushButton *stop;
    QTableWidget *status;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *TS_label;
    QLabel *D_lable;
    QLabel *S_lable;
    QPushButton *save;
    QComboBox *S_edit;
    QPushButton *browse;
    QLabel *path;
    QSpinBox *TS_edit;
    QSpinBox *D_edit;
    QGroupBox *groupBox_2;
    QLabel *Sp_label;
    QDoubleSpinBox *sp_edit;
    QWidget *tab_3;
    QLabel *info;
    QLabel *label_13;
    QPushButton *play;
    QLabel *title_zh;
    QLabel *title_en;
    QLabel *label;
    QPushButton *quit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(691, 585);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(30, 30, 71, 71));
        logo->setStyleSheet(QStringLiteral("image: url(:img/icon.png);"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 110, 631, 441));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 250, 221, 151));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox{\n"
"\n"
"border-width:1px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        type = new QComboBox(groupBox_3);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(70, 40, 131, 22));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 40, 31, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 31, 20));
        label_3->setFont(font1);
        number = new QLineEdit(groupBox_3);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(70, 70, 131, 20));
        submit = new QPushButton(groupBox_3);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setEnabled(false);
        submit->setGeometry(QRect(70, 110, 81, 31));
        submit->setFont(font1);
        board = new QGroupBox(tab);
        board->setObjectName(QStringLiteral("board"));
        board->setGeometry(QRect(20, 10, 571, 191));
        board->setFont(font);
        board->setStyleSheet(QLatin1String("QGroupBox{\n"
"\n"
"border-width:1px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        track = new QLabel(board);
        track->setObjectName(QStringLiteral("track"));
        track->setGeometry(QRect(70, 60, 421, 81));
        track->setStyleSheet(QStringLiteral("image: url(:/img/track.png);"));
        bus = new QLabel(board);
        bus->setObjectName(QStringLiteral("bus"));
        bus->setGeometry(QRect(100, 60, 16, 16));
        bus->setStyleSheet(QStringLiteral("background-image: url(:/img/bus.png);"));
        test = new QPushButton(board);
        test->setObjectName(QStringLiteral("test"));
        test->setGeometry(QRect(230, 140, 75, 23));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 240, 41, 16));
        label_4->setFont(font1);
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(500, 250, 91, 151));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QLatin1String("QGroupBox{\n"
"\n"
"border-width:1px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        start = new QPushButton(groupBox_5);
        start->setObjectName(QStringLiteral("start"));
        start->setEnabled(false);
        start->setGeometry(QRect(10, 40, 31, 31));
        start->setStyleSheet(QStringLiteral("background-image: url(:img/start.png);"));
        pause = new QPushButton(groupBox_5);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setEnabled(false);
        pause->setGeometry(QRect(50, 40, 31, 31));
        pause->setStyleSheet(QStringLiteral("background-image: url(:img/pause.png);"));
        step = new QPushButton(groupBox_5);
        step->setObjectName(QStringLiteral("step"));
        step->setEnabled(false);
        step->setGeometry(QRect(10, 80, 31, 31));
        step->setStyleSheet(QStringLiteral("background-image: url(:img/step.png);"));
        stop = new QPushButton(groupBox_5);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setEnabled(false);
        stop->setGeometry(QRect(50, 80, 31, 31));
        stop->setStyleSheet(QStringLiteral("background-image: url(:img/stop.png);"));
        status = new QTableWidget(tab);
        if (status->columnCount() < 1)
            status->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        status->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (status->rowCount() < 5)
            status->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        status->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        status->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        status->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        status->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        status->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFlags(Qt::NoItemFlags);
        status->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFlags(Qt::NoItemFlags);
        status->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFlags(Qt::NoItemFlags);
        status->setItem(2, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFlags(Qt::NoItemFlags);
        status->setItem(3, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFlags(Qt::NoItemFlags);
        status->setItem(4, 0, __qtablewidgetitem10);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(20, 260, 221, 141));
        status->setEditTriggers(QAbstractItemView::NoEditTriggers);
        status->setSelectionMode(QAbstractItemView::NoSelection);
        status->horizontalHeader()->setVisible(false);
        status->horizontalHeader()->setCascadingSectionResizes(false);
        status->horizontalHeader()->setDefaultSectionSize(100);
        status->horizontalHeader()->setHighlightSections(false);
        status->horizontalHeader()->setMinimumSectionSize(25);
        status->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        status->horizontalHeader()->setStretchLastSection(false);
        status->verticalHeader()->setVisible(true);
        status->verticalHeader()->setCascadingSectionResizes(false);
        status->verticalHeader()->setDefaultSectionSize(27);
        status->verticalHeader()->setHighlightSections(false);
        status->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        status->verticalHeader()->setStretchLastSection(true);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 210, 71, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(430, 210, 121, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(550, 210, 41, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(280, 210, 41, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 210, 21, 21));
        label_10->setStyleSheet(QStringLiteral("image: url(:/img/clo.png);"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(410, 210, 21, 21));
        label_11->setStyleSheet(QStringLiteral("image: url(:/img/cnt.png);"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(530, 210, 21, 21));
        label_12->setStyleSheet(QStringLiteral("image: url(:/img/tar.png);"));
        tabWidget->addTab(tab, QString());
        board->raise();
        groupBox_3->raise();
        label_4->raise();
        groupBox_5->raise();
        status->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 10, 351, 231));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"\n"
"border-width:1px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        TS_label = new QLabel(groupBox);
        TS_label->setObjectName(QStringLiteral("TS_label"));
        TS_label->setGeometry(QRect(40, 70, 181, 16));
        TS_label->setFont(font1);
        D_lable = new QLabel(groupBox);
        D_lable->setObjectName(QStringLiteral("D_lable"));
        D_lable->setGeometry(QRect(40, 100, 151, 16));
        D_lable->setFont(font1);
        S_lable = new QLabel(groupBox);
        S_lable->setObjectName(QStringLiteral("S_lable"));
        S_lable->setGeometry(QRect(40, 40, 141, 16));
        S_lable->setFont(font1);
        save = new QPushButton(groupBox);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(120, 140, 111, 31));
        save->setFont(font1);
        S_edit = new QComboBox(groupBox);
        S_edit->setObjectName(QStringLiteral("S_edit"));
        S_edit->setGeometry(QRect(220, 40, 91, 22));
        browse = new QPushButton(groupBox);
        browse->setObjectName(QStringLiteral("browse"));
        browse->setGeometry(QRect(120, 180, 111, 31));
        browse->setFont(font1);
        path = new QLabel(groupBox);
        path->setObjectName(QStringLiteral("path"));
        path->setGeometry(QRect(40, 120, 261, 21));
        TS_edit = new QSpinBox(groupBox);
        TS_edit->setObjectName(QStringLiteral("TS_edit"));
        TS_edit->setGeometry(QRect(220, 70, 91, 22));
        TS_edit->setMinimum(2);
        TS_edit->setMaximum(10);
        TS_edit->setValue(5);
        D_edit = new QSpinBox(groupBox);
        D_edit->setObjectName(QStringLiteral("D_edit"));
        D_edit->setGeometry(QRect(220, 100, 91, 22));
        D_edit->setMinimum(1);
        D_edit->setMaximum(10);
        D_edit->setValue(2);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 260, 351, 141));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox{\n"
"\n"
"border-width:1px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:gray;\n"
"\n"
"margin-top:0.5ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        Sp_label = new QLabel(groupBox_2);
        Sp_label->setObjectName(QStringLiteral("Sp_label"));
        Sp_label->setGeometry(QRect(40, 60, 161, 16));
        sp_edit = new QDoubleSpinBox(groupBox_2);
        sp_edit->setObjectName(QStringLiteral("sp_edit"));
        sp_edit->setGeometry(QRect(210, 60, 91, 22));
        sp_edit->setDecimals(1);
        sp_edit->setMinimum(0.1);
        sp_edit->setMaximum(10);
        sp_edit->setSingleStep(0.1);
        sp_edit->setValue(1);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        info = new QLabel(tab_3);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(220, 90, 401, 181));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 60, 191, 251));
        label_13->setStyleSheet(QStringLiteral("image: url(:/img/author1and2.png);"));
        play = new QPushButton(tab_3);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(260, 220, 21, 23));
        play->setFlat(true);
        tabWidget->addTab(tab_3, QString());
        title_zh = new QLabel(centralWidget);
        title_zh->setObjectName(QStringLiteral("title_zh"));
        title_zh->setGeometry(QRect(110, 20, 511, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(26);
        title_zh->setFont(font2);
        title_en = new QLabel(centralWidget);
        title_en->setObjectName(QStringLiteral("title_en"));
        title_en->setGeometry(QRect(120, 70, 241, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        title_en->setFont(font3);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 70, 91, 16));
        QFont font4;
        font4.setFamily(QStringLiteral("Forte"));
        font4.setPointSize(14);
        label->setFont(font4);
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(640, 20, 31, 31));
        quit->setStyleSheet(QStringLiteral("border-image: url(:img/quit.png);"));
        MainWindow->setCentralWidget(centralWidget);
        tabWidget->raise();
        logo->raise();
        title_zh->raise();
        title_en->raise();
        label->raise();
        quit->raise();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\207\252\345\212\250\351\251\276\351\251\266\345\205\254\344\272\244\350\275\246\350\260\203\345\272\246\347\263\273\347\273\237 AutoBusManager 1.0", Q_NULLPTR));
        logo->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\221\345\207\272\346\214\207\344\273\244", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "clockwise", Q_NULLPTR)
         << QApplication::translate("MainWindow", "counterclockwise", Q_NULLPTR)
         << QApplication::translate("MainWindow", "target", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\347\261\273\345\236\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\231\345\217\267", Q_NULLPTR));
        submit->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\346\214\207\344\273\244", Q_NULLPTR));
        board->setTitle(QApplication::translate("MainWindow", "\351\235\242\346\235\277", Q_NULLPTR));
        track->setText(QString());
        bus->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        test->setText(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        start->setToolTip(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\277\220\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        start->setText(QString());
#ifndef QT_NO_TOOLTIP
        pause->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234\350\207\252\345\212\250\350\277\220\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pause->setText(QString());
#ifndef QT_NO_TOOLTIP
        step->setToolTip(QApplication::translate("MainWindow", "\345\215\225\346\255\245\350\277\220\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        step->setText(QString());
#ifndef QT_NO_TOOLTIP
        stop->setToolTip(QApplication::translate("MainWindow", "\347\273\223\346\235\237\350\277\220\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stop->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = status->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\345\200\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = status->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "TIME", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = status->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Position", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = status->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Clockwise", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = status->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "CounterClockwise", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = status->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Target", Q_NULLPTR));

        const bool __sortingEnabled = status->isSortingEnabled();
        status->setSortingEnabled(false);
        status->setSortingEnabled(__sortingEnabled);

        label_6->setText(QApplication::translate("MainWindow", "clockwise", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "counterclockwise", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "target", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", " \345\233\276\344\276\213\357\274\232", Q_NULLPTR));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256\345\217\202\346\225\260", Q_NULLPTR));
        TS_label->setText(QApplication::translate("MainWindow", " \350\275\246\347\253\231\346\225\260\351\207\217\357\274\210TOTAL_STATION\357\274\211", Q_NULLPTR));
        D_lable->setText(QApplication::translate("MainWindow", " \350\275\246\347\253\231\351\227\264\350\267\235\357\274\210DISTANCE\357\274\211", Q_NULLPTR));
        S_lable->setText(QApplication::translate("MainWindow", " \350\260\203\345\272\246\347\255\226\347\225\245\357\274\210STRATEGY\357\274\211", Q_NULLPTR));
        save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\271\266\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        S_edit->clear();
        S_edit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "FCFS", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SSTF", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SCAN", Q_NULLPTR)
        );
        browse->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210\351\205\215\347\275\256\346\226\207\344\273\266..", Q_NULLPTR));
        path->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\212\250\347\224\273\350\256\276\347\275\256", Q_NULLPTR));
        Sp_label->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\351\200\237\345\272\246\357\274\210\346\257\217clock\350\200\227\346\227\266\357\274\211", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        info->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\350\256\241\347\256\227\345\257\274\350\256\272\344\270\216\347\250\213\345\272\217\350\256\276\350\256\241\350\257\276\347\250\213\350\256\276\350\256\241 - \350\207\252\345\212\250\351\251\276\351\251\266\345\205\254\344\272\244\350\275\246\350\260\203\345\272\246\347\263\273\347\273\237\357\274\210\345\212\250\347\224\273\347\211\210\357\274\211</p><p>\347\273\204\345\210\253\357\274\232\347\254\254\345\233\233\347\273\204</p><p>\347\217\255\347\272\247\357\274\2322021211315</p><p>\347\273\204\351\225\277\357\274\232\346\242\201\346\231\250\351\224\220 2021211321</p><p>\347\273\204\345\221\230\357\274\232\351\227\253\346\231\250\346\265\251 2021211314</p><p>\347\273\204\345\221\230\357\274\232\345\255\231\346\207\277 2021211315</p><p>2022\345\271\2647\346\234\210</p></body></html>", Q_NULLPTR));
        label_13->setText(QString());
        play->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        title_zh->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\207\252\345\212\250\351\251\276\351\251\266\345\205\254\344\272\244\350\275\246\350\260\203\345\272\246\347\263\273\347\273\237 \345\212\250\347\224\273\347\211\210</span></p></body></html>", Q_NULLPTR));
        title_en->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#12c8fa;\">AutoBus Manager with UI</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Version:1.0", Q_NULLPTR));
        quit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
