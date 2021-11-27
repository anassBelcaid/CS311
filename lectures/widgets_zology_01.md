---
layout: page
title:  Widgets Zoology I
description:   Discover the rich set of predefined widgets.
date: 2021/28/11

lecturers:
  - name:  Anass Belcaid
permalink: /lectures/widgets1/
---



* (toc)
{:toc}


## Introduction

This lecture will be a little different from the previous ones. As now, we are
well aware of the core functionality of **Qt**. This main focus of this lecture,
    is give a simple survey on the most common used widgets.

 > The Goal is not to remember them all, but rather have a feeling of how to
 find a widget, how to read its documentation and investigate its properties,
 signals and slots.


Let's take for example our beloved
[QLabel](https://doc.qt.io/qt-5/qlabel.html). Let's imagine that is our first
encounter with this basic Widget. First on the **documentation** page,  you
focus on the following sections

### Widget Definition

<div class="center">
  <img src= "{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Label_description.png" width="500">
  <div class="figcaption">
  Simple description of the QLabel.
  </div>
</div>


We remark the following points:

1. The name of the **Header** (`<QLabel>`), in order to use the widget.
2. The name of the **QT component** (`QT  += widgets`), to include in the **Qmake** project.
3. The base class of which `QFrame`.


### Detailed description

If want to get the **detailed description** about this class, we click on the
`More` link. We will get:

<div class="center">
  <img src= "{{ site.url }}{{ site.baseurl
  }}/assets/img/lecture8/Label_detailled_description.png" width="800">
  <div class="figcaption">
  Detailed Description of the QLabel.
  </div>
</div>


### Properties

Another interesting part in the documentation is the **Properties** which shows
a set of `useful` (or identifying) properties.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/label_properties.png" width="550">
  <div class="figcaption">
  The set of useful properties of the Label class.
  </div>
</div>


For example, looking in the **property** section of the label, we can discover
that a *label* has:

- **Alignment** : which holds the alignment of the text.
- **Indent**: holds the text indent in pixels.
- **qpixmap**: Image of the label.


### Public functions

The most important piece of information is the set of **pubic function** and
methods. This section presents all the public **API** for manipulating the item

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Label_public_interface.png" width="650">
  <div class="figcaption">
  Set of the Public functions for the Label class.
  </div>
</div>

### Signals / Slots

The last two important sections are the **Signals/Slots** part. The section
presents all the available signals and slots for this widgets.


<div class="left">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Label_signals.png" width="300">
</div>
<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Label_slots.png" width="300">
  <div class="figcaption">
  Signals and slots of the Label Widget.
  </div>
</div>

> Pretty neat.

--------

## Input  Widgets

Using this mechanism, we will present a set of widget to get an **information**
or entry from the user. Depending on the type of this information, we will use
the appropriate **widget**:

### Boolean 

Those types of widgets, can hold a binary information.  The most used one are
QCheckBox and QRadioButton.

#### QCheckBox

A [QCheckBox](https://doc.qt.io/qt-5/qcheckbox.html#details) is an **option**
button that can be switched on (checked) or off(unchecked).

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Qcheck_box.png">
  <div class="figcaption">
  QcheckBox
  </div>
</div>



> CheckBoxes are usually used to represent features in an application that can
be enabled or disabled **without affecting each others**.


<div class="left">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/checkboxes-exclusive.png" width="200">
</div>

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture8/checkboxes-non-exclusive.png" width="200">
  <div class="figcaption">
  Cechbox can be checked together in the same time.
  </div>
</div>

The most important signal of the widgets is `stateChanged` which is triggered if
the state of the checkbox is changed.

#### QRadio Button 

A similar widget to the QWidget is the [QRadioButton](https://doc.qt.io/qt-5/qradiobutton.html). A QRadioButton is an option button that can be switched on (checked) or off (unchecked). Radio buttons typically present the user with a **one of many** choice.

> In a group of radio buttons, only one radio button at a time can be checked; if the user selects another button, the previously selected button is unchecked.


### Numbers

Now, we will move on reading an **number** values. For these first citizen
class, we have a large choice of **predefined** widgets.


1. [QSpinBox](https://doc.qt.io/qt-5/qspinbox.html#details):
    
    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/windows-spinbox.png">
    </div>
    
2. [QDoubleSpinBox](https://doc.qt.io/qt-5/qdoublespinbox.html) 

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/doubleSpinBox.png">
    </div>

3. [QSlider](https://doc.qt.io/qt-5/qslider.html)

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/slider.jpg">
    </div>

4. [QDial](https://doc.qt.io/qt-5/qdial.html)

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/dial.jpg">
    </div>

5. [QScrollBar](https://doc.qt.io/archives/qt-4.8/qscrollbar.html)

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/scrollbar.png">
    </div>

----

### Enums (lists)

[Enums](https://en.cppreference.com/w/cpp/language/enum) are **distinct** type
whose value  is restricted  to a range of values which may include several
**explicitly**  named **constants**.

For example, we can declare the three  basic colors such as:

```cpp
enum Color { red, green, blue };
```

The best way to read these type of values in a **graphical** interface is a [QComboBox](https://doc.qt.io/qt-5/qcombobox.html):

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl
  }}/assets/img/lecture8/comboBox.png">
</div>

The most used methods for this widget are:

- `count` : return the number of available items.
- `currentIndex` : return the current selected **index**.
- `addItem(QString)` : to add a **single** item to the list.
- `addItems(QStringList)`: to add a **list** of items.
- `clear()`:  to remove all the items. 

----

### Strings 

For **Strings** we could use one those **progressive** classes depending on the
size of  your String.



1. [QLineEdit](https://doc.qt.io/qt-5/qlineedit.html): for reading a single
   line.

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/lineEdit.png">
    </div>

2. [QPlainText](https://doc.qt.io/qt-5/qplaintextedit.html): Display and edit
   **plain text**.


    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/PlainText.png">
    </div>

3. [QTextEdit](https://doc.qt.io/qt-5/qtextedit.html): display and edit both
   plain and **rich** (formatable) text.

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/TextEdit.png">
    </div>

-----

### Time

Qt offers two basic widget a **generic widget** to get the **Date** input for a
user.


1. [QDateTimeEdit](https://doc.qt.io/qt-5/qdatetimeedit.html): is a widget for
   editing dates and times in the same time.

   
    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/windows-datetimeedit.png" height="50">
    </div>

For more oriented **Time** entries. Qt offers the two **derived** classes:


-  [QTimeEdit](https://doc.qt.io/qt-5/qtimeedit.html): for editing **times**
only.
 
    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/windows-timeedit.png" height="50">
    </div>

If we need to read the **date** only, we have a 

- [QDateEdit](https://doc.qt.io/qt-5/qdateedit.html#details): for reading only
dates

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl
      }}/assets/img/lecture8/windows-dateedit.png" height="50">
    </div>

> **Exericse**: Write a Qt widget that presents three previous widgets for
reading a birthday. Your widgets should be synchronized!!. ( i.e. If the date
changes, all the date aware widgets should change. And the same goes for the
time.

## Wrap up

We, will take a pause here, and try to test your knowledge on **reading the
documentation** and identifying the different widgets in a graphical window.

So you goal is achieve the following **Widget**:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture8/Dial_slider_horizontal.png">
  <div class="figcaption">
  Your first Entry challenge.
  </div>
</div>


- All the **elements** (I'm not saying their name) are **synchronized**.
- The Upmost down element, is for controling if the widget on the right should
be placed in **Horizontal** or **Vertical** Alignement.

- Add A Key binding with **up** to increae the value of the widgets and **down**
to increase.

- If we check the Inverted keyBinding, those controles should **switch** roles.

This example is taken from the [Qt archive](https://doc.qt.io/archives/qt-5.5/qtwidgets-widgets-sliders-example.html), if you want to complete the full details.

----






