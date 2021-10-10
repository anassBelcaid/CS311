---
layout: page
title: Drawing Shapes.
description: Use Polymorphism and Abstraction to draw shapes. 
date: 2021/10/19
lecturers:
  - name:  Anass Belcaid
permalink: /shapes/
---

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/shapes_drawing.png" width="500" height="200">
</div>



* (toc)
{:toc}


## Check you understanding.

The first list if for the students how want to **deepen** or (check) their
understanding of the basic mechanism of polymorphism.


### Polymorphism Mystery 1

The exercise is from [CodeStepByStep](https://www.codestepbystep.com/problem/view/cpp/inheritance/polymorphismMystery1) and fill the missing boxes.

### Polymorphism Mystery 2

Same question for  the second example
[CodeStepByStep](https://www.codestepbystep.com/problem/view/cpp/inheritance/polymorphismMystery2).



## Abstract Shape drawing

In this lab, we will use **polymorphism** and Abstraction to display shapes in
Canvas defined as `GWindow`. The [GWindow](https://cs.stanford.edu/people/eroberts/StanfordCPPLib/doc/GWindow-class.html#Method:drawOval) provides graphical window that supports simple graphics. It includes several methods to draw **lines**, **rectangles** and **ovals**. 

In order to draw all those objects using the same class (called `Artist`),
we will use polymorphism and abstraction to represents all these forms as an **abstract class** called `Shape`.



The starting code for this project is in <a href="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/shapes.zip"> shapes.zip </a>.



Here is the **UML class** diagram for this project:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/class_diagram.png" width="400">
  <div class="figcaption">
   UML Class diagram for the drawing shape model.
  </div>
</div>


Some remarks on this diagram:

1. The relation between `Shape` and `GPoint` is called an [Composition](https://en.wikipedia.org/wiki/Composition_over_inheritance) that indicates that an object of the class **Shape** has-a **GPoint** as it center.

2. The second intersting relation is the once that rely `Shape` and `GWindow`.
   This relation exists since one of the `Shape` methods (draw) uses a Gwindow
   as a parameter.
3. The third relation between the conrete class and the `Shape` is an
   **Inheritance class**.



the [GPoint](https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/GPoint.html) class is used to represent a positioin in the **2D** plan. The class two constructors and a `toString()` method to convert into a string.


```cpp
class GPoint{
public:
    GPoint(); 
    GPoint(double x, double y);

    string toString()const;
private:
double x;
double y;
};
```


### Class Shape

The class `Shape` is an **Abstract class** to regroup all the common features
between the shapes. For the case of simplicity, we will only keep the following
aspects:

- `GPoint` : the center of any shape.
- `area` : method to compute the area of the shape (pure function).
- `draw(GWindow)`: abstract method to draw the shape in a GWindow.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/abstract_shape_form..png" width="200">
  <div class="figcaption">
  Representation of an abstract class with a given center.
  </div>
</div>


Here is the content of this class:

```cpp
// Define the abstract class Shape
// to represent all the shapes
class Shape
{
public:
    //default constructor
    // create a shape in (0,0)
    Shape() : pos(0,0){}

    //Create a shape in (x, y)
    Shape(double x, double y): pos(x, y){}

    // Area of the shape (abstract)
    virtual double area() const = 0;


    //Drawing in a window
    virtual void draw(GWindow & canvas) const = 0;

    // modifiers
    void set_position(double x_pos, double y_pos)
    {
        pos.x = x_pos;
        pos.y = y_pos;
    }

    // Accessser
    double get_x_pos() const {return pos.x;}
    double get_y_pos() const {return pos.y;}

private:
        // position of the shape
        GPoint pos;
};
```

As you could read the two following methods are **pure**. Meaning that they mus
tbe implemented in the Inherited classes.

1. `double area()const = 0`
2. `void draw(GWindow &) const = 0;`


### The Ellipse class

Your first task is to implement the class `ellipse` that **inherite** from the
`Shape` class. In addition to its `center`,  the ellipse will be represented by
its

- `x_radius`
- `y_radius`

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/Ellipse.png"
  width="200">
  <div class="figcaption">
   An Ellipse represented by its center, and two radius.
  </div>
</div>


-  Check the method `drawOval` in the `GWindow` class. 

> Be careful about the arguments, especially the center and the radius.

### The Rectangle class.


Similar to the `Ellipse`, a **Rectangle** is a class  that inherits from the
`Shape` class and used to represented a rectangle with a given **width** and
**height**.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/Triangle_rep.png" width="200">
  <div class="figcaption">
  Representation of a Rectangle with a given center, height and width.
  </div>
</div>

> Look for a method called `drawRect` in **GWindow** but be careful about the arguments.


### Triangle class.

The final class, you should implement is the `Triangle` class. In order to
simply to drawing mecanism, we will only consider **equilateral** triangles.
Hence a trianle will be represented by  it **center** and **width** as shown in
the figure:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/rectangle.png" width="150">
  <div class="figcaption">
  Representation of a Triangle given its gravitational center and width. 
  </div>
</div>


> In order to draw this shape, you should look for `drawPolygon` whichs receives
a list of `GPoint`.



### Final form
Once you completed those classe correctly, make sure the programe outputs the
following form:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/objects.png" width="300">
  <div class="figcaption">
  Output of the program, if all the classes are implemented correctly. 
  </div>
</div>

### Coloreful shapes

Now suppose your boss suddently chaned his mind, and he wants a **colorful
shapes** as shown in the figure:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/colorful_objects.png" width="300">
  <div class="figcaption">
  Giving life to our shapes.
  </div>
</div>


> Think of a minimal change to your code in order to add this feature. 

This change will push you to **appreciate** the abstraction aspect of
programming.


## ChessBoard

If your feeling adventurious, change the `main.cpp` file in order to print
**chessboard**.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/03_shapes/chessboard.jpg">
  <div class="figcaption">
  A chessboard with pieces.
  </div>
</div>


- You'll have to draw and fill all the rectangles.
- You'll also need to add a new `Shape` in order to represents the pieces.

> Good luck.
