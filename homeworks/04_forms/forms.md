---
layout:  page
title: Programming Widget Layout
description:   Use the gained knowledge to create forms.
date:  2021/10/27

lecturers:
  - name:  Anass Belcaid

permalink: /forms/
---


* (toc)
{:toc}


# Experimenting with QHBOXLayout

Create a project called `hbox` with the following code:

```cpp
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QWidget* window = new QWidget();
  window->setWindowTitle("QHBoxLayout Test");

  window->show();

  return app.exec();
}
```

This will show an **empty** window. Your goal is to modify the code in order to
display the following form:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/04_forms/hbox.png">
  <div class="figcaption">
  A QHBoxLayout example.
  </div>
</div>


# Nested Layouts

The goal of the exercice is learn to analyse the construction of a form and
thencode it using **Netsted layouts**. 

Here we show you a classic dialog from the book **GB** to search for a user.

>You do not have to code any **functinality**, just the form of the dialog.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/04_forms/nesting.png">
  <div class="figcaption">
  Nested Layout.
  </div>
</div>


- In order to add a layout to a main one, you'll have to use 
    ```cpp
    addLayout(layout)
    ```
- The **vertical space** ([Stretch](https://doc.qt.io/qt-5.15/qboxlayout.html#addStretch)) could be added by 
    - `layout->addStretch(dimension)`
    - `layout->addSpacer(SpaceItem)`
- the Widget with a empty checkable **square** is a [QCheckBox](https://doc.qt.io/qt-5/qcheckbox.html)


# Bug report Form

This example is taken from [Qt Tutorial](https://doc.qt.io/archives/qq/qq25-formlayout.html). You task is to create the following form to report a problem.



<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/04_forms/form_report.png">
  <div class="figcaption">
  Dialog to report a form.
  </div>
</div>


# Grid Layout

For our final exercice, we will visit an imporant layout that we missed in
class.


- Check and read the documentation for the [QGridLayout](https://doc.qt.io/qt-5.15/qgridlayout.html)

- Once you've read it, try to construct the following calculator:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/04_forms/keypad.png">
  <div class="figcaption">
  Calculator using the Grid Layout.
  </div>
</div>


- The component showing the number is called a [LCDNumber](https://doc.qt.io/archives/qt-4.8/qlcdnumber.html)
- You may assume that at max it can contains **6 digits**. 
- Call the method `setMinimumHeight` on you LCDNumber to set a minimu height of
**80** pixels.


> Again we only want the form, in your next lab you will implement a functional
calculator.
