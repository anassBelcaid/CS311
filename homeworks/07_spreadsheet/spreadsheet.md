---
layout: page
title:  Application Using Main Window 
description:   Create a MainWindow based application using the designer.
date: 2021/11/16

lecturers:
  - name:  Anass Belcaid
permalink: /spreadsheet/
---




* (toc)
{:toc}

## Text Editor


For your first example, we will playing the **Desinger** for a fast application
creation. The application is from [Qt Examples](https://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html) and is a simple text editor program built around [QPlainText](https://doc.qt.io/qt-5/qplaintextedit.html).


<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/wordEditor.png">
  <div class="figcaption">
  Example for the main text editor.
  </div>
</div>

We will mainly use the **desinger** for a rapid design of it features. But if
you feel aventurious you can write all in using code.

Here is an overview of the menus:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/application-menus.png">
  <div class="figcaption">
  Set of menus for our application.
  </div>
</div>


### Creating the project.


First create a new project called `WordText` using the following steps:

1. Choose a `QT Widgets Application`.
2. Name your project `WordText`
3. Inherit now from **QMainWindow**.
4. Choose all the remaining default choices.


Open the form You'll see that it has now an empty **menu** and already a defined
**menu** and **satatus** bars.

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/empty_project.png" width="700">
  <div class="figcaption">
  First empty QMainWindow Project.
  </div>
</div>


### Icons


1. Add a **resource fil** and add a set of predefined icons from you choice.

### Menus

Using the designer add all the menues in the image description.

> To add a menu you simply enter its name. and you can edit its properties in
the **object Insepector**.

### Actions

Easy enough you can also add your actions to a menu by simply clicking the text
in the menu.
