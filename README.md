# TARvg17

### Homework - Perimeter and Area of quadrilateral by 4 Points
Найти периметр и площадь четырехугольника на основе 4х Точек

[Homework base:](https://github.com/Anaga/TARvg17/blob/master/PointsHomeWork/main.cpp "Основа домашней работы")

У нас есть структура Точка - координаты точки и ее имя

```javascript
struct Point{
    float x;
    float y;
    char Name;
};
```

Точеки обеденыне по 4 в массив
```javascript
    Point quadOne[4];
    
    quadOne[0].Name='A';
    quadOne[0].x=0.0;
    quadOne[0].y=0.0;
    
    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=0.0;
    
    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;
    
    quadOne[3].Name='D';
    quadOne[3].x=0.0;
    quadOne[3].y=4.0;
```

написать тела функций:
```javascript
float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter  usind function 'distance' 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD
```

* Первая - возвращяет растояние между двумя точками по формуле sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) ) 
* Вторая - находит периметр как сумму 4х отрезков: (AB + BC + CD + DA) 
* Третия - находит площадь четырехугольника по точками используя формулу Гауса, или же, делит четырехугольник на 2 треугольника,  
 и находит его площадь как сумму 2х треугольников - ABC + ACD 
 площадь треугольников, зная длины сторон, можно найти по формуле Герона. 

Ссылки: 
* [Gaus formula](https://en.wikipedia.org/wiki/Shoelace_formula) 
* [Формулa Гауса](https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D0%B8_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0)
* 
* [Heron formula](https://en.wikipedia.org/wiki/Heron%27s_formula) 
* [Формулa Герона](https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%93%D0%B5%D1%80%D0%BE%D0%BD%D0%B0)

Результаты вычислений записать в текстовый файл, вывод такой:

> "Quadrilateral with points: A[0;0] B[4;0] C[4;4] B[0;4] " 
> "Have perimeter 16.00 and area 16.000" 
>  
> "Quadrilateral with points: E[-10;-10] F[10;-10] G[10;10] H[-10;10] " 
> "Have perimeter 80.00 and area 400.00" 


 первые точки для проверки - A[0;0] B[4;0] C[4;4] B[0;4] и  E[-10;-10] F[10;-10] G[10;10] H[-10;10]  

 но будут еще.


# 2DArr
## app for class work 03.10.2018
Arrays in C++, one dimensional and two dimensional arrays

# Pointys
## app for class work 03.10.2018
Structurs, on Point example:

```javascript
enum Color{ Red, Green, Blue };

struct Points{
    int x;
    int y;
    Color col;
};
```

function to print one point to std and to QString
```javascript
QString printPoint(Points a){
    QString qsTemp = "Point [%1;%2] \n";
    cout << "Point ["<< a.x << ";"<< a.y<< "] " ;
    qsTemp = qsTemp.arg(a.x).arg(a.y);
    Color c = a.col;
    switch (c) {
    case Red: cout << "Red"; break;
    case Green: cout << "Green"; break;
    case Blue: cout << "Blue"; break;
    default:cout << "Error"; break;
    }
    cout << endl;
    return qsTemp;
}
```

and a part to made new text file and print point to file:
```javascript
    QFile qf("PointList.txt");
    if (qf.open(QFile::WriteOnly | QFile::Truncate)) {
          QTextStream out(&qf);
          out << "Hello \n" ;

          for (int i=0; i<4; i++) {
              out << printPoint(PArr[i]);
              out << endl;
          }
      }
```


# Role Dice 
## app for class work 26.09.2018

The game DUNGEONS & DRAGONS use set of dices with meny numbers, from 4 till 20

[https://www.google.com/search?q=dnd+dice+set](https://www.google.com/search?q=dnd+dice+set)


We made an application, what can return random number from 1 to N, and N is one on set [4, 6, 8, 10, 12, 20, 100]

also we spore results in array, so we can print it.


*main new topics*
- [ ] enum
- [ ] Random

*topic to practice*
- [ ] Functions
- [ ] Loops

### Homework - Array Join
You  shall write a function to join 2 sorted arrays.
* For example, array A=[3], array B=[6]. The joined array will be C=[3, 6]
* For example, array A=[12], array B=[11]. The joined array will be C=[11, 12]
* For example, array A=[5, 8], array B=[11, 12]. The joined array will be C=[5, 8, 11, 12]
* For example, array A=[3, 5, 8, 12, 16], array B=[12]. The joined array will be C=[3, 5, 6, 8, 11, 12, 12]
* For example, array A=[3, 5, 8, 12, 16], array B=[6, 11, 12]. The joined array will be C=[3, 5, 6, 8, 11, 12, 12, 16]

function header:
```javascript
int joinSortedArray(int arrA[], int arrA_size, int arrB[], int arrB_size, int arrC[]);
```

first array 'A':
* int arrA[] // 'A' array name
* int arrA_size // 'A' array elements count

second array 'B'
* int arrB[] // 'B' array name
* int arrB_size // 'B' array elements count

output array 'C' have enough elememnts to store A and B arrays. so, it size more than arrA_size pluss arrB_size
arrC_size>=arrA_size + arrB_size
* int arrC[] // 'C' array name

examples:
```javascript
    int D10X5[5] = {1,2,3,4,5};
    int D20X10[10] = {2,3,5,5,8,12,13,17,18,20};
    int D10AndD20[20];

    std::cout << "\n D10 rolls:";
    for (int i=0; i<5; i++) std::cout << " " << D10X5[i];

    std::cout << "\n\n D20 rolls:";
    for (int i=0; i<10; i++) std::cout << " " << D20X10[i];

    joinSortedArray(D10X5,5, D20X10,10, D10AndD20);

    std::cout << "\n\n D10 + D20 rolls:";
    for (int i=0; i<15; i++) std::cout << " " << D10AndD20[i];
```

Output:
> D10 rolls: 1 2 3 4 5
> 
> D20 rolls: 2 3 5 5 8 12 13 17 18 20
> 
> D10 + D20 rolls: 1 2 2 3 3 4 5 5 5 8 12 13 17 18 20









## class work 19.09.2018 ##

*main new topics*
- [ ] Arrays
- [ ] Write to files
- [ ] Random

*topic to practice*
- [ ] Functions
- [ ] Loops
- [ ] Git credential - fill, reject

### Git credential ###
To clear credential on git folder, you shall 
1) read documentation - [gitcredentials](https://git-scm.com/docs/gitcredentials)
2) reject old cred on machine - run in git bash command: git credential reject
and fill it with this text:

```
$ git credential reject
protocol=https
host=github.com
```

3) generate new cred on this machine - run in git bash command:
```
$ git credential fill
protocol=https
host=github.com
path=Anaga/TARvg17.git
```
then git shall ask you e-mail and password in new GUI windows.

and then, output will be:
```
protocol=https
host=github.com
path=
username=Personal Access Token
password=fa7790ce97f6b526cfded32e2a9c43e9dfdeb3650a
```
