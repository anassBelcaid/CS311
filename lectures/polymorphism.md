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


In order to achieve a class pointer association, the compiler stores a [Virtual table](https://en.wikipedia.org/wiki/Virtual_method_table). The **Vtable** stores stores pointers to all the virtual functions.

- The compiler create one table for each **class**.

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

A starter project to try these commands is in : <a href="{{ site.url }}{{ site.baseurl }}/assets/code/lecture3/snows.zip"> snows.zip </a>


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
Sleet* var4 = new Fog();
var4->method1();
```




### Constructor/Destructor

An interesting question involves the two classical methods
(constructor/destructor):

1. Should the **destructor** be virtual?
2. Should the **constructor** be virtual?

> Try to think about this question before reading the explanation.

The **destructor** must be `virtual` in order to clean up the mess created by
the subclass. Otherwise, we risk leaks in memory or resources!.



Let's consider the following example in <a href="{{ site.url }}{{ site.baseurl
}}/assets/code/lecture3/virtual_destructor.zip	"> virtual_destructor.zip</a>.
The code declare two classes. The first one called `Base` is as follow:


```cpp

class Base
{
    protected:
        int * nums;
    public:
        Base(int n);
        ~Base();
};

Base::Base(int n)
{
    nums = new int[n];
}

Base::~Base()
{
    delete [] nums;
}


```

We also use a derived class called `Derived` declared as follow:

```cpp
class Derived : public Base{

private:
    int * nums2;
public:
    Derived(int n, int m);
    ~Derived();
};


Derived::Derived(int n, int m):Base(n)
{
    //opening the file
    nums2 = new int[m];
}


Derived::~Derived()
{
   delete [] nums2;
}
```

The code is **correct** as each destructor is in charge of freeing its own
memory. **Base** delete `nums1` and **Derived** deletes `nums2`.

Using your deep understanding of overloading methods, what will be the problem
of the following code:


```cpp
    //Creating a derived class using the Base pointer
    Base * var = new Derived(4, 4);

    //calling the destructor
    delete var;
```


Without a virtual destructor, the compiler will call the destructor of the
mother class (`Base`). Therefore, the memory allowed for the second vector will
be **lost**!!.


> What about the constructor?

The constructor **cannot be** virtual, as it must know its exact type.



### Type casting

In addition to the **static_cast** that convert type in **compile** time, we can
use `dynamic_cast` with pointers to **downcast** pointers from a Base class to a
Derived class.


Let's revisit, the example of the `Person/Student`, where we add a method
`changeMajor` to the Student class.

The starter code for this example is in <a href="{{ site.url }}{{ site.baseurl
}}/assets/code/lecture3/Person2.zip">Person2.zip</a>


This method is not in the Person class, hence a pointer on `Person` cannot
access the `changeMajor` method. For example the code will give an error:

```cpp
    Person * P1 = new Student("Steve", 321, "Euromed", "CS", 4);
    P1->displayProfile();


    P1->changeMajor("PH"); //error P1 no changeMajor
    P1->displayProfile();
}
```

In order to solve this problem, we could use the **dynamic_cast** which have the
following syntax:

```cpp
newType = dynamic_cast<newType>(expression);
```


For our example, we need to convert a pointer `Person*` into student pointer
`Student*`. Hence the syntax will be:

```cpp
Student * P2 = dynamic_cast<Student*>(P1);

//Now we could use Student methods
P2->changeMajor("PH");   // Works perfectly
```
## Abstraction

### Abstract functions

Abstraction is one of the most essential and important feature of Object Oriented
Programming. Abstraction means displaying only **essential information** and
hiding the details.


For example, let's consider the process of a man **driving a car**. The man only
knows that pressing accelerators will increase the speed of the car and pressing
the brakes will slows down the car. He **does not know** about the inner
mecanism of the car.

We can apply this mecanism in C++ using inheritance and virtual method. First,
we need to define the notion of an `abstract method`.

> An abstract function is a method without implementation.

Why would someone uses an abstract method. It helps to **decouble** the
implementation from the interface.

For example in the car analogy, we will have:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture3/image.png">
  <div class="figcaption">
  The method accelerate and break must be abstract as we don't know yet how to
  implement them.
  </div>
</div>


In the following example, the methods `acceelerate` and `break` are **abstract**
since their impplementation will be left to the Derived classses.

In C++, an abstract class must be **virtual** followed by `=0` to declared that
it doesn't have an implementation yet.


```cpp

class Car{
  virtual void accelerate() = 0;  // declare accelerate as abstract
  virtual void break ()  = 0;
}
```


### Abstract class

A class that has one or more  **abstract method** is called `Abstract class`.

-  An abstract class **cannot be instantiaed**. 


```cpp
Car C = new Car();     //Cannot do this!!!
```


- The derived class must implement **all the abstract methods**.
- If a derived class, did not implemented all the abstract functions, it will
still **abstract**.

Let's consider this example in code from <a href="{{ site.url }}{{ site.baseurl
}} ../assets/code/lecture3/CarExample.zip"> Car Example.zip </a>
. Suppose the cose of the `Car` class is
given as follow:


```cpp
class Car
{

    protected:
        int num_wheels;
        int speed;
    public:
    Car(int num_wheels);
    virtual  void accelerate() = 0;
    virtual void Break() = 0;

    friend ostream &operator<<(ostream &, const Car &);
};
 
ostream & operator<<( ostream & out, const Car & C)
{
    out << "Car  [speed] : " <<   C.speed ;
    return out;
}

Car::Car(int num_wheels):num_wheels(num_wheels)
{
  
}
```

And suppose the code of the `Mecanial` Car is given as follow:

```cpp
class Mecanical : public Car
{

    using Car::Car;

    void virtual accelerate()override; //implement the method accelarate
    
};

void Mecanical::accelerate()
{

    speed += 2;
}
```
The following code will give an **error**!!:

```cpp


   //What should we fix in order to instantiate this class
   Car *C = new Mecanical(4);
   cout << *C << endl;

   C->accelerate();

   cout << *C << endl;
```

> What seems to be the problem?


Since the class `Mecanical` didn't implemented the `Break` method which was
**abstract**. The class itself is **abstract**. Hence it cannot be instantiated.
We could fix the problem by implementing this method We could fix the problem by
implementing this method.

### Constructor/Destructor

An intersting question is:

> Since an abstract class, cannot be instantiated. Why should we give it a
**Constructor**?


The answer is `Yes`. We still use it to create the common parts that will be
inherited from the derived classes.


Consider the example of the Car:
```

Car::Car(int num_wheels):num_wheels(num_wheels)
{
}
```

Even a Car, will never be instantiated. It is useful to have a base constructor
which will instantiate the common parts (for our case the *wheels*).


That is for **Abstraction**, We will revisit this subject heavily in the **next
semester course**!.
