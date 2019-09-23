---
title: "2. gyakorlat"
date: 2019-09-17T13:00:00+02:00
draft: false
---

### Összefoglaló
fordítás lépései, imperatív programozási elemek, formatstring, jokerek, típusok, kiírás, beolvasás, gyakorlás

---

# Fordítás lépései
1. **preprocesszálás**: `gcc -E prog.c` vagy `cpp prog.c`
2. **fordítás**: `gcc -c prog.c`
3. **linkelés**: `gcc prog.o` (figyelem! **.o** fájlokon)
 
 Részletesebben az előadáson illetve [itt](https://www.cs.swarthmore.edu/~newhall/unixhelp/compilecycle.html).
 
> **Note**: Egy object fájl tartalmát a `objdump -d prog.o` paranccsal nézhetitek meg.

# Típusok
A `C` nyelvhez a típusok hivatalos listáját [itt](https://en.cppreference.com/w/c/language/type) találhatjátok. Néhány legfontosabbat kiemeltem ide:

## Alap típusok
### Előjeles típusok
`short`, `int`, `long`, `long long`

### Előjel nélküli típusok
`bool`, `unsigned {char,short,int,long,long long}`

### Lebegőpontos típusok
`float`, `double`, `long double`

# Imperatív programozási elemek
> **Note**: Minden vezérlési szerkezet csak a következő utasításra érvényes, kivéve ha egy blokkot nyitsz, mert akkor arra az egész blokkra.

> **Note**: Előfordulhat, hogy egy feltétel helyén (*valószínűleg*) véletlenül egy értékadást adunk meg egyenlőségvizsgálat helyett.\\
Pl. `if (i = 2)` az `if (i == 2)` helyett, azaz `int -> bool`. Ez azért fordulhat elő, mert a legtöbb típus *implicit* konvertálódhat logikai értékké (hamis ha nulla, igaz egyébként).\\
Ezt bonyolítja, hogy implicit konverzió van sokszor visszafelé is, így pl. `bool -> int` `int x = i == 2;` (nem ugyan azt jelenti mint a `int x = i = 2;`).

## Vezérlési szerkezetek
### Elágazás
```c
if (cond)
  printf("true branch taken\n");
printf("every time executed\n");

if (cond) {
  printf("true branch taken\n");
  printf("still the same branch\n");
}
```

> **Note**: Konvenció, hogy minden blokk nyitásakor az adott blokhoz tartozó utasítások be legyenek húzva. Használhatsz tabot vagy space-t is, de ne keverd őket!


### Elöltesztelős ciklus
```c
int i = 0;
while (i < 5) {
  printf("looping\n");
  ++i; // <---- make the loop exit once
}
```

### Hátultesztelős ciklus
```c
int i = 0;
do {
  printf("%d, ", i);
} while (++i < 10); // increment `i`, and test if it's less then 10
```

### Számlálós ciklus
`for (int i = 0; i < 10; ++i)`
Három részből áll, inicializáló tag, ciklusfeltétel és iterációs lépés. Ezeket `;`-vel választjuk el egymástól, bármelyik elhagyható, így `for (;;)` egy végtelen ciklust jelent.
```c
for (int i = 0; i < 10; ++i)
  printf("%d, ", i);
```

> **Note**: Nem trukturált vezérlési szerkezetek: `break`, `continue`.
Ezekkel ki tudtok ugorni egy blokkból, hogy onnan folytatódjon a program futása. Csak nagyon indokolt esetekben ildomos használni őket, erősen rontják a kód olvashatóságát.
Egy ciklusban a `break` hatására kilépünk a ciklusból (már a ciklusfeltétel sem fog lefutni). A `continue` pedig csak az aktuális iterációt szakíja meg és egyből a ciklusfeltételhez ugrik.
[Bővebben](https://www.programiz.com/c-programming/c-break-continue-statement).

### Switch
Egész típusokon kiválthatunk több elágazást egy `switch`-el. Switch-ben fel tudjuk sorolni, mely bemenetre mit kell végrehajtson.
[Bővebben](https://www.programiz.com/c-programming/c-switch-case-statement).
```c
int i = ....; // input
switch (i) {
  case 0:
    printf("i was zero\n");
    break;
  case 3:
  case 4:
  case 8:
    printf("3, 4 or 8\n");
    // missing break here, aka. fallthrough
  case 9:
    printf("3, 4, 8 or 9\n");
    break;
  default:
    printf("not 0,3,4,8,9, something else\n");
    break;
}
```
> **Feladat**: Próbáld ki ezt a `switch`-et, milyen eredményt ad a következő számokra: `0,1,2,3,8,9,44`. Mire számítottál?

# Beolvasás, kiírás
Mind a két funkcionalitáshoz nélkülözhetetlen a `format string` fogalma.
Részletesebben a [hivatalos referenciát](https://en.cppreference.com/w/c/io/fprintf) olvasva tájékozódhattok.
Ahhoz hogy használhassuk a `printf`-et vagy a `scanf`-et vagy társait, szükségünk lesz a `stdio.h` headerre, amit az `#include <stdio.h>` sorral hozhatunk be.

Mind a két függvény egy `format string`-et vár első paraméternek. Ez adja meg milyen típusként kezelje a paramétereket. Ezeket (nem hivatalos módon) gyakran csak *joker*-eknek nevezem. 
A legfontosabb ezek közül:

type       | format <br>specifier | meaning
----------:|:-----:|:---------
`int`      | `%d`  | *decimal*
`unsigned` | `%u`  | *unsigned int*
`char`     | `%c`  | *character*
`float`    | `%f`  | *float*
`double`   | `%lf` | *long float*
`string`   | `%s`  | *string*

Kiíjuk a `4`-et és az `5`-öt:
```c
#include <stdio.h>
int main() {
  int n = 4;
  printf("number is: %d, which is one less then %d\n", n, n + 1);
}
```
---
Bekérünk egy előjeles egész számot. Ha sikerült beolvasni pontosan **egy** számot, akkor kiírom, különben kiírom hogy nem sikerül beolvasni egy számot sem.
```c
#include <stdio.h>
int main() {
  int n;
  int jokers_resolved = scanf("%d", &n); // notice the `&` sign before `n`.
  if (jokers_resolved == 1) 
    printf("number is: %d, which is one less then %d\n", n, n + 1);
  else
    printf("could not read any numbers\n");
}
```

> **Note**: Figyeljük meg hogy a `scanf` megadja hogy hány elemet sikerült beolvasnia, és mellékhatásként olvas csak az adott változókba.
`scanf("%d%d", &intVar, &unsignedVar)` esetén ha `2`-vel tér vissza a hívás, akkor mind a 2 változóba sikerült beolvasnia. Ha pl. `1`-el térne vissza, akkor csak az első változó kapott volna értéket, a többi nem.

---

# Feladatok
0. Megézed az előadás [fahrenheit](http://gsd.web.elte.hu/lectures/imper/imper-lecture-1) példát, hány helyen és milyen hibákat lehet elkövetni benne?
1. [FizzBuzz](https://en.wikipedia.org/wiki/Fizz_buzz):
Kérj be egy pozitív egész számot, `n`-et! Írd ki a számokat `1`-től `n`-ig! A hárommal osztható számok helyett a `fizz` szó jelenjen meg, az öttel oszthatók helyett `buzz`, a hárommal és öttel is osztható számokat helyett viszont `fizzbuzz`!
2. Kérj be egy pozitív egész számot, `n`-et! Írd ki `n` osztóit!
3. Kérj be egy pozitív egész számot, `n`-et! Írd ki, hogy `n` [tökéletes szám](https://hu.wikipedia.org/wiki/T%C3%B6k%C3%A9letes_sz%C3%A1mok)-e!
4. Kérj be egy pozitív egész számot, `n`-et! Írd ki, hogy `n` prím szám-e!
5. Kérj be két pozitív egész számot, `n`-et és `m`-et (egy utasítással)! Írd ki, hogy `n` és `m` relatív prímek-e!
6. Kérj be egy egész számot, `n`-et! Írd ki, hogy `n` [Fibonacci-szám](https://en.wikipedia.org/wiki/Fibonacci_number)-e!
7. Kérj be egy pozitív számot, `n`-et! Írd ki `i=1`-től `n`-ig, hogy `i` Ft mennyi Euróba kerülne!


**Rengeteg további feladat vár benneteket a [canvasban](https://canvas.elte.hu/courses/3557/assignments).**