---
layout: page
title:  Gettting your feet wet with Qt 
description:   Qt Installation and contrainer manipulation.
date:  2021-10-05
permalink: /feetWet/
---

* (toc)
{:toc}


## Qt Installation

If you followed last year class on **Problem solving**, you're probabely setup
and ready to compile your programe. Feel free to jump to the problems sections
and test your knowledge on `QString` and `Constainers`.

### Windows Installation
Visit the open source download page at  [https://www.qt.io/download-open-source/](https://www.qt.io/download-open-source/). Click on **Downdload Qt** button and then select the **Downloads for open source users**.

1. Launch the utility installer.
2. Login to the Qt database system:

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture1/Qt_logging_preview.png" height="300">
</div>
3. Select the latest version of **Qt5**.

<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture1/qt_components_selection.png" height="300">
</div>

4. After the setup finish, launch `Qt Creator` program to run and compile your
   programs.

### Linux

#### Ubuntu base systems

First start by installing the **programmer tools**;

```shell
sudo apt install build-essential
```


Then we can install **Qt Creator** which automatically install **Qt** as a
dependency.

```shell
sudo apt install qtcreator
```

If you want to make **Qt5**  as your default Qt install the following package:

```shell
sudo apt install qt5-default
```

> If you want the documentation and the set of  examples:

```
sudo apt install qt-doc qt-examples
```

#### RPM based distributions

Install the **qt-devel** package


```shell
sudo dnf install qt5-devel
```


#### Arch Base


You'll have to install the **qtcretor** package

```shell
sudo pacman -S qtcreator
```

### Mac Os

1. Make sure your MacOs system is up to date.

2. Install the developer tools. Open a terminal an enter the following command:

```shell
xcode-select --install
```
3. Download the **qt creator** setup from [Qt creator installation page](https://www.qt.io/download-open-source#section-3)


<div class="center">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/lecture1/qt-creator-mac-install.gif" width="600" height="400">
</div>

4. Enter your email and password
5. Choose the **QT5** component.

## Strings


### Cities Coordinates

In this exercise, we will practice the use of the method `split` in the
**QString** class to read a [CSV file](https://en.wikipedia.org/wiki/Comma-separated_values). These type of files contain a set fields separated by commas.

The project of this exercise comes with a file `Morocco.csv` that stores
a set of attributes (like longitude or latitude) of a all the Moroccan cities.
The head of the file looks like

```
city,city_ascii,lat,lng,country,iso2,iso3,admin_name,capital,population,id
Casablanca,Casablanca,33.5992,-7.62,Morocco,MA,MAR,Casablanca-Settat,admin,4370000.0,1504175315
El Kelaa des Srarhna,El Kelaa des Srarhna,32.05,-7.4,Morocco,MA,MAR,Marrakech-Safi,,1450021.0,1504846488
Fès,Fes,34.0433,-5.0033,Morocco,MA,MAR,Fès-Meknès,admin,1112072.0,1504861997
Rabat,Rabat,34.0253,-6.8361,Morocco,MA,MAR,Rabat-Salé-Kénitra,primary,572717.0,1504023252
Tifariti,Tifariti,26.0928,-10.6089,Morocco,MA,MAR,,primary,,1504999990
Tangier,Tangier,35.7767,-5.8039,Morocco,MA,MAR,Tanger-Tétouan-Al Hoceïma,admin,947952.0,1504861504
Marrakech,Marrakech,31.6295,-7.9811,Morocco,MA,MAR,Marrakech-Safi,admin,928850.0,1504172585
Sale,Sale,34.05,-6.8167,Morocco,MA,MAR,Rabat-Salé-Kénitra,,850403.0,1504989034
Meknès,Meknes,33.8833,-5.55,Morocco,MA,MAR,Fès-Meknès,,520428.0,1504333193
Kenitra,Kenitra,34.25,-6.5833,Morocco,MA,MAR,Rabat-Salé-Kénitra,,431282.0,1504534876
```

The goal is to read this file, and print the 

- name
- longitude
- latitude
- population
of each city.

The information about each city should be printed like:

```
<city name> (long, lat) population = (<population>).
```

The symbol `< >` represents a **placeholder** that should be replaced by the real
value for each city.


The starting project of this exercice is in <a href="{{ site.url }}{{ site.baseurl }}/homeworks/01_feet_wet/cities_coordinates.zip">cities_coordinates.zip</a>


This project is without **tests**, you task is rather to implement each of the
following step in the **main** function.


1. In order to get the content of the file, you should create an [input file stream](https://www.cplusplus.com/reference/fstream/ifstream/).

    - The syntax to open an `ifstream` is 
    ```cpp
    ifstream In("name of the file");
    ```

    - In order to make sure that you file is opened, print the status of `In` using 

    ```cpp
    cout << In.is_open() << endl;
    ```
    This value should print **true**.

2. Next, we need to read the content of this file line by line. We will mainly
   use the function `getline(stream, string)` that read a line from any stream
   and stores it in **string**.

   ```cpp
   //reading the header
   string line;
   readline(In, line);

   //main loop to read all the remaining lines
   while ( readline(In, line))
   {
     
      //work with line 
   }
   ```

3. Now you task ( if you accepted) is to tranform each line using the [Split](https://doc.qt.io/qt-5/qstring.html#split) method to only print the mentioned fields. 


> An extra credit goes for students who uses  an `OOP` approach for representing
the city.


> Could you print all the cities sorted by their **population**.



### Alien Dictionary

In an alien language, surprisingly, they also use **English** lowercaes letters,
but possibly in a different `order`. The `order` of the alphabet is some
**permutation** of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of
the alphabet, return `true` if and only if the given `words` are **sorted**
lexicographically in this alien language.


For more information on lexicographical order, check the [wiki entry](https://en.wikipedia.org/wiki/Lexicographic_order).


The starting file is on <a href="{{ site.url }}{{ site.baseurl }}/homeworks/01_feet_wet/alien_dictionary.zip"> alien_dictionary.zip</a>.

**Example 1**

```shell
Input: words = ["hello","letscode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language,
then the sequence is sorted.
```

**Example 2**

```shell
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language,
then words[0] > words[1], hence the sequence is unsorted.
```


**Example 3**

```shell

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match,
and the second string is shorter (in size.) 
According to lexicographical rules "apple" > "app", 
because 'l' > '∅', where '∅' is defined as the blank character
which is less than any other character [More info on 
```



> If you feel stuck, check the documentation of the function [is_sorted](https://en.cppreference.com/w/cpp/algorithm/is_sorted). Also you need to check your background on **operator overloading**.


## Containers

### Minumun Moves

Given an integer array nums of size `n`, return the minimum number of moves required to make all array elements **equal**.

A move consist of **incrementing** `n-1` elements of the array by 1.

Example1:

```shell
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```


**Example 2**:

```shell
Input: nums = [1,1,1]
Output: 0
```

The starting code with some basic test is in <a href=" {{ site.url }}{{ site.baseurl }}/homeworks/01_feet_wet/minimum_moves.zip">minimum Moves.zip</a>.

> If you're feeling aventurious, try to come up with a non brute force
algorithm.
 
