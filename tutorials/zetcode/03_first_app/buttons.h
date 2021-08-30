#pragma once
#include <QWidget>
#include <QApplication>
#include <QPushButton>

class Button : public QWidget
{
public:
    Button (QWidget *parent = nullptr);

};

Button::Button(QWidget *parent):QWidget(parent)
{
    //creating a push button
    QPushButton *B = new QPushButton("Push Me",this);

    //setting the geometry
    B->setGeometry(50, 50 , 100, 40);


    //connection ( next chapters for explanation)
    connect(B, &QPushButton::clicked, qApp, &QApplication::quit);
}
