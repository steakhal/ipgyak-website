---
title: "Példa elméleti feladatsor"
date: 2019-12-17T1:00:00+02:00
draft: false
summary: Példa elméleti feladatsor
---

1. Mit ír ki a következő C program?
```c
#include <stdio.h>

int main() {
    int a = 7;
    if (a % 3 == 2)
        printf("result1");
    else
        printf("result2");
    return 0;
}
```
 - fordítási hibát
 - semmit (üres képernyő)
 - result1
 - **result2**

2. Hány iterációt hajt végre a következő ciklus *(hányszor hajtódik végre a printf() függvényhívás)*?
```c
#include <stdio.h>

int main() {
    int i = 10;
    while (--i > 3)
        printf("%d", i);
    return 0;
}
```
 - fordítási hibát eredményez
 - 0
 - **6**
 - 7

3. Mit ír ki a képernyőre az alábbi C program?
```c
int main() {
    char msg[] = "CBA";
    printf("%d", msg[3]);
    return 0;
}
```
 - semmi, futási hibával leáll: az msg tömbnek 3 eleme van, nem hivatkozhatunk az utolsó utáni elemre
 - memóriaszemét
 - 65
 - **0**

4. Melyik deklaráció felel meg a következő leírásnak: "point" nevű változó mely egy előjel nélküli, hosszú egész (`long int`) konstans érték memóriacímének típushelyes tárolására képes
 - **const unsigned long int* point;**
 - const long int* point;
 - unsigned long int* const point;
 - const signed long int* point;

5. Melyik állítás igaz a következő C lokális változó deklaráció esetében?
```c
int* pointer = (int*)malloc(5000 * sizeof(int));
```
 - a heap-en lefoglalásra kerül egy sizeof(int*) méretű terület, ahol tárolódik - a stack-en lefoglalásra került - egy legalább 5000 * sizeof(int) méretű terület kezdő memóriacíme
 - **a stack-en lefoglalásra kerül egy sizeof(int*) méretű terület, ahol tárolódik - a heap-en lefoglalásra került - egy legalább 5000 * sizeof(int) méretű terület kezdő memóriacíme**
 - a heap-en létrejön egy sizeof(int*) méretű terület, ahol tárolódik - a heap-en lefoglalásra került - egy legalább 5000 * sizeof(int) méretű terület kezdő memóriacíme
 - egyik sem

6. Mi lesz az `(5 / 10 + 100)` C kifejezés kiértékelésekor kapott érték típusa?
 - double
 - float
 - **int**
 - unsigned int

7. Melyik állítás hamis?
 - C-ben a változók deklarációja nem szükségszerűen jár memóriafoglalással
 - **void x; deklaráció esetén az x változónak tetszőleges típusú érték adható**
 - a main() függvény visszatérési értéke információt ad az operációs rendszernek a program sikerességéről
 - a main() függvény paraméterben megkapja a program parancssori argumentumait

8. Melyik állítás hamis?
 - Python-ban a blokkhatárokat eltérő indentálással jelöljük
 - a Python magas szintű programozási nyelv
 - Python-ban a string immutable típus
 - **Python-ban minden változót deklarálni kell a felhasználása előtt**

9. Mit ír ki a következő **Python** program?
```c
list = [1, 10]
print(2 in list)
```
 - True
 - **False**
 - szemantikus hiba: [2] in list lenne helyes
 - szintaktikus hiba: nincs in operátor Python-ban

10. Melyik állítás igaz a **Python** a szimultán értékadására?
 - **egy utasításban több változó kap értéket - akár - különböző kifejezések alapján**
 - egy utasításban több változó kap értéket mindig pontosan egyetlen kifejezés alapján
 - Python-ban nem létezik szimultán értékadás
 - egyik sem a megadottak közül

---
Feladatok forrása:
**Leskó Dániel** Imperativ programozás [gyakorlatáról](http://ldani.web.elte.hu/ip/12)

