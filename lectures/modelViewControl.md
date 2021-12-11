---
layout: page
title:  Containers and the Model/View paradigm
description:   discover the set of Conainters and get your feet wet with the MVC pattern.
date: 2021/12/12

lecturers:
  - name:  Anass Belcaid

permalink: /lectures/widgets2/
---


* (toc)
{:toc}


## Introduction

In this lecture, we will dive deeper into some **advanced** Qt widgets. We will
check a set of **containers** to regroup a collection of widgets ( generally
called *items*). We did already have some experience with an advanced container
widget which is the [QTableWidget](https://doc.qt.io/qt-5/qtablewidget.html)
which inherit from the predefined container [QTableView](https://doc.qt.io/qt-5/qtableview.html).

We will check three basic containers:

- **list** : You already know what is a list.
- **Tree**: to manage a collection in the form of a tree.
- **Table** : to manage widgets in **2D** lattice array.


For each type, we will check **two variant**:

- **Item Based**: define a list in the simplest term and hold the set of
widgets.

- **Model Based**: A more advanced method using a full **model** to get its data
and serve simply as a view.

> The model based widgets use an advanced pattern [MVC](https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller) which makes it a
little complicated. We will only stratch the surface with those models.

## Items Based Widgets

First we will presnt the **item based** containers. Those widgets controls
themselves their contents.

### List Widgets

A [QListWidget](https://doc.qt.io/qt-5/qlistwidget.html#details) is a widget
that provides  an **item-based** list widget. As the name suggests,  those widgets could be anything
that inherits from the [QListWidgetItem](https://doc.qt.io/qt-5/qlistwidgetitem.html) class.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/windows-listview.png" width="300">
  <div class="figcaption">
   Representation of a list View on Qt.
  </div>
</div>

As the documentation suggest, we will list the important methods and properties.

- **Properties**:
    - `count` : holds the number of items
    - `currentRow`: index of the current item.
    - `sortingEnabled`: holds whether sorting is enabled.
- **Methods**:
    - `addItem(QString &)`: add a String item
    - `addItem(QWidget *)`: add a QListWidgetItem
    - `currentItem()`:  get a pointer to current item.

> I'll leave to rest as an exercise to practice reading the documentation. 

As an example, we will create the following **widget** to show the following
items:


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/list_widget_browser.png">
  <div class="figcaption">
  Listing the set of browsers using a ListWidget.
  </div>
</div>


1. We want to associate an **icon** to each item.
2. Each time we click on the button, a Message dialog appear informing the user
   of the name of the **clicked** item.
3. Modify your widget to modify the clicked item **background** to `red`.

### Tree Widgets

A [TreeWidget](https://doc.qt.io/qt-5/qtreewidget.html) is container to present
items as a [Tree](https://en.wikipedia.org/wiki/Tree_(data_structure)). 

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture9/tree_images.png" width="300">
  <div class="figcaption">
  Representation of a simple tree.
  </div>
</div>

We will cover this structure **in detail** in next course. But for now, we will
remember the following points:

- A Tree Node has a value and a set of children.
- The top down node of the tree is called **root**.


For our Qt class, each item is a member of the class [QTreeWidgetItem](https://doc.qt.io/qt-5/qtreewidgetitem.html).

Here are a set of intersting functions for our class:

- `addTopLevelItem(QTreeWidgetItem *item)`: to add a node a top level of the
tree.

- `columnCount`: property to return the number of columns.

For a Item you can add a single or multiple children using one of the following
methods:

- `addChild(QTreeWidgetItem *item)`: to add a single item
- `addChildren(QList<QTreeWidgetItem *>)`: to add multiple children at the same
time.


Let's practice this containter, to create the following view for:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/tree3.png">
  <div class="figcaption">
  Example of a tree that we should construct.
  </div>
</div>


1. Create a Qt project, and inherits from the **QWidget** class.

2. Add a **QTreeWidget** as a central component:

    <div class="center">
      <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/QTreeWidget_ui.png">
      <div class="figcaption">
      Illustration of the ui for our class.
      </div>
    </div>

3. In the constructor **ten** items for each number.
    - In order to create an item, we use the following syntax:
    ```cpp
    auto one = new QTreeWidgetItem({"1"});
    auto two = new QTreeWidgetItem({"2"});
    ...
    ```
4. Set up the **root** node:
    ```cpp
    ui->treeWidget->addTopLevelItem(one);
    ```
5. Finally finish the structure of the tree by setting up the children:

    ```cpp
    // Add two as a child of one
    one->addChild(two);
    one->addChild(three);

    // adding four and five as children
    two->addChildren({five, six});
    ...
    ```

### Table Widgets

This will be, a short section, as you already used widget in your
**spreadsheet** project.


The problem of these widgets, is that the should manage their own contents. Let
Imagine for example, that we want to show the content of a folder. This is
perfect scenario for a **QTreeWidget** but the creation of the **hierarchy**
will be cumborsume.

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/assets/img/lecture9/dirview-example.png" width="500">
  <div class="figcaption">
  Directory Hierarchy using a QTreeWidget
  </div>
</div>


In this case, using an **MVC** pattern will really help.

----

## MVC Model

For  a more **flexible** and **advanced** container widgets. Qt introduces the
[Model /View/ Control (MVC)](https://doc.qt.io/qt-5/model-view-programming.html)
paradigm. This is a [design pattern](https://en.wikipedia.org/wiki/Software_design_pattern) originating from Smalltalk that is often used when building **user interfaces**.

### Definition


> MVC consists of three kinds of objects. The **Model** is the application
object, the **View** is its scrren presenation, and the **Controller** define
sthe way the user interface reacts to user input.

Before MVC, user interface designs tented to lump these ojects together. MVC
**decouples** them to increase *flexiblity* and *reuse*.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/MVC3.png" width="500">
  <div class="figcaption">
  Architecture of the MVC model. With a Model that holds the representation data. The view to represent the data to the user. And finally the controller which define the user interface to modify the model
  </div>
</div>


The three main components of this model are:

1. **The model**: which holds the internal data for our application.
   Typically either in a *data structure* like an array or a *Database*.

2. **The View**: which offer a graphical reprsentation of the data like the ones
   we see such as **Tree** or **List** widgets.

3. **The controller**: which represents the brain for the application and
   takes responsibility for all the user interaction.


> Qt does not offer a (controller) but rather a **delegate**.
> The discussion why this model is more flexible than the classical (MVC) is
out of the scope of this course.


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/modelview-overview.png">
  <div class="figcaption">
  The model/view architecture with a <b>delegate</b>.
  </div>
</div>

Those components communicates with each other using **signals and slots**.

- Signals from the **model** inform the **view** about changes to the data held by the
data source.

- Signals from the **view** provide information about the users' **interaction** with
the items being displayed.

- Signals from the **delegate** are used during editing to tell the **model** and **view**
about the state of the editor.


#### Models

All the models are based on the [QAbstractItemModel](https://doc.qt.io/qt-5/qabstractitemmodel.html) class. This class define an **interface** that is used by views and delegate to access data.

Also **Qt** offers a set of basic models:

- [QStringListModel](https://doc.qt.io/qt-5/qstringlistmodel.html):
provides a model to store **QString**.
- [QFileSystremModel](https://doc.qt.io/qt-5/qfilesystemmodel.html):
provides a model to view the structure of a folder.
- [QStandardItemModel](https://doc.qt.io/qt-5/qstandarditemmodel.html): A
model for a general data structure data.
- [QSqlTableModel](https://doc.qt.io/qt-5/qsqltablemodel.html) and
[QSqlRelationalTableModel](https://doc.qt.io/qt-5/qsqlrelationaltablemodel.html): to manage a model with a given **sql** database.


> If any of those models could solve your problem, you have to create your
**own** class by deriving from the following base classes:


- [QAbstractItemModel](https://doc.qt.io/qt-5/qabstractitemmodel.html): The more basic and abstract model. Need for complex adaptation.

- [QAbstractListModel](https://doc.qt.io/qt-5/qabstractlistmodel.html):  A model for list based item.

- [QAbstractTableModel](https://doc.qt.io/qt-5/qabstracttablemodel.html): For a model that stores data in 2d array.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/modelview-models.png">
  <div class="figcaption">
  List of basic model with their specific indexation.
  </div>
</div>


#### Views

Once we have a model, we have three kind  of views ( as previously
stated).

- [QListView](https://doc.qt.io/qt-5/qlistview.html): a View for a list model.
- [QTableView](https://doc.qt.io/qt-5/qtableview.html): A view for a Table
model.

- [QTreeView](https://doc.qt.io/qt-5/qtreeview.html): A view for a tree like
model.


Once we declared a **view**, we can set up his model using **polymorphism**:

```cpp
void QAbtractItemModel::setModel(QAbstractItemModel * model);
```

### Example (Folder Model)

In order to simplify those concepts, we will create a widget to show the
structure of a given project using different **views**.


1. Create a project inheriting from a simple **widget** and add the following
   items to your form:

   - ListView
   - TreeView

   <div class="center">
     <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/File_system_ui.png">
     <div class="figcaption">
     Ui form for our filesystem view.
     </div>
   </div>
   
2. First in the **constructor**, we will create the
   **QFileSystremModel**:

   ```cpp
    // Creating the fileSystem model
    auto model = new QFileSystemModel();

    // Setting up the model at the current file
    model->setRootPath(QDir::currentPath());

    // Getting the index of the current folder
    auto index = model->index(QDir::currentPath());

   ```
3. Now that we have a model for our folder, we can create different
   view to see its contents:

   ```cpp
    // Seting up the list view
    ui->listView->setModel(model);
    ui->listView->setRootIndex(index);

    // Setting up the tree view
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(index);
   ```

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/file_system_output.png">
  <div class="figcaption">
  The output for our file system widget.
  </div>
</div>

   
1. Try to add the third **QTableWidget**.
2. Add a folder and a file in this folder to see the effect in the
   **TreeView**.



### Personal Model (advanced)

In this **optional** part, we will tackle the principle and mechanism for
creating you personal model by inheriting from the
**QAbstractTableModel**


The basic steps for this concept is 

1. Create a class by inheriting from  **QAbstractTableModel**.
2. Define the **abstract** method to return the number of item (rows) of our
   model
   ```cpp
   int QAbstractItemModel::rowCount(const QModelIndex &parent=
   QModelIndex())const;
   ```

3. override the function to return the content of a item.
    ```cpp
    QVariant QAbstractItemModel::data(const QModelIndex &index, int role
    = Qt::displayRole) const;
    ```

Let's show these concept, for a tabular model to print countries and their
capital.

Here is the **header file**.

```cpp

#ifndef CONTINENTMODEL_H
#define CONTINENTMODEL_H
#include <QAbstractTableModel>

class ContinentModel : public QAbstractTableModel
{
public:
    //Constructor with a list of towns
    ContinentModel(QStringList & items, QStringList &capitals, QObject *parent=nullptr);


    // Abstract methods to implement
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    QVariant data(const QModelIndex &index, int role)const override;


private:
      //define an enum for the columns
       enum Colonnes{ country = 0, capital = 1};
       QStringList items;
       QStringList capitals;
};

#endif // CONTINENTMODEL_H
```


Now there is the implementation of the constructor:

```cpp
// Simply store the list of countries and the capitals
ContinentModel::ContinentModel(QStringList &items, QStringList &capitals, QObject* parent):QAbstractTableModel(parent)
{
    if(items.length() > 0)
        this->items = items;
}
```


The implementation for the number of rows and columns is straightforward:

```cpp
int ContinentModel::rowCount(const QModelIndex &parent) const
{
    return items.length();
}

int ContinentModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}
```

And finally for the function to get the data:

```cpp
QVariant ContinentModel::data(const QModelIndex &index, int role) const
{
    //check if the inedex is valid
    if(!index.isValid())
        return QVariant();

    //check if is withing the bounds
    if (index.row()>items.count() || index.column()>=2)
        return QVariant();

    // set up the text.
    if (role == Qt::DisplayRole || role == Qt::EditRole)
        if(index.column() == country)
            return items.at(index.row());
        else if (index.column() == capital && index.row() < capitals.count())
            return capitals.at(index.row());

    return QVariant();
}

```

Now we are ready to use our model with all the **predefined** views:

```cpp

    //Creating the model
    QStringList pays;
    pays << "France" << "England" << "Morocco" << "Egypt" << "Brasil";
    QStringList capitals;
    capitals << "Paris" << "?" << " ?" << "?" << "?" ;
    ContinentModel *model = new ContinentModel(pays, capitals);

   //adding a view on this model
   auto view = new QTableView;
   view->setModel(model);
```


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture9/custom_model_view.png">
  <div class="figcaption">
   Final result for our custom Model view.
  </div>
</div>

## Wrap up

In this lecture, we cover a set of predefined **Item based** widgets
containers such as **List** and **Tree** Widgets. We dive deeper in a more
complex but flexible paradigm which is the (MVC) pattern. This principle
even is it is complex to create, it offer more flexibly and reuse by
separating the model from the view and the control of the data.

