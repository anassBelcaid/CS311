---
layout: page
title:  Signals and Slots
description:   Learn how to make connexions between objects.
date:  2021/11/01

lecturers:
  - name:  Anass Belcaid

permalink: /signals/
---


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture5/cmu-logo.png"
  width="500" height="300">
</div>


* (toc)
{:toc}


# Introduction

**Signals and slots** is the language construct introduced by Qt for
communication between objects. This is a short and concise  for the [Observer pattern](https://en.wikipedia.org/wiki/Observer_pattern). It provides the possibility for objects (called observers) to be recipients for automatic notifications from objects upon change of state or any notification.

This mechanism is in the core of **Event-driven** program such as **GUI**
applications. Where an application reacts to different events generated by the
users. Events could be generated by mouse clicks, keyboard or other timed
events.


The signals and slots mecanism is fundamental to Qt programming. It enables the
application programmer to **bind**  objects together without the objects knowing
*anything* about each other. We have alread connected some signals and slots
together.


## Slots

**Slots** are almost idential to ordinary `C++` member functions. They can be
virtual,  public, protected or private. The can also be **directly** invoked as
any other `C++` member functions. Also their parameters can be of any type. The
main difference is that `slots` can be **automatically** connected to respond to
a signal. The classical connect mecansim look like:

```cpp
connect(sender, SIGNAL(signal), receiver, SLOT(slot));
```

where `sender` and `receiver` are pointer to QOjbects and signal and slot are
methods without parameters.

for Example, in previous examples, we connected a `spinBox` and a `slider` to
synchronize their values using:

```cpp
connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
```

- What is intersing about signals is that a signal can also be connected to
another signal!! making a **chain reaction**.

```cpp
connect(lineEdit, SIGNAL(textChanged(const QString &),
        this, SIGNAL(updateRecord(const QString &)));
```

- Another intersting aspect is that those connexions could be broken
programmatically for a more intersting behavior.


```
disconnect(lcd, SIGNAL(overflow()), this, SLOT(handleMathError()));
```


# Basic Example.

### Volume control

Lets start with a basic example showing a `slider` and `LCDNumber`. Downdload
the starting project in <a href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture5/volume_constrol.zip"> volume_control.zip</a>.

- Configure and run the project to produce a window like:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture5/volume.png">
  <div class="figcaption">
  Window with a slider and LCDNumber.
  </div>
</div>

- We want to establish a connexion that `display` the number of the slider each
time its `value changes`.

- In order to do that we connect those objects using the mechanism of
`signals/slots`.
    1. First add the declaration in `window.h`
    ```cpp
    void makeConnections();
    ```
    We will create this method to setup all the connexions between the internal
    objects. We could do this in the consructor. However, we may find this
    approach more structured.

    2. Add the implementation of ths method in the `window.cpp`:
        ```cpp
        void makeConnections()
        {
            //connect the slider to the LCD number
            connect(slider, SIGNAL(valueChanged(int)), number, SLOT(display(int)));
        }
        ```
        o
    In this code we have two object (widgets) which are the `slider` and the
    `number`. The line added will connect each change in value in the slider
    to un **update** of the lcdnumber displayed value.

    
### Custom SLOTs

In this second example, we will illustrate that we could create our
**custom slots** to respond to a given signal. Our goal is create a dialog to
**roll a dice** each time we click on a button.

1. First download and extract ther starter code in <a
href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture5/dice.zip"> dice.zip </a>. 

2. Execute the programmer, we will see a diaglog like this one:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture5/diceroller.png">
  <div class="figcaption">
  Dialog to roll a dice.
  </div>
</div>

3. In order to create the connexion between the button and the dices, we need to
   create our `custom slot` to respond the click.

   - First, we will declare our private slots in the `window.hpp`
    ```cpp
    private slots:
       void rollDice()
    ```

   - Second, we will implement this slot in `window.cpp`
    ```cpp
    void rollDice()
    {
       //Generate a random value for dice 1
       int n = qrand() % 6;
       die1->setPixmap(diceFaces[n]);

      //Same for the second dice
      n  = qrand() % 6;
      die2->setPixmap(diceFaces[n]);
    }
    ```
    This method will alter change the images for the dices given the values
    `randomly generated` by Qt Random generator.

   - Now we only need to connect the click of the button with this slot, we
   will do it in a custom connexion.

    ```cpp
    void DiceRoller::makeConnections()
    {
     connect(rollButton, &QPushButton::clicked, this, DiceRoller::rollDice);
    }
    ```

    In the last line, we used a new synatax to refere to the signals and slots
    using the `reference` mecanism.



# Special Signals (events)

## Key Press

Another cool aspect of `signals/slots` is that you could program them also in
the spirit of **listener/event** mechanism like in `Java`. Fist, we will
illustrate this concept by writing an application to respond to a `key press`
from the keyboard.


We could write this concept using `signals/slots` but we will do it by
**overriding** an inherited function:

```cpp
void keyPressEvent( QKeyEvent *e)
```

This `slot` will be trigger automatically each time we click an keyboard key.
The information of the key will be store in the class [QKeyEvent](https://doc.qt.io/qt-5.15/qkeyevent.html).

Let's show the mechanism by writing a simple application to **display** the keys
entered by the user. The application will automatically close when we enter the
**escape** key.


The starter code for is in <a href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture5/pressEvent.zip"> pressEvent.zip </a>


First we will write a custom widget that inherit from the `QWidget` class:

```cpp
class SpecialEvent : public QWidget
{
public:
    SpecialEvent();
    virtual ~SpecialEvent();
 private:
    void createWidgets();
    void placeWidgets();
    void makeConnexions();

private:
    //members

    QLabel *mainLabel;
    QHBoxLayout *mainLayout;
protected:
    void keyPressEvent(QKeyEvent *e);
};
```

The main point is this class, is the **protected function** that inform Qt that
we will override the `keyPressEvent` for our widget.


Here is the implementation:

```cpp


SpecialEvent::SpecialEvent():QWidget()
{
    createWidgets();
    placeWidgets();
    makeConnexions();
}

SpecialEvent::~SpecialEvent()
{
    delete mainLabel;
    delete mainLayout;
}

void SpecialEvent::createWidgets()
{
    // Create the label
    mainLabel = new QLabel("K", this);
    mainLabel->setFont(QFont("monospace",50));


    //Create the layout
    mainLayout = new QHBoxLayout();
}

void SpecialEvent::placeWidgets()
{

    mainLayout->addWidget(mainLabel);
    setLayout(mainLayout);
}

void SpecialEvent::makeConnexions()
{

}
void SpecialEvent::keyPressEvent(QKeyEvent *e)
{

    if (e->key() == Qt::Key_Escape)
        qApp->exit();
    else
        mainLabel->setText(e->text());
}
```

The interesting part is the `keyPressEvent` where we:

- Compare the `e->key()` to static key `Qt::Key_Escape`
- If this key is entered we quit the application.
- Otherwise we will change the label of the label the text of the key.
        `mainLabel->setText(e->text())`




## Move event

Similar to the `keyPressEvent`, we can also listen to any `mouse mouvement`
following the same syntax.

For example, suppose we want to change the title of the our **keyPress**
application to show the current position of the window. We need to override the
[QMoveEvent](https://doc.qt.io/qt-5/qmoveevent.html) using the following syntax:

```cpp
void moveEvent(QMoveEvent *event)
```

Here is the implementation of this function, using the information stored in the
`event`.


```cpp
//getting the x position
auto x = e->pos().x();

// getting the y position
auto y = e->pos().y();

setWindowTitle(QString("Pos (%0, %1)").arg(x).arg(y));

```
## Timer

Another example of pref dined events is a [TimerEvent](https://doc.qt.io/archives/qt-4.8/qtimerevent.html). This event is used to implement repetitive tasks that automatically triggered periodically. A classical example is a **clock** showing the current time:


Let's change our simple application to display the current time and change it
each second.


First we will add `QLabel` to  our private set of widgets to represent current time:


```cpp
QLabel * timeLabel;
```


We need to create this label in the `createWidgets` section:

```cpp

//Getting the current time
QTime current = QTime::currentTime();

//Creating the label with the curren time
timeLabel = new QLabel(current.toString(), this);

//changint the font
timeLabel->setFont(QFont("times", 14));
```


Now, we will add it to our **mainLayout** in the `placeWidgets` function:

```cpp
//Add a spacer 
mainLayout->addSpacer(new QSpacer(40, QSizePolicy::expanding));
mainLayout->addWidget(timeLabel);
```


Now for the essential part, in order to respond to a time event we need:

1. **Override** the `timerEvent(QTimerEvent *)` function.
2. **Register** a timer with a given time with `startTime(int)`


For the **first part**, here is the code for the overidden function:

```cpp
void SpecialEvent::timerEvent(QTimerEvent *e)
{
    //Here we simply change the test of the label 
    // by the current time
    timeLabel->setText(QTime::currentTime().toString());
}
```


For the **second part**, we add the following call the contructor:

```cpp
//Add a timer listener each 1000 miliscons (1 second)
startTimer(1000);
```


At the end you have an application three events. Here is a snapshot for this
application:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture4/final_special_event.png">
  <div class="figcaption">
   An application that listen to (key, mouse, timer) events.
  </div>
</div>










