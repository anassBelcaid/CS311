---
layout: page
title:  Application Using Main Window 
description:   Create a MainWindow based application using the designer.
date: 2021/11/16

lecturers:
  - name:  Anass Belcaid
permalink: /spreadsheet/
---




* (toc)
{:toc}

## SpreadSheet (Functionality)


### Context

In the lecture on **QMainWindow**, we wrote the code for the graphical and set
of actions for our main SpreadSeet application. Now we will focus on writing a
set of basic functionality.

 For the full Fonctionality, you'll need a deep understanding on inheritance
and 
   - [QTableSelectedRange](https://doc.qt.io/qt-5.15/qtablewidgetselectionrange.html)
   - Sorting using keys.
   - Introducing a formula for each Cell ( you must use Inheritance to
   specialize a QTalbeWidget).

> Those concepts are out of the scope of this course and will much of a lost of
time. But for  the curious programmer, they could try to achieve the full
functionality.



In the our last iteration of the SpreadSheet we did obtain an application with:

- Menu Bar
- Two tools bars
- Status bar to print the informations

You should have an application that looks like that :

<div class="centger">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/starter_image.png">
  <div class="figcaption">
  Starter Application with actions and menus.
  </div>
</div>



> If you missed or have a problem with the previous week, Here is the link for
the application (Preferably you should work with your own version to have a
feeling of completion!). 

Here is the <a href="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/SpreadSheet_01.zip">
Starter_code.zip</a>


#### Remarks

We did add the following modifications:

1. The `updateStatusBar` now takes two ints in order to syncrhonize 
with the selected item from the spreadsheet.
```cpp
void updateStatusBar(int, int) 
```

Here is the **implementation** of this function:

```cpp
void SpreadSheet::updateStatusBar(int row, int col)
{
    QString cell{"(%0, %1)"};
   cellLocation->setText(cell.arg(row+1).arg(col+1));

}
```

Which simply change the **cellLocation** text with the current cell
coordinates.

2. We added the `makeConnexion()` function to connect all the actions. Here
   is the content of the this function:

    ```cpp
void SpreadSheet::makeConnexions()
{

   // --------- Connexion for the  select all action ----/
   connect(all, &QAction::triggered,
           spreadsheet, &QTableWidget::selectAll);

   // Connection for the  show grid
   connect(showGrid, &QAction::triggered,
           spreadsheet, &QTableWidget::setShowGrid);

   //Connection for the exit button
   connect(exit, &QAction::triggered, this, &SpreadSheet::close);

   //connectting the chane of any element in the spreadsheet with the update status bar
   connect(spreadsheet, &QTableWidget::cellClicked, this,  &SpreadSheet::updateStatusBar);
}
```

### Go Cell 

Now we will add the function for the **goCell** action. For that, we need to
create a **Dialog** for the user to select a cell. 

> We did already achieved that in <a href="https://anassbelcaid.github.io/CS311/designer/#godialog"> Go Dialog </a>. 

If you lost that project, here are the steps to acomplish that:

1. Create a **Form Class**:

2. Using the designer obtain the following the form:

    <div class="center">
      <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/godidalog_ui.png">
      <div class="figcaption">
       Ui components of the Go Dialog.
      </div>
    </div>

3. Add the **regular expression** validator for the `lineEdit`:

    ```cpp
    //Validating the regular expression
    QRegExp regCell{"[A-Z][1-9][0-9]{0,2}"};

    //Validating the regular expression
    ui->lineEdit->setValidator(new QRegExpValidator(regCell));

    ```

4. Add a public **Getter** for the line edit Text to get the cell address:
    
    ```cpp
        QString GoCellDialog::cell() const
        {
            return ui->lineEdit->text();
        }
    ```

No we are setup to create the **interesting** connexion between the **goCell**
action:


1. First we will create the proper slot called `goCellSlot` to respond to the
   action **trigger**.

    ```cpp
    private slots:
    void goCellSlot();            // Go to a Cell slot
    ```
2. connect the action to its proper slot in the `makeConnexions` function:
    ```cpp
   //Connextion between the gocell action and the gocell slot
   connect(goCell, &QAction::triggered, this, &SpreadSheet::goCellSlot);

    ```
3. Now for the fun part. We will implement the `goCellSlot()` function:

    ```cpp  
    void SpreadSheet::goCellSlot()
    {
        //Creating the dialog
        GoCellDialog D;

        //Executing the dialog and storing the user response
        auto reply = D.exec();

        //Checking if the dialog is accepted
        if(reply == GoCellDialog::Accepted)
        {

            //Getting the cell text
            auto cell = D.cell();

            //letter distance
            int row = cell[0].toLatin1() - 'A';
            cell.remove(0,1);

            //second coordinate
            int col =  cell.toInt();


            //changing the current cell
            spreadsheet->setCurrentCell(row, col-1);
        }
    }
    ```
<div class="left">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/go_cell_query.png	">
</div>
<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/go_cell_response.png" width="400">
  <div class="figcaption">
  Go to Cell dialog and response.
  </div>
</div>

### Find Dialog

We will move now for the **Find** dialog. This dialog prompts the user for a
input and seek a cell that contains the entered text. 


1.  Create a **Form Class** with the following *ui*:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/find_dialog_ui.png">
  <div class="figcaption">
  Find Dialog ui form.
  </div>
</div>

2. Add a **Getter** to obtain the searched text.
3. Implements the connexion between the **dialog** and the **find** function:

Here is a set of useful information about the `QTableWidget` class:

- The method `rowCount()` gives the number of rows.
- The method `columnCount()` gives the number of columns in the spreadsheet.
- The Method `item(int i, int j)` return a pointer on the cell indexed by i and
j.
- If this pointer is not null, you could get its content by the method `text()`
which returns a `QString`.

- Finally, the method to change the  **focused** cell is 
    ```cpp
    spreadsheet->setCurrentCell(int i, int j);
    ```

<div class="left">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/find_cell_query.png" width="400">
</div>
<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/find_cell_response.png" width="440">
  <div class="figcaption">
  Find dialog illustration
  </div>
</div>





### Saving and loading files

For our final task, we will learn how to save the content of our spreadsheet in
a simple format. Since a spreadsheet is not forcefully **tabular**, it will be a
waste to save all the **empty** data. Hence, we will choose a simple format that
store the **coordinates** and the **content** of the non empty cells.

```
i1, j1, content1
i2, j2, content2
.
.
.
```

#### Saving Content

We will start by writing a **private** function `saveContent(QSTring filename)` to  save the content of our spreadsheet in a text file.

1. We will add the declaration in the   `header` file:

    ```cpp
    protected:
        void saveContent(QString filename)const;
    ```

2. For the implementation, we will using two classes:
    - [QFile](https://doc.qt.io/qt-5/qfile.html) which provides an interface to
    read and write in files.
    - [QTextStream](https://doc.qt.io/qt-5/qtextstream.html) for manipulating
    objects with a stream such as a file.

3. Here is  the complete implementation of this function:
    ```cpp
    void SpreadSheet::saveContent(QString filename) const
    {

        //Gettign a pointer on the file
        QFile file(filename);

        //Openign the file
        if(file.open(QIODevice::WriteOnly))  //Opening the file in writing mode
        {
            //Initiating a stream using the file
            QTextStream out(&file);

            //loop to save all the content
            for(int i=0; i < spreadsheet->rowCount();i++)
                for(int j=0; j < spreadsheet->columnCount(); j++)
                {
                    auto cell = spreadsheet->item(i, j);

                    //Cecking if the cell is non empty
                    if(cell)
                    out << cell->row() << ", "<< cell->column() << ", " << cell->text() << endl;
                }

        }
        file.close();
    }
    ```

#### Save File action

Now that we have an operational `saveContent` function, we could focus on the
slot itself.

So first we will create a **slot** to respond to the action trigger in the
header.

```cpp
private slots:
    void saveSlot();             //Slot to save the content of the file
```


Now we will add the connexion in the `makeConnexion` function:

```cpp
   //Connexion for the saveFile
   connect(save, &QAction::triggered, this, &SpreadSheet::saveSlot);
```


Finally for the interesting part, the implementation of the slot


```cpp

void SpreadSheet::saveSlot()
{
    //Creating a file dialog to choose a file graphically
    auto dialog = new QFileDialog(this);

    //Check if the current file has a name or not
    if(currentFile == "")
    {
       currentFile = dialog->getSaveFileName(this,"choose your file");

       //Update the window title with the file name
       setWindowTitle(currentFile);
    }

   //If we have a name simply save the content
   if( currentFile != "")
   {
           saveContent(currentFile);
   }
}

```


#### Load File

>Now it is your turn to write the implementation for the **load file** action.


That will be all for our humble application. In your free time, try to add more
functionalities.

------

## Text Editor

For your first example, we will playing the **Designer** for a fast application
creation. The application is from [Qt Examples](https://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html) and is a simple text editor program built around [QPlainText](https://doc.qt.io/qt-5/qplaintextedit.html).


<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/wordEditor.png">
  <div class="figcaption">
  Example for the main text editor.
  </div>
</div>

We will mainly use the **designer** for a rapid design of it features. But if
you feel adventurous you can write all in using code.

Here is an overview of the menus:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/application-menus.png">
  <div class="figcaption">
  Set of menus for our application.
  </div>
</div>


### Creating the project.


First create a new project called `WordText` using the following steps:

1. Choose a `QT Widgets Application`.
2. Name your project `WordText`
3. Inherit now from **QMainWindow**.
4. Choose all the remaining default choices.


Open the form You'll see that it has now an empty **menu** and already a defined
**menu** and **satatus** bars.

<div class="center">
  <img src=" {{ site.url }}{{ site.baseurl }}/homeworks/07_spreadsheet/empty_project.png" width="700">
  <div class="figcaption">
  First empty QMainWindow Project.
  </div>
</div>


### Icons


1. Add a **resource file** and add a set of predefined icons from you choice.

### Menus

Using the designer add all the menues in the image description.

> To add a menu you simply enter its name.  You can edit its properties in
the **object Inspector**.

### Actions

Easy enough you can also add your actions to a menu by simply clicking the text
in the menu.

### Functionality 
Now using your knowledge, try to code the functionality of the **Text Editor**.
Here is a link for [QPlainTextEdit](https://doc.qt.io/qt-5/qplaintextedit.html).


> Good luck
