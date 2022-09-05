#include <QFile>
#include <QFileDialog>
#include <qstringlistmodel.h>
#include <QtDebug>
#include <qpainter.h>
#include <QMouseEvent>
#include <QTableView>
#include <QStandardItemModel>
#include <QTime>
#include <QMediaPlayer>
#include <string>

#include "mainwindow.h"
#include "io.h"
#include "init.h"
#include "datastr.h"

QPoint winP;//用于保存鼠标相对于窗口的坐标
QString fileName;

Ui::MainWindow* pub;

bool autorun;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pub = ui;
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/img/iconmini.png"));
    //下面是窗口初始化
    setFixedSize(this->width(), this->height());                    //固定窗口尺寸
    setWindowFlags(windowFlags() &~ Qt::WindowMaximizeButtonHint);  //禁止最大化
    this->setAttribute(Qt::WA_TranslucentBackground);               //设置窗口背景透明
    setWindowOpacity(0.93);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);        // 设置窗口为无边框
    //下面是添加车站状态label
    for(int i = 1; i <= 40; i++){
        QLabel *staLab = new QLabel("", ui->board);//注：最后一个参数一定为一个“父窗体”！
    }


    ui->test->hide();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)//鼠标释放事件
{
    QWidget::mouseReleaseEvent(event);//由基类继续传递
    winP=QPoint();//释放鼠标，清空数据
}

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标点击事件
{
    winP=QPoint();
    QWidget::mousePressEvent(event);//由基类继续传递
    QPoint mouseP = event->globalPos();//获取鼠标点击时相对于屏幕的坐标(z)
    int x = this->geometry().topLeft().x();//窗口左上角相对于屏幕的x坐标(x_x)
    int y = this->geometry().topLeft().y();//窗口左上角相对于屏幕的y坐标(x_y)
    //求出鼠标相对于应用窗口的坐标(y)
    int x_w=mouseP.x()-x;
    int y_w=mouseP.y()-y;
    //将鼠标相对于窗口的坐标保存
    winP.setX(x_w);
    winP.setY(y_w);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);//由基类继续传递
    QPoint mouseP = event->globalPos();//获取鼠标点击时相对于屏幕的坐标(z)
    QPoint endP(mouseP.x()-winP.x(),mouseP.y()-winP.y());//求出窗口相对于桌面的坐标(x)
    this->move(endP);//设置窗口相对于桌面的坐标（x），实现窗口移动
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制背景图
    QPixmap pixmap(":img/bg2.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); // 绘制不规则背景
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_start_clicked()
{
    autorun = 1;
    ui->step->setEnabled(0);
    ui->stop->setEnabled(0);
    int tt = ui -> sp_edit ->value() * 1000;
    while (autorun){
        QTime time;
        time.start();
        TIME++;
        readCommand(0, 0);
        while (time.elapsed() < tt){
            QCoreApplication::processEvents();   //处理事件
        }
    }
}

void MainWindow::on_save_clicked()
{
    QString ts = ui->TS_edit->text();
    QString ds = ui->D_edit->text();

    TOTAL_STATION = ts.toInt();
    DISTANCE = ds.toInt();
    if (ui->S_edit->currentText() == "FCFS"){
        STRATEGY = 1;
    }
    if (ui->S_edit->currentText() == "SSTF"){
        STRATEGY = 2;
    }
    if (ui->S_edit->currentText() == "SCAN"){
        STRATEGY = 3;
    }
    initSystem();
    ui->submit->setEnabled(1);
    ui->start->setEnabled(1);
    ui->pause->setEnabled(1);
    ui->step->setEnabled(1);
    ui->stop->setEnabled(1);


}

void MainWindow::on_browse_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,tr("请选择配置文件"),"C:",tr("配置文件(*dic);"));
    ui->path->setText(fileName);

    QByteArray tmp = fileName.toLatin1();
    char* path = tmp.data();
    getConfig(path);

    if (STRATEGY == 1){
        ui->S_edit->setCurrentText("FCFS");
    }
    if (STRATEGY == 2){
        ui->S_edit->setCurrentText("SSTF");
    }
    if (STRATEGY == 3){
        ui->S_edit->setCurrentText("SCAN");
    }
    ui->TS_edit->setValue(TOTAL_STATION);
    ui->D_edit->setValue(DISTANCE);
}

void MainWindow::on_quit_clicked()
{
    qApp->exit(0);
}

void MainWindow::on_submit_clicked()
{
    QString str = ui->type->currentText();
    QString stv = ui->number->text();
    int commandType;
    int value = stv.toInt();

    if (str == "clockwise"){
        commandType = 1;
    }
    if (str == "counterclockwise"){
        commandType = 2;
    }
    if (str == "target"){
        commandType = 3;
    }
    readCommand(commandType, value);
}


void printStatus(){
    QTableWidgetItem* myTIME = new QTableWidgetItem(QString::number(TIME));
    QTableWidgetItem* myPos = new QTableWidgetItem(QString::number(position->pos));
    std::string s1, s2, s3;
    for (int i = 1; i <= TOTAL_STATION; i++){
        QLabel* now ;

        s1 += INFO[i].clockwise;
        now = (QLabel *)pub->board->children().at(i + 12);

        if (INFO[i].clockwise == '1'){
            now->setHidden(0);
        }
        else {
            now->setHidden(1);
        }

        s2 += INFO[i].counterclockwise;
        now = (QLabel *)pub->board->children().at(i + 22);


        if (INFO[i].counterclockwise == '1'){
            now->setHidden(0);
        }
        else {
            now->setHidden(1);
        }

        s3 += INFO[i].target;
        now = (QLabel *)pub->board->children().at(i + 32);


        if (INFO[i].target == '1'){
            now->setHidden(0);
        }
        else {
            now->setHidden(1);
        }
    }
    QTableWidgetItem* myTar = new QTableWidgetItem(QString::fromStdString(s3));
    QTableWidgetItem* myClc = new QTableWidgetItem(QString::fromStdString(s1));
    QTableWidgetItem* myCnt = new QTableWidgetItem(QString::fromStdString(s2));
    pub->status->setItem(0, 0, myTIME);
    pub->status->setItem(0, 1, myPos);
    pub->status->setItem(0, 2, myClc);
    pub->status->setItem(0, 3, myCnt);
    pub->status->setItem(0, 4, myTar);
}

void setStation(){
    int it1, it2;
    int tot = TOTAL_STATION - 2;
    if (TOTAL_STATION <= 2){
        tot = TOTAL_STATION;
    }
    if (TOTAL_STATION % 2){
        it1 = 350 / (tot / 2);
        it2 = 350 / (tot / 2 + 1);
    }
    else {
        it1 = it2 = 350 / (tot / 2);
    }
    for (int i = 1; i <= TOTAL_STATION; i++){
        int num = i + 2;
        QLabel *labNow = (QLabel *)(pub->board->children().at(num));
        if (i < TOTAL_STATION / 2 + 1){
            labNow->setGeometry(105 + it1 * (i - 1), 79, 15, 15);
        }
        else {
            labNow->setGeometry(455 - it2 * (i - TOTAL_STATION / 2 - 1), 107, 15, 15);
        }
        labNow->setText(QString::number(i));
        QFont ft("Consolas", 10);
        QPalette pa;
        pa.setColor(QPalette::WindowText, QColor("purple"));
        ft.setPointSize(11);
        labNow->setFont(ft);
        labNow->setPalette(pa);
        labNow->setAutoFillBackground(true);
        labNow->setAlignment(Qt::AlignHCenter);
    }
    for (int i = 1; i <= TOTAL_STATION; i++){
        int num = i + 12;
        QLabel *labNow = (QLabel *)(pub->board->children().at(num));
        if (i < TOTAL_STATION / 2 + 1){
            labNow->setGeometry(90 + it1 * (i - 1), 40, 15, 15);
        }
        else {
            labNow->setGeometry(440 - it2 * (i - TOTAL_STATION / 2 - 1), 140, 15, 15);
        }
        labNow->setPixmap(QPixmap(":/img/clo.png"));
    }
    for (int i = 1; i <= TOTAL_STATION; i++){
        int num = i + 22;
        QLabel *labNow = (QLabel *)(pub->board->children().at(num));
        if (i < TOTAL_STATION / 2 + 1){
            labNow->setGeometry(105 + it1 * (i - 1), 40, 15, 15);
        }
        else {
            labNow->setGeometry(455 - it2 * (i - TOTAL_STATION / 2 - 1), 140, 15, 15);
        }
        labNow->setPixmap(QPixmap(":/img/cnt.png"));
    }
    for (int i = 1; i <= TOTAL_STATION; i++){
        int num = i + 32;
        QLabel *labNow = (QLabel *)(pub->board->children().at(num));
        if (i < TOTAL_STATION / 2 + 1){
            labNow->setGeometry(120 + it1 * (i - 1), 40, 15, 15);
        }
        else {
            labNow->setGeometry(470 - it2 * (i - TOTAL_STATION / 2 - 1), 140, 15, 15);
        }
        labNow->setPixmap(QPixmap(":/img/tar.png"));
    }
}

void moveBus(int v){
    int it1, it2, it3;
    int tot = TOTAL_STATION - 2;
    int x = pub->bus->geometry().x();
    int y = pub->bus->geometry().y();
    int w = pub->bus->geometry().width();
    int h = pub->bus->geometry().height();

    if (TOTAL_STATION <= 2){
        tot = TOTAL_STATION;
    }
    if (TOTAL_STATION % 2){
        it1 = (360 / (tot / 2)) / DISTANCE;
        it2 = (360 / (tot / 2 + 1)) / DISTANCE;
    }
    else {
        it1 = it2 = (360 / (tot / 2)) / DISTANCE;
    }
    it3 = 45 / (DISTANCE - 1);

    int t1 = (TOTAL_STATION / 2) * (DISTANCE - 1) + 1;
    int t2 = (TOTAL_STATION / 2 + 1) * (DISTANCE - 1) + 1;

    if (v == 1){
        if (position->pos < t1 && position->pos != 0){
            pub->bus->setGeometry(x + it1, y, w, h);
        }
        else if (position->pos == t1){
            if (DISTANCE != 2){
                pub->bus->setGeometry(475, 70, w, h);
            }
            else {
                pub->bus->setGeometry(475, 90, w, h);
            }
        }
        else if (position->pos > t1 && position->pos < t2){
            pub->bus->setGeometry(475, y + it3, w, h);
        }
        else if (position->pos == t2){
            pub->bus->setGeometry(453, 125, w, h);
        }
        else if (position->pos > t2 && position->pos < TOTAL_LENGTH - DISTANCE + 1){
            pub->bus->setGeometry(x - it2, 125, w, h);
        }
        else if (position->pos == TOTAL_LENGTH - DISTANCE + 1){
            if (DISTANCE != 2){
                pub->bus->setGeometry(70, 110, w, h);
            }
            else {
                pub->bus->setGeometry(70, 90, w, h);
            }
        }

        else if (position->pos > TOTAL_LENGTH - DISTANCE + 1 && position->pos < TOTAL_LENGTH){
            pub->bus->setGeometry(70, y - it3, w, h);
        }

        else {
            pub->bus->setGeometry(100, 60, w, h);
        }
    }
    else {
        if (position->pos == TOTAL_LENGTH - 1){
            if (DISTANCE != 2){
                pub->bus->setGeometry(70, 70, w, h);
            }
            else {
                pub->bus->setGeometry(70, 90, w, h);
            }
        }

        else if (position->pos > TOTAL_LENGTH - DISTANCE && position->pos < TOTAL_LENGTH){
            pub->bus->setGeometry(70, y + it3, w, h);
        }

        else if(position->pos == TOTAL_LENGTH - DISTANCE){
            pub->bus->setGeometry(100, 125, w, h);
        }

        else if (position->pos >= t2 - 1 && position->pos < TOTAL_LENGTH - DISTANCE){
            pub->bus->setGeometry(x + it2, 125, w, h);
        }

        else if (position->pos == t2 - 2){
            if (DISTANCE != 2){
                pub->bus->setGeometry(475, 110, w, h);
            }
            else {
                pub->bus->setGeometry(475, 90, w, h);
            }
        }

        else if (position->pos >= t1 - 1 && position->pos < t2 - 2){
            pub->bus->setGeometry(475, y - it3, w, h);
        }

        else if (position->pos == t1 - 2){
            pub->bus->setGeometry(460, 60, w, h);
        }

        else if (position->pos < t1 - 2){
            pub->bus->setGeometry(x - it1, y, w, h);
        }

        else {
            pub->bus->setGeometry(100, 60, w, h);
        }
    }
}

void MainWindow::on_step_clicked()
{
    TIME++;
    readCommand(0, 0);
    this->update();
}

void MainWindow::on_stop_clicked()
{
    int w = pub->bus->geometry().width();
    int h = pub->bus->geometry().height();
    initSystem();
    ui->bus->setGeometry(100, 60, w, h);
}

void MainWindow::on_pause_clicked()
{
    autorun = 0;
    ui->step->setEnabled(1);
    ui->stop->setEnabled(1);
}

void MainWindow::on_play_clicked()
{
    QMediaPlayer *m_pMediaPlayer = new QMediaPlayer;
    m_pMediaPlayer->setMedia(QUrl("qrc:/music/Toilet Story 6.mp3"));
    m_pMediaPlayer->play();
}

void MainWindow::on_test_clicked()
{

}
