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

### List Widgets

### Tree Widgets

### Table Widgets

## MVC Model

### Definition

### Example (Folder Model)

### List View

### Tree View

### Table View

### Personal Model(advanced)

## Wrap up

