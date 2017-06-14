#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QRect>
#include <QString>
#include <QLabel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    timer_id = startTimer(200);
    objects.push_back(unique_ptr<Shape> (new Ball));
    objects.push_back(unique_ptr<Shape> (new Rocket));

    setGeometry(0, 0, max_x, max_y);
//    qDebug() << geometry().width();

    ui->setupUi(this);
    this->installEventFilter(this);



}


void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (auto &o:objects)
    {
        o->OnDraw(painter);
    }

}
void Dialog::solution()
{
    Ball* pBall = nullptr;
    Rocket* pRock = nullptr;

    for (auto &o:objects)
    {
        pBall = dynamic_cast<Ball*> (o.get());
        if(pBall != nullptr)
        {
            break;
        }

    }
    for (auto &o:objects)
    {
        pRock = dynamic_cast <Rocket*> (o.get());
        if(pRock != nullptr)
        {
            break;
        }

    }

    Line ln;
    Point p;
    if ((pBall != nullptr) && (pRock != nullptr))
    {
        ln = pRock->get_line();
        p = pBall->get_point();

 //       qDebug() << ln.x1 << " " << ln.y1 << " " << ln.x2 << " " << ln.y2 << "\t"  << p.x << " " << p.y;
    }


   if ((p.x >= ln.x1) && (p.x <= ln.x2) && (p.y >= ln.y1))
   {
        pBall->m_dy = -pBall->m_dy;
        score += 100;
   }

   if((pBall->w > max_x + 15) || (pBall->m_x < x_min - 15) || (pBall->m_y < y_top - 15) || (pBall->h >= max_y))
   {
        score -= 50;
   }

//    qDebug() << score;
       ui->score_l->setNum(score);

}

void Dialog::timerEvent(QTimerEvent *e)
{
    for (auto &o:objects)
    {
        Ball* pBall = dynamic_cast<Ball*> (o.get());
        if (pBall != nullptr)
        {
            pBall->move();
            pBall->tryMirror(0,y_top, max_x,max_y);
        }
    }

    solution();

    update();
}

bool Dialog::eventFilter(QObject *object, QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        for (auto &o:objects)
        {
            Rocket* pRock = dynamic_cast<Rocket*> (o.get());
            if (pRock != nullptr)
            {
                QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);

                if( Qt::Key_Left == keyEvent->key() )
                {
                    pRock->move_left();
                }
                else if( Qt::Key_Right == keyEvent->key() )
                {
                    pRock->move_right();
                }
            }
        }

    }


}


Dialog::~Dialog()
{
    delete ui;
}
