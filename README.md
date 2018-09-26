# TARvg17


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
For example, array A=[3], array B=[6]. The joined array will be C=[3, 6]
For example, array A=[12], array B=[11]. The joined array will be C=[11, 12]
For example, array A=[5, 8], array B=[11, 12]. The joined array will be C=[5, 8, 11, 12]
For example, array A=[3, 5, 8, 12, 16], array B=[12]. The joined array will be C=[3, 5, 6, 8, 11, 12, 12]
For example, array A=[3, 5, 8, 12, 16], array B=[6, 11, 12]. The joined array will be C=[3, 5, 6, 8, 11, 12, 12, 16]

function header:
```javascript
int joinSortedArray(int arrA[], int arrA_size, int arrB[], int arrB_size, int arrC[]);
```

first array 'A':
int arrA[] // 'A' array name
int arrA_size // 'A' array elements count

second array 'B'
int arrB[] // 'B' array name
int arrB_size // 'B' array elements count

output array 'C' have enough elememnts to store A and B arrays. so, it size more than arrA_size pluss arrB_size
arrC_size>=arrA_size + arrB_size
int arrC[] // 'C' array name

examples:
```javascript
    int D10X5[5] = {1,2,3,4,5};
    int D20X10[10] = {2,3,5,5,8,12,13,17,18,20};
    int D10AndD20[20];

    std::cout << "\n D10 rolls:";
    for (int i=0; i<5; i++) std::cout << " " << D10X5[i];

    std::cout << "\n D20 rolls:";
    for (int i=0; i<10; i++) std::cout << " " << D20X10[i];

    joinSortedArray(D10X5,5, D20X10,10, D10AndD20);

    std::cout << "\n D10 + D20 rolls:";
    for (int i=0; i<15; i++) std::cout << " " << D10AndD20[i];
```

Output:
> D10 rolls: 1 2 3 4 5
> D20 rolls: 2 3 5 5 8 12 13 17 18 20
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
