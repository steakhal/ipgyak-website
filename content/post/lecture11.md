---
title: "11. gyakorlat"
date: 2019-11-26T1:00:00+02:00
draft: false
summary: Minta ZH feladatok megoldásai, gyakorlás
---

### Összefoglaló
Minta ZH feladatok megoldásai, gyakorlás

# *(minta)* ZH feladatok

## 1. feladat: fibonacci
Készíts két modult. Az egyikben a *Fibonacci*-számok sorozatát kiszámító
függvényt (függvényeket), a másikban az első modult alaposan letesztelő
főprogramot kell elkészíteni.

A *Fibonacci*-számok a következők:
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...
```
Azaz egy Fibonacci-szám az előző két Fibonacci-szám összegeként áll elő.

A C-nyelvű megoldásban az első modul exportáljon két függvényt: `fibs1` és `fibs2`. A `fibs1` kap egy nemnegatív egész számot paraméterként, és visszaadja az első ennyi *Fibonacci*-számot.
A `fibs2` kap paraméterként egy tömböt is, és ebbe írja a kiszámított *Fibonacci*-számokat.

A *Fibonacci*-számok gyorsan növekednek, ezért érdemes őket a lehető legnagyobb méretű egész típusban tárolni. (Vedd figyelembe azt is, hogy ezek a számok mindig nemnegatívok.) Azt az értéket, hogy hány *Fibonacci*-számot akarunk meghatározni, egy kisméretű egész típussal elegendő ábrázolni. (Itt is érdemes kikényszeríteni, hogy csak nemnegatív érték lehessen.)

---

## 2. feladat: filter first n positive in sequence
Készíts két modult. Az egyikben valósíts meg egy függvényt, amely egy egészekből álló számsorozatot kap paraméterül, továbbá egy pozitív egész számot, amely megmondja, hogy a sorozat első ennyi pozitív elemét kell visszaadni. 

Például az `<<1,-2,3,4,5,-6,7,-8,-9,0>>` sorozat esetén a `3` értékre az `<<1,3,4>>` sorozatot kell kapnunk. Ha a függvény által kapott számsorozatban nincs annyi pozitív elem, mint amennyit vissza kellene adni *(például `6` a fenti sorozatban)*, akkor a függvény adjon vissza `NULL` értéket.
```
<<1,-2,3,4,5,-6,7,-8,-9,0>>, 3-ra a kimenet:     <<1,3,4>>
<<1,-2,3,4,5,-6,7,-8,-9,0>>, 6-ra a kimenet:     NULL
```

A másik modulban valósíts meg egy főprogramot, amely alaposan leteszteli az első modulban megvalósított függvényt.

 **Figyelj oda a dinamikus memória felszabadítására!**
Írj főprogramot, amelyben minden érdekes esetet leellenőrzöl.

---
Fájlok:

#### 1. feladat: fibonacci
- [main-fibonacci.c](main-fibonacci.c)
- [fibonacci.c](fibonacci.c)
- [fibonacci.h](fibonacci.h)

#### 2. feladat: filter first n positive in sequence
- [main-filter.c](main-filter.c)
- [filter_first_n_positive.c](filter_first_n_positive.c)
- [filter_first_n_positive.h](filter_first_n_positive.h)

Feladatok forrása:
**Luksa Norbert** Imperativ programozás [gyakorlatáról](https://docs.google.com/document/d/1tR48WoOFX2ybyP0t00j1NtTR17c_MihJR2hRsP_nZs4/edit)
