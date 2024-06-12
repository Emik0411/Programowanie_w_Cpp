#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::lightGray)));
    auto r = this->rect();
    painter.drawRect(r);


    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);

    QPointF center = QPointF(20, 75);
    int R = 30;
    QRadialGradient gradient(center, R);
    gradient.setColorAt(0, Qt::magenta);
    gradient.setColorAt(0.5, Qt::lightGray);
    painter.setBrush(gradient);

    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.drawEllipse(center.x() - R / 2, center.y() - R / 2, R, R);
        }
        painter.rotate(360.0 / num_disks);
    }

    painter.setPen(QPen(Qt::black));
    painter.drawLine(-2, 0, 2, 0);
    painter.drawLine(0, -2, 0, 2);
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
