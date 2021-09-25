---
layout: page
title:  C++ Inheritance 
description:   Explore C++ inheritace and its variants types.
date: 2021/10/11

lecturers:
  - name:  Anass Belcaid
permalink: /inheritance/
---



* (toc)
{:toc}


## Definition.

**Inheritance** is a way to form new classes based on *existing* classes, taking
on their attributes/behavior.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture2/mammal_diagram.png" width="500">
  <div class="figcaption">
   A Class  UML diagram illustrating the notion of Inheritance.
  </div>
</div>

We can also see **Inheritance** as a:

- A way to indicate that classes are **related**.
- A way to share code between two or more related classes (**hierarchy**).


With this notion, a class can **extend** another class, abosrbing its
data/behavior.

in the **OOP** vocabulary, we say that:

- `Superclass` (base class): is the parent class that is being extended.
- `Subclass` (derived class): Child class that inherits from the superclass.
    - The subclass gets a copy of every field and method from the superclass.
    - Subclass can **add** it's own behavior and/or change inherited behavior.

The **QT** library make heavy use of this mecanism to alleviate the creation of
grpahical windows and applications. Here is a simple overview ot its principal
component.

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture2/qt_inheritance_diagram.png" width="600">
  <div class="figcaption">
  Inheritance  Class Diagram of the Qt library.
  </div>
</div>
`
From this diagram, we could, for example, check the relation between `QWidget`
,whish represents the base component of each graphical element, and the
`QPushButton` for a button that could be clicked.

The [QWidget](https://doc.qt.io/qt-5/qwidget.html) defines the basic behavior of a graphical component such as:

```cpp

bool enabled();  //if the component could be accessed
QFont font();    // the used font
QRect geometry(); // the occupied geometry
QSize maximumSize();   // define the maximum size
```

In the hierarchy, we consider the class [QAbstractButton](https://doc.qt.io/qt-5/qabstractbutton.html) to regroup all the properties and behavior of all the buttons  such as `QPushButton` or `QRadioButton`.

```cpp
QIcon icon();      // return the icon of the button
QKeySequence shortcut();  // return the keyboard shorcut to activate the button
bool checkable();        //predicate to verify if the button could be checked.
void toggle();          // an Added slot to inform other components
```

## Employee Example.

Lets consider a company with following **employee regulations**:

- All employees work 40 hours /week.
- Emplyees make $40,000 per year plus $500 for each year worked.
    - except for lawyers who get twice the usual pay.
    - Programmer who get the same $40k base but $2000 for each year
    worked.
- Employees have 2 weeks of paid vacation days per year.
    - except for programmers who get an extra week (a total of 3).

- Employees should use a yellow form to apply for leave.
    - Except for programmers sho use a pink form.
- Each type of employee has some unique behavior:
    1. **Lawyers** know how to sue.
    2. **Programmers** know how to write code.
    3. **Secretaries** know how to take dication.
    4. **Legal Secretaries** know how to take dication and how to file
       legal briefs. 

Here is the code for the **Employee** class:

```cpp
#define once
#include <string>
using std::string;

class Employee{
    public:
        Employee(string name, int years);
        virtual int hours()const;
        virtual string name()const;
        virtual double salary()const;
        virtual int vacationDays()const;
        virtual string vacationForm()const;
        virtual int years()const;

    private:
        string myName;
        int myYears;
};
```
And here is the **implementation** of these methods:

```cpp
#include "employee.h"

Employee::Employee(string name, int years){
    myName = name;
    myYears = years;
}

int Employee::hours() const{
    return 40;
}

string Employee::name()const
{
    return myName;
}

double Employee::salary()const
{
    return 40000.0 + 500 * myYears;
}

int Employee::vacationDays()const
{
    return 10;
}

string Employee::vacationForm() const
{
    return "yellow";
}

int Employee::years() const{
    return myYears;
}
```

Your task is to implement the **Lawyer** and **Programmer** classes:

- Lawyer:
    - A Lawyer remembers what **law school** he/she went to.
    - Lawyers make **twice** as much salary as normal employees.
    - Lawyers know how to **sue** people (unique behavior).

- Programmer:
    - Programmer make the same base salary as other employees, but
    they earn a bonus of **2k/year** instead of the usual **500/year**.
    - Programmers fill the **pink** form rather than the usual yellow
    one.
    - Programmers get **3 weeks of vacation**.
    - Programmers know how to write **code** as their unique
    behavior.


A **Cmake** starter code for this project  is in <a href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture2/employees.zip"> Employees.zip</a>.



## Single Inheritance.

The syntax of Inheritance in `cpp`, is as follow:

```cpp
class Derived : public BaseClass 
{
    //Additional attributs and methods
};
```

The associated **UML** [class diagram](https://en.wikipedia.org/wiki/Class_diagram) use a single simple arrow pointing on the base class:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture2/single_inheritance.png	">
  <div class="figcaption">
   Representation of Inheritance in the Uml diagram class.
  </div>
</div>



For example, the class diagram for our employee example will be as:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture2/employee_example.png" width="400">
  <div class="figcaption">
   UML Class Diagram for the proposed Employee example.
  </div>
</div>


We will give the implementation of the `Lawyer` class and leave you the
other as an **exercise**.

First we will create the **header** `lawyer.h` an declare the class:


```cpp
class Lawyer : public Employee
{
    public:
    //Decide on constructor (either inherit or reimplement)
    // See next section
    
    public:
    void sue(); //behavior
    virtual double salary();  //change the behavior of salary

    
    //Additinal attributes
    private:
    string school;
};
```

### Constructor Rules.


In C++03, constructors of a class are not allowed to call other constructors in an initializer list of that class. Hence, constructors for base class **cannot be directly exposed to derived classes**.

> Each derived class must implement constructors even if a base class
constructor will be appropriate.


Hence for our `Lawyer` class, we must add an appropriate constructor by adding
the following code in the header file:


```cpp
Lawyer(string name, int year, string school);
```

We should also add the **implementation** of this method on the `laywer.cpp` as
follow:


```cpp
Lawyer::Lawyer(string name, int year, string school)
{
    this->name = name;
    this->year = year;
    this->school = school;
}
```

We can remark that we are repeating code by inintializing the two attributes
**name** and **year**.

- C++11 allows constructors to other peer constructors(by **delegation**). This
allows constructors to add another constructor behavior with minimum code. We
could write the previsou constructor as follows:

```cpp
//Constructor with delegation to the base class
Lawyer::Lawyer(string name, int years, string school):Employee(name, years)
{
    this->school = school;
}
```

If you want to inherit the base class constructors (Java like) you could use the
following syntax:

```cpp
using BaseClass::BaseClass;
```

This is an **all-or-nothing** feature which means that  all of the constructors will be
inherited.


> An inherited constructor will be **shadowed** if the derived class reimplement
its own.


### Access Control.

Like `Java`, C++ offers three access control for the attributs or methods:

- **public**: Accessible everywhere from any class or code.
- **private**: Accessible only *within* the class.
- **protected**: Accessible within and for *child* classes. 

### Perils of Inheritance

Inheritance offer a fast way to reuse code and avoid repetition. But it's not
always best to use it.

Lets consider the following examples:

1. A class `Point3D` that  extends a `Point2D` by adding a **z** coordinate.
2. A class `Rectangle` that extends a class `Square`.
3. A class `SortedVector` that extends a simple unordered vector.

> Try to think, what could go wrong with these examples!!

- The method `distance` will be completely wrong for a **3D** point.
- The Rectangle class supports operations that `Square` should not like
`setWidth`.

- A `SortedVector` may change the behavior of a given method such as `insert`.
The user will try insert a value into a given index by will not find that value
there.

## Private and Protected Inheritance


Similar the *access specifiers* for attributes, **C++** offers three ways of
inheriting a class attributes and methods.

- **public Inheritance**: makes `public` attributes of the base class `public`
and the `protected` attributes remains `protected` in the derived class.


- **protected Inheritance**: makes `public` and the `protected` attributes of the base class
`protected`.

- **Private Inheritance** copies code from superclass but does not publicly
advertise that your class extends that superclass.

    ```cpp
    class Derived : private Base
    ```

    - Private Inheritance is one way of implementing the **has-a** relationship.
    - Good for cases when you want to inherit another class's code, but you don't
    want the outside clients to **randomly** call it.
    - For example have `Point3D` privately inherit from  `Point2D` and add a **z**
    coordinate functionality.

```cpp
//Base class
class Base{
public:
 int x;
proteced:
 int y;
private:
  int z;
}

//Public inheritance
class DerivPub : public Base{
// x  remains public
// y remains protected
// z in not accessible
}


//protected Inheritance
class DerivPro : protected Base{
// x is now protected
// y remains protected
// z in not accessible
}


//Private Inheritance
class DerivPriv : private Base{
// x is private
// y is private 
// z is not accessible
}
```


## Multiple Inheritance.

The concept of inheriting from different source is called `mulitple
inheritance`.

-  In general is **forbidden** in many OOP languages like `Java` but is allowed
in `C++`.

- Convenient as it allows code sharing from multiple sources.
- In the other hand, is can be buggy  and **confusing**. For example if both the
Base classes define the same attribute.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture2/multiple_inheritance.png" width="500">
  <div class="figcaption">
   Example of the IOstream class that uses multiple Inheritance.
  </div>
</div>

The syntax for inheriting from multiple base class is:

```cpp
class Name : public SuperClass1, public SuperClass2...
{
}
```
As an example, let's consider two simple classes according to the following
diagram:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture2/multiple_example.png">
  <div class="figcaption">
   UML Class Diagram for simple example on multiple inheritance.
  </div>
</div>


The starter **cmake** project is in <a href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture2/multiple_inheritance.zip"> mulitple_inheritance.zip</a>


The first class `A` is defined as:

```cpp
class A {
    protected:
      int a;
    public:
    //constructor
    A(int a):a(a){}
};
```

The second class is given by:

```cpp
class B{
    protected:
    int b;
    public:
    //constructor
    B(int b):b(b){}
};
```
1. Implement the `C` class by inheriting from A and B.
2. Implement the `diff` method which computes the difference between **a** and
   **b**.








