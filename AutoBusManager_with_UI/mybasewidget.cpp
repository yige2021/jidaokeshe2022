#include "mybasewidget.h"
#include <QPainter>
#include <QMouseEvent>

#define BORDER_COLOR QColor(74, 75, 76, 220)
#define BACKGROUND_COLOR QColor(74, 75, 76, 220)
#define RADIUS 30

MyBaseWidget::MyBaseWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

void MyBaseWidget::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(BORDER_COLOR);
    pen.setWidth(1);
    painter.setPen(pen);

    QBrush brush(BACKGROUND_COLOR);
    painter.setBrush(brush);

    QRectF rect(0, 0, this->width(), this->height());
    painter.drawRoundedRect(rect, RADIUS, RADIUS);
}

void MyBaseWidget::mousePressEvent(QMouseEvent *ev)
{
    auto pos = ev->pos();
    press_x = pos.x();
    press_y = pos.y();
}

//void MyBaseWidget::mouseMoveEvent(QMouseEvent *ev)
//{
//    auto global_pos = ev->globalPosition();
//    move(global_pos.x() - press_x, global_pos.y() - press_y);
//}
