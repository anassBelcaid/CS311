---
layout:  post
title: Rapid Dialog Design 
description: Learn to use Qt Designer for diaglogs
date: 2021/11/08
permalink: /designer/ 
lecturers:
  - name:  Anass Belcaid
---

* (toc)
{:toc}



##  Qt Designer

Qt is designed to **pleasant** and intuitive to **hand-code**, and it is not
unusual for programmer to develop *entire Qt* applications pruely by writing C++
source code. Still, many programmer prefer to use a **visual approach** for designing forms, becaud they find it more **natural** and *faster* than hand-coding. Also they want to be able to experiment with and change **design** more quickly and easily than is possible with hand-coded  forms.


[QT designer](https://www.url.com) expands the optiosn available to
programmers by providing a visual capability. Qt Designer can be used to
develop all or just some of an applicatin's **Forms** that are created using Qt
Designer end up as C++ code, so Qt Designer can be used as a  conventional tool chain to imposes no special requirements on the compiler.


In the lecture, we will present the **Qt Desginer** capabilities and
show the mecansims to incorporate its forms into a Qt project.


We will start by a simple `GoDialog` and then move to a more complicated
dialog with some dynamic expansion features. The third part of the lecture,
present the core of Message dialogs in Qt.

## GoDialog

In this section, we will use Qt Desinger to create a `Go to Cell` dialog shown
in the figure:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/go_dialog_preview.png">
  <div class="figcaption">
  Preview of the Go to Cell Dialog.
  </div>
</div>

First we, will create   a single project to show a basic `QDialog`. This
dialog will be emtpy and it our role to fill it components using our `ui`
model.


The main of the project is given as follow:

```cpp

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating a basic dialog
    auto D = new  QDialog;
 
    // Showing the dialog
    D->show();

    return a.exec();
}
```

Now, we want to add a form that contains the widgets. So 

- Select the project.
- Add new.
- Select `Qt Designer From`.
<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/designer_dialog.png" width="500">
</div>

- From the  select `Widget`.
- Name the form `godialog.ui`.

### Creating widgets

Using the *drag and drop* method, add the following components to your form:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/go_dialog_widgets.png" width="300">
</div>

> Do not spend any time **positioning** the widgets as you know that they will
by positioned  using a proper **Layout**.

Now, we will edit the **properties** of our widgets:

1. Click on the label, and the **Object Inspector**( the window on the right)
   change the following content:
   - `ObjectName`: label
   - `text`    : "&Cell Location"
2. Click on the Editor and change the following:
    - `ObjectName`: lineEdit
3. Click on the first button, and change:
    - `ObjectName`: okButton
    - `enabled` : false
    - `text`  : OK
    - `default` : true
4. Now for the second button:
    - `ObjectName` : cancelButton
    - `text`     : cancel
5. Click the form background to select the form itself.
    - `ObjectName`: GoDialog
    - `WindowTitle`: To to Cell

For now, the dialog looks fine, a final touch is to **associate** the
label the lineEdit. In order to do that, we will click on `Edit/Edits Buddies`
to enter a special mode that allows you set set **buddies**.

Click on the label and drag the red arrow line to the line editor, then releae.
The label should show `Cell location` (the & should disappear).


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/go_dialog_buddies.png">
</div>

### Laying Widgets

Now it is time to lay out the widgets on the form:

1. Select the `CellLocation` label and the `lineEdit` and select **Lay Out
   Horizontally**.
2. Select the `Spacer` the `OkButton` and the `cancelButton` and
   click on **Lay out Horizontally**.
3. The final task, is to select the form itself and click **Lay Out
   Vertically**. 
    - We want also to adjust the size to **preferred size**.

The Dialog should appear as follow:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl
  }}/assets/img/lecture6/go_dialog_layouts.png">
</div>

The red lines that appear on the form show the layouts that have been created.


Now we can add the **Tab order** (order of which the widgets will be
activated by cycling the tab key). Click on `Edit/Edit tab Order`. A number in
a blue rectangle will appear next to each widget that can accept **focus**
Click on the widget until you see the order you're looking for.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl
  }}/assets/img/lecture6/go_dialog_tab_order.png">
</div>

Now that we have a working a form, we will use the function
**setupUi(dialog)** that permits to a form to register its contents in a given
dialog:


Her is the modified  `main.cpp`:

```cpp
#include <QApplication>
#include <QDialog>
#include "ui_godialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating a basic dialog
    auto D = new  QDialog;

    //Setting the contentent of the diaglog using the form
    Ui::GoDialog ui;
    ui.setupUi(D);

    //showing the dialog
    D->show();

    return a.exec();
}
```

You should see the full dialog but notice the following points:

- If you enter `Atl-C` you will go automatically to the lineEdit (this is
the result of editing the buddies).

- The `Ok` Button is not activated.

- Try to cycle using `Tab` button to see the order of the buttons.



### (Optional IA, CS) Subclassing Forms 

We can make the dialog function properly by **writing some code**. The cleanest
way is to create a new class that **inherits** both `Qdialog` and
`Ui::GoDialog` and that implement the *missing functionality*.

We will create a new class called `GoCellDialog` with the following header
file:

```cpp
#ifndef GOCELLDIALOG_H
#define GOCELLDIALOG_H
#include <QDialog>
#include "ui_godialog.h"


//Multiple Inheritance (could be simply replaced by composition)
class GoCellDialog : public QDialog, public Ui::GoDialog
{
public:
    GoCellDialog( QWidget *parent=nullptr);

 private slots:
 //Automatic slot for the textChanged signal
    void on_lineEdit_textChanged();
};

#endif // GOCELLDIALOG_H
```

And here the implementation for the `GoCellDialog.cpp`:

```cpp
#include "gocelldialog.h"
#include <QRegExpValidator>

GoCellDialog::GoCellDialog( QWidget *parent): QDialog(parent)
{
    //Setting the ui
    setupUi(this);       // Drawback Im a form and QDialog in the same time


    //Connection
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);


    //regular Expression for the lineEdit (letter, digit, digit)
    QRegExp reg{"[a-zA-Z][0-9][0-9]{0,2}"};

    lineEdit->setValidator(new QRegExpValidator(reg, this));

}

void GoCellDialog::on_lineEdit_textChanged()
{
    //Activate the button if the input is validated
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
```
In the code below we used the following points:

-  [QRegExp](https://doc.qt.io/qt-5/qregexp.html) is store a [regular expression](https://en.wikipedia.org/wiki/Regular_expression) in order to accept only value that could refer to a *valid* cell.

- Once we defined our regular expression, we set `Validator` for the
line Edit using the previous regular expression.

- We also connected the `ok` and `cancel` buttons to the default slots
`accept` and `reject` on the Dialog class.

- A final point, is the use of **Automatic signal connexion** similar
to `Java` mechanism.


```cpp
on_objectname_signal
```

will  connect automatically to the special `signal` of the `objectName`.


For our example `on_lineEdit_textChange`, this slot will be triggered each time
the `text` of the `lineEdit` changes.

## Nested Layout (revisited)


Now we will consider the example `nestedLayout` in the layout lab:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/04_forms/nesting.png">
  <div class="figcaption">
  Nested Layout using the QtDesigner.
  </div>
</div>


> Now it is you turn to complete that form using the designer.


Here is the steps that you should respect:

1. In the **same project**, create a new `Qt Designer Form Class`, This will
   have both the **ui** files and the class files `.cpp` and `.h`.


2. Name you class `SearchDialog` and make it inherit from **QDialog**.

3. Place the widgets and lay them correctly.
4. Make the label a **buddy** of the lineedit.
5. Choose your tab order.
6. Save and show the dialog in the main function.
7. (Optinal): make the line edit accepts only names with **three** to **seven**
   letters.

## MessageDialog

[QMessageBox](https://doc.qt.io/qt-5/qmessagebox.html) is a commonly used modal
dialog to display some informational message and optionally ask the user to
respond by clickign any one the standad button on it. Each standar button has a
predefined caption, a role and return a predifined hexadecimal number.

We will learn how to show some basic **predefined** messages that
inherits from the **QMessageBox**.


### About


Let continue on our same project, and add simple form with a single button to
trigger the **about** message.


1. Add your first button with the following properties:
    - `ObjectName`: aboutButton
    - `Text`      : &About

A fast way to define your `automatic` slot for a given signal is to:

- select the button.
- select `go to slots`
- Choose the `clicked()` signal.

This will create an automatic function called:

```cpp
void on_aboutButton_clicked()
```

Fill this function with a `about` dialog that show information about you
application.


```cpp
void Messages::on_aboutButton_clicked()
{

    //Use of the message about
    QMessageBox::about(this, "About Message","This is a simple applicatin made by the Students");
}
```

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/about_dialog.png">
  <div class="figcaption">
  About dialog with an Ok button
  </div>
</div>

### About Qt

Now we move on, to another **about** dialog that show your Qt installation
information.


1. Add a second button called `aboutQtButton`.
2. On his `slot` add the following code to show the information about
   you Qt:


```cpp
void Messages::on_aboutQtButton_clicked()
{
   QMessageBox::aboutQt(this, "Your Qt");
}
```

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/about_qt.png" width="500">
  <div class="figcaption">
  Qt Information.
  </div>
</div>

### Critial

We will add a third button, to show these types of messages:

- `QMessageBox::critical(parent, title, Message)` to show a message informing
of a denger area or error.

- `QMessageBox::information(parent, title, message)` similar to **critial** but
with an friendly icon to show a normal information.


### Question

The third and intersting Message is an **question** message.

> Imagine when you want to quit an running up that could be processing important
files on you computer, a good application should *ask you to confirm* before
exiting the app.



Let's createa new button and name it `Quit`. This button should:

1. Show a dialog to the user asking him if he want to leave.
2. If the user click on the `Yes` Button, the application should `exit`.
3. Otherwise, the application show a thanks message for continuing using the
   app.



So in the custom **slot** for this button add the following code:


```cpp

void Messages::on_critialButton_clicked()
{
 auto reply = QMessageBox::question(this, "Exit dialog",
 "Do you want to leave our lovely app!")
}
```

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/question_message.png">
  <div class="figcaption">
  QMessgeBox::Question with two default buttons.
  </div>
</div>

This function return `STandardButton` containing the result of the user.

For our example if we want to know if the user clicked `yes` or `no` and act
accordingly, we will add the following code:


```cpp

//User clicked to yes
if (reply == QMessgeBox::Yes)
    qApp.exit();

else {  //user clicked to no

    QMessgeBox::information(this, "Thanks",
    "Thank you for using our app");
}
```

> Another intersting question is what is we need more answers, like `YesToAll`?


`QMessageBox::question` offer a fourth argument that specify the set of answers
to pop up to the user. For example, if want three response such as:

- Yes
- No
- YestoAll

we will create the Dialog as follow:

```cpp
    auto reply = QMessageBox::question(this, "Exit dialog",
                                       "Do you want to leave our lovely app!",
                                       QMessageBox::Yes | QMessageBox::No | QMessageBox::YesAll);
```

This will bring the following dialog:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture6/message_yes_all.png">
  <div class="figcaption">
  Showing more than one answer.
  </div>
</div>

## Wrap up

In this lecture, we showed how to use the **QT Desinger** for rapid dialog and
UI design. We illustrated its use with a simple form and show how to incoroprate
the content of a `ui` form into a dialog using either simple syntax or the
Inheritance. The last section focused on the class `QMessageBox` to get simple
information from the user such as a yes or no.

Next we will dive deeper into creating a fully featured application. Stay tuned.

