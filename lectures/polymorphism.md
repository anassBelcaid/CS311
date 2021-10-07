---
layout: page
title: Polymorphism and Abstraction
description:   Defining a good class hierarchy for problem solving
date:  2021/10/18

lecturers:
  - name:  Anass Belcaid

permalink: /polymorphism/
---


* (toc)
{:toc}

## Polymorphism

### Definition

[Polymorphism](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)) is
the ability for the same code to be used with *different types* of objects and
behave differently with each.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture3/polymorphism.png" width="300">
  <div class="figcaption">
  Polymorphism on producing sounds for animals.
  </div>
</div>


In **C++** the behavior is achieved by:

1. **Templates** which provides a **compile-time** polymorphism.
2. **Inheritance** which provides a **run-time** polymorphism.

The main advantage is the 
> The client can call a method on different kind of objects, and the resulting
behavior will be different.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture3/simple_polymorphism.png" width="300">
  <div class="figcaption">
  Classical polymorphism example with shapes and squares.
  </div>
</div>

### Actual vs Declared type.

Now, we will present the mecanism of **pointers** in order to implement
**Polymorphsm**. First let consider the basic example of a Person / Student
heirarchy.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture3/person.png"
  width="120">
  <div class="figcaption">
   Simple Person Student Hierarchy.
  </div>
</div>


And now let's consider the example of constructing two objects using pointers.

```cpp
// Creation of  person using a person pointer
Person * P1 = new Person("Person1", 391, "Euromed");

//Creating a Student using a Student person
Student * P2 = new Student("Person2", 391, "Euromed", "CS", 4);

//More intersting  
Person *P3 = new Student("Person3", 391, "Euromed", "Mech", 5);
```

The last example, show an intersting concept which allows a base class pointer
to point on **derived class**.

> with this system, you can only use the methods and attributs on the bae class.

Let's code the diagram and execute the code. Here is the code for the person
class:

```cpp
//Class Person
class Person
{
/* private: */
    public: 
    int id;
    string name;
    string address;

public:
    Person(string , int , string);
    virtual void displayProfile()const;
};


Person::Person(string name, int id, string address):name(name),id(id),address(address)
{
}
void Person::displayProfile()const
{
    cout << string(40, '-') << endl;
    cout << "ID: " << id << " Name: " << name << " " <<  address << endl;
    cout << string(40, '-') << endl;
}
```

And here is the code for the **Student** class:


```cpp
// Class Student
class Student: public Person{
    private:
        int num_courses;
        string major;

    public:
        Student(string name, int id, string address, string major, int num_courses);
        void displayProfile()const override;
};

Student::Student(string name, int id, string address, string major, int num_cours):Person(name, id, address),major(major),num_courses(num_cours)
{
}

void Student::displayProfile()const
{

    cout << string(40, '-') << endl;
    cout << "ID: " << id << " Name: " << name << " " <<  address << endl;
    cout << "Major :" << major << "\t num courses: " << num_courses << endl;
    cout << string(40, '-') << endl;
}
```

With this example, what will  be the output of the following line:

```cpp
//More intersting  
Person *P3 = new Student("Person3", 391, "Euromed", "Mech", 5);
P3->displayProfile();
```

> To our big surprise, the line **doesn't show** the major course and the number
of courses. i.e the attributes of the **Student** class.


In order to solve the method, we should declare all the **overridden** methods
as `virtual`.


```cpp
virtual void displayProfile()const;  //delcared as virtual
```

### Polymorphism Examples

Let's practice the use of virtual methods with this simple example:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture3/rain.png"
  width="200">
  <div class="figcaption">
   Single Inheritance Diagram.
  </div>
</div>

For simplification, we will consider that each method will print the name of the
class followed by the number. 

For example the `method1()` of the class `Frog` will be like:

```cpp
class Frog
{
virtual void method1(){
  cout << "Fog 1" << endl;
}
};
```

and `method2` for the class `Sleet` will print:

```cpp
class Sleet
{
  virtual void method2()
  {
    cout << "Sleet 2" << endl;
  }
};
```


#### Question 1:

What will be the output of the following code:

```cpp
Snow* var1 = new Sleet();

var1->method1();
```

#### Question 2:

What will be the output of the following code:

```cpp
Snow* var2 = new Rain();

var2->method1();
```

#### Question 3:

What will be the output of the following code:

```cpp
Snow* var3 = new Rain();

var2->method2();
```


#### Question 3:

What will be the output of the following code:

```cpp
Snow* var4 = new Fog();
var4->method2();
```


### Constructor/Destructor

### Type casting

## Abstraction

### Abstract class

### Constructor/Destructor
