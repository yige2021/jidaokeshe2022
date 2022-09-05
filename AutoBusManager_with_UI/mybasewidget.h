#ifndef MYBASEWIDGET_H
#define MYBASEWIDGET_H

#include <QWidget>

class MyBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyBaseWidget(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *);

    int press_x;
    int press_y;
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // MYBASEWIDGET_H
