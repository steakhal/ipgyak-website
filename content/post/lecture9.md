---
title: "9. gyakorlat"
date: 2019-11-12T13:00:00+02:00
draft: false
summary: dinamikus ellenőrzés, address sanitizer, valgrind, assert makró, int vektor implementálása, API design döntések
---

### Összefoglaló
dinamikus ellenőrzés, address sanitizer, valgrind, assert makró, int vektor implementálása, API design döntések

## Dinamikus ellenőrző eszközök
Biztonságos, helyes kód létrehozásához minden ellenőrző eszközre szükség van.
Dinamikus (*instrumentált*) ellenőrzés alatt az olyan ellenőrzéseket értjük, amikor a programot futtatjuk, az abban rejlő hibák felkutatásához.

Ennek előnye, hogy a futás során minden információ elérhető a problémák detektálásához. Hátránya, hogy csak azt a kódutat ellenőrzi, mely lefutott.

### Google Address Sanitizer
Rendkivül hasznos, pontos eszköz. Viszonylag gyors és nem annyira memóriaigényes.
Hátránya, hogy újra kell forditani a vizsgálandó binárist.

Alapvetően Linux platformra lett kidolgozva, de *elvileg* már [Windows-on is működik](https://devblogs.microsoft.com/cppblog/addresssanitizer-asan-for-windows-with-msvc) *(October 23rd, 2019)*.

`gcc` és `clang` már régóta támogatja, melyet a `-fsanitize=address` kapcsolóval tudunk aktiválni. Ezzel a memóriakezelési hibákat tudjuk felderiteni.

Létezik továbbá `thread`, `leak`, `undefined` sanitizer-ek. Részleteket [itt](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html) találhattok.

Fontos megjegyezni, hogy a hibaüzenetek megértéséhez gyakran hasznos lehet a *debug szimbólumok* bekapcsolása, melyet a `-g` kapcsolóval tehettek meg. Release buildhez nem javasolt ezt használni.

Példa forditáshoz:
```
gcc -Wall -Wextra -std=c99 -pedantic main-vec.c vec.c  -fsanitize=address -g
```

Példa kimenet a futtatásra `./a.out`:
```
=================================================================
==17955==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 20 byte(s) in 1 object(s) allocated from:
    #0 0x7f36ed7fc37e in realloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0x10c37e)
    #1 0x55609902e919 in vec_push_back /home/user/git/gyak/vec.c:33
    #2 0x55609902e1ec in main /home/user/git/gyak/main-vec.c:13
    #3 0x7f36ed320b96 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x21b96)

SUMMARY: AddressSanitizer: 20 byte(s) leaked in 1 allocation(s).
```

### Valgrind
Előnye, hogy nem kell az instrumentálandó binárist újra forditani az elemzés miatt.
Hátránya, hogy viszonylag lassú és nem talál meg minden memóriakezelési hibát.

Egyszerűen futtatni kell vele a binárisunkat: `valgrind ./a.out`

Példa kimenet:
```
==17448== 
==17448== HEAP SUMMARY:
==17448==     in use at exit: 0 bytes in 0 blocks
==17448==   total heap usage: 2 allocs, 2 frees, 1,044 bytes allocated
==17448== 
==17448== All heap blocks were freed -- no leaks are possible
==17448== 
==17448== For counts of detected and suppressed errors, rerun with: -v
==17448== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Assert makró
Egy rendkivül hasznos makró, melyet előfeltételek, utófeltételek és invariánsok kifejezésére használunk.
Segitségükkel megállithatjuk a program futását (tesztelési fázisban), amennyiben valami olyan történne, amire a programozó nem számitott.

`assert(boolean-condition)` elképzelhető úgy mint egy logikai értéket váró függvény, mely megöli az alkalmazásunkat, ha a paramétere `hamis`. Ellenkező esetben nincs hatása a futtatásra.

Fontos megjegyezni, hogy ezek az `assert(...)`-ek eltűnhetnek release buildben, hogy gyorsabb futást kaphassunk. Ezt szabályozza az `-DNDEBUG` (*not debug*) kapcsoló.

Mivel eltűnhetnek, igy nem szabad mellékhatásos függvényt használni `assert` makró feltételében.

### Extra feladatok
- Előző órai `trim` függvény befejezése.
- [Canvas](https://canvas.elte.hu) `18_20_Person` feladata.

---
Fájlok:

- [main-vec.c](main-vec.c)
- [vec.c](vec.c)
- [vec.h](vec.h)
