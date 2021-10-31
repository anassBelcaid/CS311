---
layout:  page
title: Gui Dialog Design with Qt designer
description:   use the Qt designer to create form and merge them to dialogs
date:  2021/11/10

lecturers:
  - name:  Anass Belcaid

permalink: /rapidgui/
---


* (toc)
{:toc}


## Dynamic Dialogs

The goal of the exercise is to create  a simple [Extension Dialogs](http://dialogextension.com/). Those dialogs present a simple appearance but have a **toggle button** that allow the user to switch between the dialog's simple and extended appearances. Those dialogs are commonly used for application that are trying to cater both **casual** and **power user**. A simple example for that is you system calculator.

The goal is create a Sorting dialog like this one:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/06_designer/dynamic_dialog.png">
  <div class="figcaption">
  Extension Dialog to show more sorting options.
  </div>
</div>


The dialog is a **Sort dialog** in a spreadsheet application, where
the user can select one or several columns to sort on. the dialog's simple
appearance allows the user to enter a single key, and its extended appearance
provides for two extra sort keys. A **More** button lets the user switch
between the simple and extended appearances.

1. First Create the simple Form:

    
    <div class="center">
    <img src="{{ site.url }}{{ site.baseurl }}/homeworks/06_designer/simple_dialog.png">
    <div class="figcaption">
    Layouts for the simple form
    </div>
    </div>

2. Now, add the extension widgets:

    <div class="center">
    <img src="{{ site.url }}{{ site.baseurl }}/homeworks/06_designer/extended_dialog.png">
    <div class="figcaption">
    Layouts for the extended form
    </div>
    </div>



3. Make sure that the two second groups are **deactivated** by defaults

4. Now try to find the correct connexion in **Qt designer** that connect the

```
More , clicked,  second group , activated.
```

Here is hint for the final connexions you should create:

<div class="center">
<img src="{{ site.url }}{{ site.baseurl }}/homeworks/06_designer/dialog_signals.png">
<div class="figcaption">
Signals for the extended dialog.
</div>
</div>


## Bug report (revisited)

The goal of this simple exercise is to **reproduce** the Bug form using **Qt
Designer** adding some functionality and *refinement* to the form.


1. First create a **QDialog** using `Qt Designer` class to create the following
   form:

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/homeworks/04_forms/form_report.png">
      <div class="figcaption">
      Bug Form
      </div>
    </div>
    
2. Add a Slot to the **reset** button.
    - First, this function should show a Message asking the user, if he is
    **surely** want to delete all the content.
    - If the user **confirms**, all editing widgets **text** should be deleted.
    - If the user **cancel**, nothing will happen.

3. The **name** field should have (firstName secondName). 
    - First name cannot have digits or symbols
    - Same goes for last name.
    - You'll need a **regular expression** to do that and the rest.
4.  The email **validator** is a little tricky (so we'll skip it for now)
5. The **Submit** button should save the content in a file ( or a database!)
6. (Optional) The Phone number should 10 digits following our convention.



## Calendar Widget

In the last exercice, your are asked to create the following widget:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/06_designer/calendarwidgetexample.png">
  <div class="figcaption">
  Calendar Widget Example.
  </div>
</div>


This example is taken from [Qt Examples](https://doc.qt.io/qt-5/qtwidgets-widgets-calendarwidget-example.html)


> You do not have to implement all the slots but try to respect the following
points.

1. Respect the **layouts**.
2. You should create a `Qt Form class`
3. Rspect the **shortcut** for each widget.
4. Add the connexion between the **preview** and **current date**
5. (Optional) Add the connexion between **weeks start on** and the **preview**.
6. (Optional) Add the connexion between **Weekday** color and the preview.
