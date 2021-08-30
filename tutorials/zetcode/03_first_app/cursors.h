#pragma  once
#include <QWidget>
#include <QFrame>
#include <QGridLayout>


class Cursor : public QWidget
{
    public:
        Cursor(QWidget *parent = nullptr);
};

Cursor::Cursor(QWidget *parent):QWidget(parent)
{
    // creating a frame inside the widget
    auto *frame1 = new QFrame(this);
    frame1->setFrameStyle(QFrame::Box);
    frame1->setCursor(Qt::SizeAllCursor);


    //adding a second grid
    auto *frame2 = new QFrame(this);
    frame2->setFrameStyle(QFrame::Box);
    frame2->setCursor(Qt::WaitCursor);

    //adding a second grid
    auto *frame3 = new QFrame(this);
    frame3->setFrameStyle(QFrame::Box);
    frame3->setCursor(Qt::PointingHandCursor);

    



    // laying things with  a grid
    auto grid = new QGridLayout(this);
    grid->addWidget(frame1, 0, 0);
    grid->addWidget(frame2, 0 , 1);
    grid->addWidget(frame3, 1, 0 );

    setLayout(grid);
}
