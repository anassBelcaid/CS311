---
layout: page
title:  Painting with QPainter
description:   learn how to draw objects and shapes using differnt styles and transformations
date: 2022/01/05

lecturers:
  - name:  Anass Belcaid

permalink: /lectures/painting/
---



<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/affine-demo.png" width="500" height="400">
</div>

----

Qt's **2D graphics** is based on the [QPainter](https://doc.qt.io/qt-5/qpainter.html) class. **QPainter** can draw *geometric* shapes (points, lines, rectangles, ellipses, arcs and cords ...) as well as **pixmap**, images and **text**. Furthermore, `QPainter` support advanced features such as **anti aliasing** (for text and shapes in edges), alpha blending, gradient filling, and vector paths. `QPainter` also support **transformations**, which makes it possible to draw resolution-independent 2D graphics.


`QPainter` can be used to draw on a **paint device**, such as a `QWidget`, a
`QPixMap`, or `QImage`. Using polymorphism, this will come in handy, if you
create your custom widgets. `QPainter` can also be used in conjunction with
`QPrinter` for **printing** and generating **PDFs**. This means that we can
often use the same code to display data on screen and to produce printed
reports.

> An alternative to QPainter is the standard library [openGL](https://www.opengl.org/). The `QtOpenGL` modules makes it very easy to integrate OpenGL code into Qt applictions.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/blanchette_diagram.png">
</div>


## Painting with QPainter
To start painting to a paint device ( typically a **QWidget**), we
simply create a `QPainter` and we pass a **pointer** to the device. For example:

```cpp
void MyWidget::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   ...

}
```

Let's illustrate this mechanism to draw a  set of **lines** in a widget.

> Create a **Widget** based project and add the following **protected**
functions.


```cpp
protected:
void paintEvent(QPaintEvent *e) override;  //classical now
void drawLines(QPainter *e);   //fonction to draw the lines
```

Here is the implementation of the **overridden** function

```cpp
void Widget::paintEvent(QPaintEvent *e)
{
    //Setting a QPainter on the current widget
     auto painter = new QPainter(this);

     //Instruct the painter to draw the lines
     drawLines(painter);
}
```

And now for the function to draw the lines:

```cpp
void Widget::drawLines(QPainter *P)
{
    //Setting the pen (color, pen width, pen style)
    QPen pen(Qt::black, 2, Qt::SolidLine);
    P->setPen(pen);

    P->drawLine(20, 20, 450, 20);


    //Now we will change the pen style
    pen.setStyle(Qt::DashLine);
    P->setPen(pen);
    P->drawLine(20, 40, 450, 40);


    //Now we will change the color
    pen.setColor(Qt::red);
    P->setPen(pen);
    P->drawLine(20, 60, 450, 60);
}
```

This will produce the following picture:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/lines_simple.png" height="200">
  <div class="figcaption">
   Widget with simple lines.
  </div>
</div>


> Change the code, to produce the first picture in zetcode tutorial:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/lines_zetcode.png"	>
  <div class="figcaption">
  Picture of the first example.
  </div>
</div>

We could draw various shapes using `QPainter` functions. Here is a figure
showing the most used ones:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/most_used_draws.png" width="350">
  <div class="figcaption">
  Most used function to draw shapes in the QPainter class.
  </div>
</div>

Try to get you hand on those function by drawing the following shapes:

1. Second example in zetcode page:

    <div class="center">
      <img src=" {{ site.url }}{{ site.baseurl
      }}/assets/img/lecture10/colours.png">
      <div class="figcaption">
      Rectangles with colours
      </div>
    </div>
    
2. Growing rectangles with a `for` loop:


    <div class="center">
      <img src=" {{ site.url }}{{ site.baseurl
      }}/assets/img/lecture10/growingRectangles.png" width="200" height="200">
      <div class="figcaption">
      Growing rectangles.
      </div>
    </div>



The properties of the `QPainter` are controlled by a 

- [QPen](https://www.url.com): controls the drawing properties.

    <div class="center">
      <img src=" {{ site.url }}{{ site.baseurl
      }}/assets/img/lecture10/pen_styles.png" width="400">
      <div class="figcaption">
      List of pen styles.
      </div>
    </div>


- [QBrush](https://doc.qt.io/qt-5/qbrush.html): controls th e **fill** pattern.

    <div class="center">
      <img src=" {{ site.url }}{{ site.baseurl
      }}/assets/img/lecture10/brush_styles.png" width="400">
      <div class="figcaption">
      Brushes styles.
      </div>
    </div>


Let's  see a few examples in practice. Let's try to produce the following
picture:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/brushes_examples.png">
  <div class="figcaption">
  Geometric shape examples.
  </div>
</div>


- Let's start with example **(a)**:
    
    ```cpp
    painter->setRenderHint(QPainter::Antialiasing, true); // antialiasing
    painter->setPen(QPen(Qt::black, 12, Qt::DashDotLine )); // pen 
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern)); // brush
    painter->drawEllipse(80, 80, 400, 240);  // drawing the ellipse
    ```
- Now for the second part (b):
    ```cpp
    painter->setPen(QPen(Qt::black, 15, Qt::SolidLine, Qt::RoundCap,
                        Qt::MiterJoin)); // a little advanced choosing a cap
    painter->setBrush(QBrush(Qt::blue, Qt::DiagCrossPattern));
    painter->drawPie(80 + 500, 80 , 400, 240, 60 * 16, 270 * 16);
    ```

- Finally for the last part (c):
    ```cpp
QPainterPath path; //Creating a path of points
path.moveTo(80, 320); // moving the first points
path.cubicTo(200, 80, 320, 80, 480, 320);
painter.setPen(QPen(Qt::black, 8));
painter.drawPath(path)
    ```
The `QPainterPath` class can specify arbitrary vector shapes by connecting basic graphical elements together: straight lines, ellipses, polygons, arcs, quadratic and cubic Bézier curves, and other painter paths. Painter paths are the ultimate drawing primitive in the sense that any shape or combination of shapes can be expressed as a path. 

Here is a second example from the documentation 

```cpp
QPainterPath myPath;
myPath.cubicTo(c1, c2, endPoint); //Besier curve from starting point to end pint
...
painter.drawPath(myPath);
```

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/qpainterpath-cubicto.png">
  <div class="figcaption">
  Bezier Curve from the starting point to the end point using c1 and c2 as
  controls.
  </div>
</div>

### Gradients

Qt supports three types of gradients:

- linear
- radial
- conical

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/gradients.png" width="500" height="300">
  <div class="figcaption">
  Set of predefined gradient on QPainter.
  </div>
</div>

- For **linear gradient**, we specify **two** controls points and a series of
`colors` on the line that connects these two points. For example the linear
gradient in the previous figure is created using the following code:

    ```cpp
    QLinearGradient gradient(50, 100, 300, 350); // gradient between (50,100) and (300, 350)
    gradient.setColorAt(0.0, Qt::white); //color at 0
    gradient.setColorAt(0.2, Qt::green); //color at 0.2
    gradient.setColorAt(1.0, Qt::black); //color at end


    //filling a region using the declared gradient
    painter.fillRect(20, 20, 300, 90, gradient);
    ```

- **Radial gradients** are defined by a center (x_c, y_c) a radius r and
a **focal point**.

- **Conical gradients** are defined by a center (x_c, y_c) and an angle
**a**. The colors spread around the center point like the **sweep** of a
`watch`.

In order to understand those gradients try to produce the following figures:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/linear_gradients_example1.png" width="300" height="300">
</div>


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture10/radialgradient.png" width="300" height="300">
</div>






