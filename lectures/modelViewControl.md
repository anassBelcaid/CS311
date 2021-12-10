---
layout: page
title:  Containers and the Model/View paradigm
description:   discover the set of Conainters and get your feet wet with the MVC pattern.
date: 2021/12/12

lecturers:
  - name:  Anass Belcaid

permalink: /lectures/widgets2/
---


* (toc)
{:toc}


## Introduction

In this lecture, we will dive deeper into some **advanced** Qt widgets. We will
check a set of **containers** to regroup a collection of widgets ( generally
called *items*). We did already have some experience with an advanced container
widget which is the [QTableWidget](https://doc.qt.io/qt-5/qtablewidget.html)
which inherit from the predefined container [QTableView](https://doc.qt.io/qt-5/qtableview.html).

We will check three basic containers:

- **list** : You already know what is a list.
- **Tree**: to manage a collection in the form of a tree.
- **Table** : to manage widgets in **2D** lattice array.


For each type, we will check **two variant**:

- **Item Based**: define a list in the simplest term and hold the set of
widgets.

- **Model Based**: A more advanced method using a full **model** to get its data
and serve simply as a view.

> The model based widgets use an advanced pattern [MVC](https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller) which makes it a
little complicated. We will only stratch the surface with those models.

## Items Based Widgets

First we will presnt the **item based** containers. Those widgets controls
themselves their contents.

### List Widgets

A [QListWidget](https://doc.qt.io/qt-5/qlistwidget.html#details) is a widget
that provides  an **item-based** list widget. As the name suggests,  those widgets could be anything
that inherits from the [QListWidgetItem](https://doc.qt.io/qt-5/qlistwidgetitem.html) class.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/windows-listview.png" width="300">
  <div class="figcaption">
   Representation of a list View on Qt.
  </div>
</div>

As the documentation suggest, we will list the important methods and properties.

- **Properties**:
    - `count` : holds the number of items
    - `currentRow`: index of the current item.
    - `sortingEnabled`: holds whether sorting is enabled.
- **Methods**:
    - `addItem(QString &)`: add a String item
    - `addItem(QWidget *)`: add a QListWidgetItem
    - `currentItem()`:  get a pointer to current item.

> I'll leave to rest as an exercise to practice reading the documentation. 

As an example, we will create the following **widget** to show the following
items:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/list_widget_browser.png">
  <div class="figcaption">
  Listing the set of browsers using a ListWidget.
  </div>
</div>


1. We want to associate an **icon** to each item.
2. Each time we click on the button, a Message dialog appear informing the user
   of the name of the **clicked** item.
3. Modify your widget to modify the clicked item **background** to `red`.

### Tree Widgets

A [TreeWidget](https://doc.qt.io/qt-5/qtreewidget.html) is container to present
items as a [Tree](https://en.wikipedia.org/wiki/Tree_(data_structure)). 

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture9/tree_images.png" width="300">
  <div class="figcaption">
  Representation of a simple tree.
  </div>
</div>

We will cover this structure **in detail** in next course. But for now, we will
remember the following points:

- A Tree Node has a value and a set of children.
- The top down node of the tree is called **root**.


For our Qt class, each item is a member of the class [QTreeWidgetItem](https://doc.qt.io/qt-5/qtreewidgetitem.html).

Here are a set of intersting functions for our class:

- `addTopLevelItem(QTreeWidgetItem *item)`: to add a node a top level of the
tree.

- `columnCount`: property to return the number of columns.

For a Item you can add a single or multiple children using one of the following
methods:

- `addChild(QTreeWidgetItem *item)`: to add a single item
- `addChildren(QList<QTreeWidgetItem *>)`: to add multiple children at the same
time.


Let's practice this containter, to create the following view for:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/tree3.png">
  <div class="figcaption">
  Example of a tree that we should construct.
  </div>
</div>


1. Create a Qt project, and inherits from the **QWidget** class.

2. Add a **QTreeWidget** as a central component:

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/QTreeWidget_ui.png">
      <div class="figcaption">
      Illustration of the ui for our class.
      </div>
    </div>

3. In the constructor **ten** items for each number.
    - In order to create an item, we use the following syntax:
    ```cpp
    auto one = new QTreeWidgetItem({"1"});
    auto two = new QTreeWidgetItem({"2"});
    ...
    ```
4. Set up the **root** node:
    ```cpp
    ui->treeWidget->addTopLevelItem(one);
    ```
5. Finally finish the structure of the tree by setting up the children:

    ```cpp
    // Add two as a child of one
    one->addChild(two);
    one->addChild(three);

    // adding four and five as children
    two->addChildren({five, six});
    ...
    ```

### Table Widgets

This will be, a short section, as you already used widget in your
**spreadsheet** project.


The problem of these widgets, is that the should manage their own contents. Let
Imagine for example, that we want to show the content of a folder. This is
perfect scenario for a **QTreeWidget** but the creation of the **hierarchy**
will be cumborsume.

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture9/dirview-example.png" width="500">
  <div class="figcaption">
  Directory Hierarchy using a QTreeWidget
  </div>
</div>


In this case, using an **MVC** pattern will really help.

----

## MVC Model

### Definition

### Example (Folder Model)

### List View

### Tree View

### Table View

### Personal Model(advanced)

## Wrap up

