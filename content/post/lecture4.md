---
title: "4. gyakorlat"
date: 2019-10-01T13:00:00+02:00
draft: false
summary: Stack, mutatók, program paraméterek, tömbök mint paraméterek, pointer pointer, tömbök tömbje, pointer aritmetika, no VLA
---

### Összefoglaló
Stack, mutatók, program paraméterek, tömbök mint paraméterek, pointer pointer, tömbök tömbje, pointer aritmetika, no VLA

---
## Fordítási kapcsolók
```
gcc -Wall -Wextra -std=c99 -pedantic   myfile.c
```
- `gcc`: fordító hívása
- `-Wall`, `-Wextra`: warningok bekapcsolása
- `-std=c99`: 99-es szabvány használata
- `-pedantic`: kövesse szigorúan a szabványt, a compiler specifikus nyelvkiegészítéseket **ne** fogadja el

A gyakorlatokon és a vizsgákon is csak **warning mentes** kódokat fogadunk. el.

---
## Stack és az absztrakt számítógép működése
https://en.wikipedia.org/wiki/Stack_buffer_overflow

https://en.wikipedia.org/wiki/Stack_buffer_overflow#/media/File:Stack_Overflow_3.png

## Mutatók (*pointerek*)
Olyan típus, melynek a felvehető értékek halmaza bármely memóriaterület címe.
Kb. olyan mintha a memóriaszalagon az adott változó helyét határozná meg.


Típusosak, így egy adott mutató pl. `int *ptr` nem mutathat csak `int` típusú memóriára.
`void *` típusú mutató bárhova mutathat (*c++-ban azért nem teljesen igaz*).


Létrehozásukhoz a címképző operátorra van szükség:
```c
int local = 2;
int *ptr = &local; // <-- here: '&'
```

Fontos megjegyezni, hogy a *mutató* is egy sima típus, azaz ha nem inicializáljuk, akkor memóriaszemét a tartalma, amit használni (*dereferálni*) tilos.

Speciális mutató a `NULL` mutató, ami nem mutat sehova. [NULL makró](https://en.cppreference.com/w/c/types/NULL)

## Program paraméterek
```c
int main(int argc, const char **argv)
```

## Tömb mint függvény paraméter
```c
void print_all(int items[], int len)
```
```c
void print_all(int *items, int len)
```


## Pointer pointerre
```c
int myvar = 42, myvar2 = 0;
int *ptr = &myvar;
int **ptr_to_ptr = &ptr;
*ptr = 33; // myvar == 33
*ptr_to_ptr = NULL; // ptr == NULL
ptr = &myvar2;
ptr_to_ptr = NULL;
ptr_to_ptr = 0; // same as above
```

## Tömbök és pointerek, pointer aritmetika, tömbök tömbje
```c
const char txt1[] = { 'h', 'e', 'l', 'l', 'o' }; // not terminated with zero => not string
const char txt2[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // an array, which contains string
const char txt3[] = "hello"; // exactly same as txt2
const char *txt4 = "hello"; // string, but not an array
```

```c
int nums1[3]; // uninitialized all items
int nums2[3] = {}; // zero initialized all items
int nums3[3] = {0}; // same as above
int nums4[] = {0,0,0}; // same as above, all count deduced from init list
int nums5[] = {2,0,0,19};
int nums6[12] = {3,2,1}; // initialized with 3,2,1,0,0,...,0 
```

```c
const char *months[12] = { "january", "february" /*etc*/};
```

**TILOS VLA-kat használni.**


# Feladatok
1. Olvassatok be `N` számot, keressétek meg a legkisebbet. Legfeljebb `MAX_N` számra kell számítani.
2. Egy beolvasott `int` tömböt fordítsatok meg, majd írjátok ki.
3. Egy beolvasott tömböt *forgassatok* el.
4. Olvassatok be pozitív egész számot (`N`), majd olvassatok be `N` pozitív páratlan számot egy tömbbe. Majd a tömböt alakítsátok [kupaccá](https://en.wikipedia.org/wiki/Heap_(data_structure)). Természetesen ellenőrizzetek minden bemenetet.


---
Fájlok:

- [find_min_idx_and_value.c](find_min_idx_and_value.c)
- [pre-plusplus_vs_post-plusplus.c](pre-plusplus_vs_post-plusplus.c)
- [reverse-array.c](reverse-array.c)
