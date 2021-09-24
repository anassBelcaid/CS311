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




### Constructor Rules.


### Access Control.


## Multiple Inheritance.

## Private Inheritance


