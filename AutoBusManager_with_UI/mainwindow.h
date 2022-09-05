#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "public.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_browse_clicked();

    void on_start_clicked();

    void on_save_clicked();

    void on_quit_clicked();

    void on_test_clicked();

    void on_submit_clicked();

    void on_step_clicked();

    void on_stop_clicked();

    void on_pause_clicked();

    void on_play_clicked();

private:

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件

};

void printStatus();
void setStation();
void moveBus(int v);

#endif // MAINWINDOW_H
