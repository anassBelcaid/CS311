---
layout: page
title: Creating Main Windows 
description:   Create full application by subclassing the QMainWindow class
date: 2021/11/15 

lecturers:
  - name:  Anass Belcaid

permalink: /mainWindow/
---

The lecture will teach you how to create **main windows** using Qt. By the end, you will be able to build an application's **entire** user interface, complete with menus, toolbars, status bar and as many dialogs as the application requires.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/mainWindow.png">
  <div class="figcaption">
  Main components of a QMainWindow.
  </div>
</div>




## Table of Contents
* (toc)
{:toc}


## Introduction

An application's main window provides the **framework** upon which the application's user interface is built. We will base our lecture on the **Spreadsheet** application show in the figure:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/example_spreadsheet.png" width="500">
  <div class="figcaption">
  SpreadSheet Application.
  </div>
</div>


Behind most **GUI** applications lies a body of code that provides the
underlying functionality. For example, code to read and write files or to
process the data presented in the user interface. For this lecture we will
focus on creating the main skeleton and live the functionality for next lecture.

## Subclassing QMainWindow

The main component of an application is the
[QMainWindow](https://doc.qt.io/qt-5/qmainwindow.html). Many of the techniques
we saw in the previous lectures for creating dialogs and widgets are relevant
for creating main windows, since both `QDialog` and `QMainWindow` inherit from
`QWidget`.

> Generally mainWindow are creating using **Qt Designer**.

But for learning proposes, we will **code** everything to demonstrate how it's
done. If you feel **overwhelmed**  you can follow the tutorial using **Qt
Designer**.



So our, first setp is to create a **Qt project** (Yes now we are ready!). and
choose the following steps:

1. Qt Widgets Application 
2. Name the project `SpreadSheet`
3. Choose `qmake` as configuration tool.
4. Name the class `SpreadSheet`

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/config_spreadSheet.png" width="500">
      <div class="figcaption">
      Configuration of the main project
      </div>
    </div>

5.  **Do not check** the form. as we will be creating a **Main Functional**
    applicaiton.
6. Finish the creation by selecting all the **default** remaining options.


If you checked the code for the `spreadsheet.h`, you'lle see that we are now
subclassing a  [QMainWindow](https://doc.qt.io/qt-5/qmainwindow.html).

```cpp
#include <QMainWindow>

class SpreadSheet : public QMainWindow
{
    Q_OBJECT
public:
    SpreadSheet(QWidget *parent = nullptr);
    ~SpreadSheet();
};
```


Now our class contains only a `Constructor/ Destructor`, we will show **step by
step** how to add the components of our functional spreadsheet. But before to do
that let's gather some resources (figures) that will serve us as **Icons**.

## QResources Management systems

[The Qt resource Management system](https://doc.qt.io/qt-5/resources.html) is a
platform independent mechanism for storing binary files in the application's
executable. The is useful if you're application always needs a certain set of
files such as:

- icons.
- translations files.
- local database.

The Qt mechanism system is based on tight cooperation between **qmake** and [rcc](https://doc.qt.io/qt-5/rcc.html) (Qt resource compiler).

We will illustrate its use by adding the some **icons** to our application. So
here  a set of icons <a href="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/icons.zip"> icons.zip </a>. You're strongly advised to use your own if you want.


> Unzip all the images in the project folder.


1. Go to your project and click **add File**
2. Select **Qt Resource File** as shown in the figure:

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/resource_file.png" width="500">
      <div class="figcaption">
      Dialog for adding a new resource file.
      </div>
    </div>

3. You'll see a third section in your project called **resources**.
4. Select the `icons.qrc` file and select `Add existing files`
5. Select all the pictures, you want to add.
 
    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture7/icons.png" width="500">
      <div class="figcaption">
      Set of added icons.
      </div>
    </div>

> Now you're set up. Let's dive into the world of menus and actions.

## Creating menus and toolbars

Before creating any application, you need to **carefully**  think about it's
features and **Functionality**. This will give us a list of **actions** that the
application could perform ( It's ok to miss some of them as we could add them
later, but at least think
about   the essential ones).

**Exercice**:

Let's think about all the functionality of a SpreadSheet and list them:


1. It should be able to **create files**.
2. It can load or **open** new files.
3. Of course we have to **save** spreadsheets.
4. An application should be able to **close itself** (daaa)
5. Our application need to **Go** to any cell.
6. also **Find** a text.
7. An application should give information **about** (which version, who's the
   creator...)
8. The list could goes on, but we will work with those options.


### Actions
In applications many common commands can be invoked via menus, toolbar buttons, and keyboard shortcuts. Since the user expects each command to **be performed in the same way**, regardless of the user interface used, it is useful to represent each command as an action.

This mechanism is implemented in the [QAction](https://doc.qt.io/qt-5/qaction.html#details) which offer a way to perform an action trough different ways.

For our case we will add the following actions to our application according to
the previous discussion:

In the `spreadsheet.h` add the following declaration:

```cpp


private:  //private method
   void createActions();   //Function to create all the actions

private:
QAction *newFile;      //Action to open a new file
QAction *openFile;     //Action to open a new file
QAction *saveFile;     // Save the file
QAction *quit;         //Operation close
QAction *about;        //About the application
```


Now for the implementation on `spreadsheet.cpp`, we will create each action with
its associated **icons**. To avoid repeatability, we will show only one action:


The general philosophy to create an action is:


1. Create it's icon with 
    ```cpp
    QPixmap quitIcon("path");
    ```
2. Create the action with its given icon:
    ```cpp
    QAction(icon, "text", parent);
    ```
3. Connect the action to it's associated **slot**.
    ```cpp
    connect(actionName, &QAction::trigerred, 
             receiver, slot)
    ```

```cpp
//Function to create all the widgets
void SpreadSheet::createActions()
{
   //Create the icon
   QPixmap quitIcon(":/quit_icon.png");

   // Create the action
   quit = new QAction(quitIcond, "&Quit", this);


    //Optional set the shortcut
    quit->setShortCut(tr("Ctrl+Q"));

   connect(quit, &QAction::trigerred, 
   qApp, &QApplicaiton::exit);

}
```



### Menus



### Toolbar


## Setting up the status bar


## Calling Dialogs

