#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QEvent>
#include "ball.h"
#include "rocket.h"
#include <vector>
#include "shape.h"
#include <memory>
#include <line.h>

using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int timer_id;

    vector <unique_ptr <Shape>> objects;

    void solution();

    int max_x = 670;
    int max_y = 490;
    int x_min = 0;

    int y_top = 67;
    int score = 300;


protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *e);

    bool eventFilter(QObject *object, QEvent *e);


};

#endif // DIALOG_H
