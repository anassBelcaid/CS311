---
layout: page
title:  Colliding Mice
description:   Draw a mouse using QPainter
date: 2022/01/12

lecturers:
  - name:  Anass Belcaid
permalink: /colliding/
---



<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/collidingmice-example.png">
</div>



* (toc)
{:toc}


##  Overview

The goal of this homework is to use you gained knowledge using the `QPainter` to
complete the [colliding mice example](https://doc.qt.io/qt-5/qtwidgets-graphicsview-collidingmice-example.html). The solution has already the **correct** code. You will be an **incpemplete** version with an `text` agent (simply showing the text). Your mission (if you choose to accept it) is the implement the 

```cpp
Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
```

to draw the mouse.


## Initial configuration


Download the initial project <a href="{{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/colliding.zip"> colliding.zip </a>.

If you investigate the code of the `Mouse` class, you'll find that that painter
only draw a text instead of the form of the mouse.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/mouses_texts.png" width="600" height="400">
  <div class="figcaption">
  Incomplete mouse example
  </div>
</div>



## Drawing the mouse


Now you should fill the method 

```cpp

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body (Construct the boy of the mouse)

    // Eyes 

    // Nose

    // Pupils

    // Ears

    // Tail ( You'll need Bezier curve for that)
}

```


## Transformations


The class `QPainter` offers a set of basic transformation like:

- `scale(sx, sy)` to scale the catesian coordinates by sx and sy.
- `rotate(angle)` to **rotate** axis by `angle`.
- `translate(dx, dy)`: to translate the axis by the vector (dx, dy)


To touch the power of those **transformations** try to produce the following
image:


<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/rotation_triangle.png" width="250" height="250">
  <div class="figcaption">
  The same form produced with different rotation angles.
  </div>
</div>


> Try to apply a translation to have the center O in the cener of the widget


```cpp

... 
auto h = height();
auto w = width();
painter->translate(w/2, h/2);

//Draw your shapes now

```

For a second example, you should apply both **rotation** and **scaling**


<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/rotate_scale.png" width="250" height="250">
  <div class="figcaption">
  Fibonacci Form using Rotation and Scaling
  </div>
</div>



## Fractral (revisit)

To check if you didn't forget your knowledge about **recurrence** try to produce
the following **fractal**.


<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/fractal.png" width="400" height="400">
</div>


Here is an illustration to show the **recursive** pattern:

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/09_colliding_mices/fractal_illustration.png" width="300">
</div>


