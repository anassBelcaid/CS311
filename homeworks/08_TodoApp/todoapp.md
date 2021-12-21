---
layout: distill
title:  ToDo Application using containers
description:   Create a versatile Todo app using (Item/Model) based containers.
date: 2021/12/22

lecturers:
  - name:  Anass Belcaid
permalink: /todoapp/
---



<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/08_TodoApp/cover.png">
</div>



* (toc)
{:toc}



##  Overview

The goal of the **homework** is to create an **application** to manage you
tasks. It should have all the features of **main application** such as menues,
actions and toolbar. The application must store an **archive** of all the
**pending** and **finished** tasks. 


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/08_TodoApp/Overview_application.png">
  <div class="figcaption">
  Overview of our application.
  </div>
</div>


> This homework will be a little **different**, since I will not be giving
detailed instructions. Leaving you the responsibility and the **choices** to
create your own application. The only restriction is to respect the **use Case**
scenarios.

## Use Cases


Here is a list of **cases** that the user  could **perform** with our app:

1. A user should be able to **close** the application of course.
2. A Todo application cannot be useful, unless it offers the possibility  of
   **creating new tasks**.
   - The essential components of a task will be defined later

3. The View of the main widget should be **split** in **three** areas:

    1. The first (en persistent) area shows the list of **today** tasks.
    2. The second one is reserved for **pending** task (tasks for the future).
    3. Finally, the third one shows the set of **finished** tasks.

4. Each category must be shown with a **custom** icon.

5. The user could either `hide/show` the pending and finished views.

6. Finally, the tasks entered to your application must remains in the app in
   future use.

   > Meaning, If I create a task and I close the application, next time I opened
   the application, I should find my tasks and not start from scratch.

## Defining a Task

A  `Task` is defined by the following attributes:

- A `description`: stating the text and goal for the task like (Buying the milk).

- A `finished` boolean indicating if the task is Finished or due.
- A `Tag` category to show the class of the task which is reduced to the
following values:

    - Work
    - Life
    - Other

- Finally, a task should have a `DueDate` which stores the **Date** planned for the
date.


When the user create a new task, the application must **pop up** a dialog for
the user to get those values. Here is an example ( not mandatory, I prefer you
create your own) example:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/08_TodoApp/new_task_dialog.png">
  <div class="figcaption">
  An example of a dialog to get a new task.
  </div>
</div>


## Item Based Model

As a first attempt, You could use **Item Based** containers for the three
widgets.

## MVC Model

Once you finished the first version, Try to move on to more complicated model
using either


-  [QTableView](https://doc.qt.io/qtforpython-5/PySide2/QtWidgets/QTableView.html)
- [QAbstractTableModel](https://doc.qt.io/qt-5/qabstracttablemodel.html)
- [QSqlTableModel](https://doc.qt.io/qt-5/qsqltablemodel.html)


## Inhancements.


- Try to add functionality to move task between **views** (for elites)


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/08_TodoApp/happy_coding.png">
</div>

