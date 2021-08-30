#pragma once
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class PlusMinus : public QWidget
{
    private:
        QPushButton *plus;
        QPushButton *minus;
        QLabel * label;


        /*methods */
        void plusOne();
        void minusOne();

    public:
        PlusMinus(QWidget *parent = nullptr);

};


PlusMinus::PlusMinus(QWidget *parent):QWidget(parent)
{
   //creating the component 
   plus = new QPushButton("+", this);
   plus->resize(200, 100);
   minus = new QPushButton("-", this);
   minus->resize(200, 100);

   label = new QLabel("0", this);


   //adding the components
   QGridLayout *grid = new QGridLayout(this);
   grid->addWidget(plus, 0, 0);
   grid->addWidget(minus, 0, 2);
   grid->addWidget(label, 1, 1);

   //connexion
   connect(plus, &QPushButton::clicked, this, &PlusMinus::plusOne);
   connect(minus, &QPushButton::clicked, this, &PlusMinus::minusOne);
}

void PlusMinus::plusOne()
{
  //getting the value from the QLabel
  auto value = label->text().toInt();
  value ++;
  label->setText(QString::number(value));

}

void PlusMinus::minusOne()
{

  auto value = label->text().toInt();
  value --;
  label->setText(QString::number(value));

}
