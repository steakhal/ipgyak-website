---
title: "3. gyakorlat"
date: 2019-09-24T13:00:00+02:00
draft: false
summary: gyakori beolvasási hibák, helyes beolvasás primitív típusokba illetve karakterláncokba, egyéb hasznos string függvények, feladatok a canvasban
---

### Összefoglaló
gyakori beolvasási hibák, helyes beolvasás primitív típusokba illetve karakterláncokba, egyéb hasznos string függvények, feladatok a canvasban

---

# Beolvasás
## Általános hibák

- Nem ellenőrizzük a `scanf` visszatérési értékét, azaz hogy hány paraméterbe tudott sikeresen beolvasni.
```c
float radius;
int center_x, center_y;
scanf("center: (%d,%d) with %f radius", &center_x, &center_y, &radius);
printf("center_x: %d\n", center_x); // bad, we dont know if center_x properly set.
```

- Elrontjuk a `format specifier` karaktereket (*jokereket*).
```c
scanf("center: (%d,%d) with %d radius", &center_x, &center_y, &radius);
// radius is float, but scanf expected an int (since %d was given), which is undefined behavior.
```

- Nem mutatót adunk át beolvasáskor, hanem annak az értékét.
```c
scanf("center: (%d,%d) with %f radius", center_x, center_y, radius);
// passed `center_x` (an integer) but scanf expected a pointer to an integer.
// scanf will potentially write to the memory location pointed by the value
// of the `center_x` (which is no grabage, since that was uninitialized).
```

- Nem adunk át kellően sok bemeneti paramétert a `scanf`-nek.
```c
scanf("center: (%d,%d) with %f radius", &center_x);
// scanf will store the second and third number to *somewhere* in memory,
// which is undefined behavior. Use the same number of arguments and jokers.
```

- `scanf`-et használunk string-ek beolvasására. Nincs felső korlát a beolvasandó karakterek számára.
```c
char name[5];
scanf("My name is: %s\n", &name[0]);
// If your name is longer than 4 characters, scanf will *overflow* the buffer,
// this vulnerability is widely used for exploits by hackers.
```

- `fgets` visszatérési értéke vagy `NULL` mutató, vagy mutató az output bufferre. `NULL` pontosan akkor ha nem tudott egyetlen karaktert sem beolvasni, ekkor egyáltalán nem nyúl az átadott bufferhez, tehát még a null-terminátort sem helyezi bele. Ha tudott beolvasni, akkor `EOF`-ig vagy enterig olvas. Az entert is beleteszi a bufferbe, majd elhelyezi utána a null-terminátort is. Legfeljebb `N-1` karatert tud beolvasni, mert a null-terminátornak is helyet hagy.
```c
char line[6]; // uninitialized
fgets(line, 6, stdin);
// if could not read any characters, `line` is untouched, still uninitialized
// using `line` would result in undefined behavior
// calling any std functions which expects `strings` is UB, bc. a `string` is
// always terminated by a `zero-terminator` (aka. `null-terminator`).
```

## Beolvasás helyesen
`scanf` használható minden primitív típushoz, kivéve karakterláncokhoz.
Karakterláncok beolvasására a `fgets` függvényt javaslom, aminél megadható hogy legfeljebb hány karakter olvasson be, amivel megakadályozhatjuk a buffer túlcsordulását.

Használata:
```c
#include <stdio.h>
#include <string.h>

int main(void) {
  float radius;
  int center_x, center_y;

  printf("enter eg.: center: (4,5) with 4.5 radius\n");
  if (3 !=
      scanf("center: (%d,%d) with %f radius", &center_x, &center_y, &radius)) {
    printf("Could not read center and radius. Abort.\n");
    return 1;
  }
  printf("radius: %f\n", radius);
  printf("center: (%d,%d)\n", center_x, center_y);

  char name[6];
  printf("enter eg.: My name is: Balazs\n");
  // notice the %5s, which stands for `read at most 5 characters *AND*
  // append the zero terminator as a 6th character.`
  if (1 != scanf("My name is: %5s\n", &name[0])) {
    printf("Could not read your name. Abort.\n");
    return 1;
  }
  printf("Name: '%s'\n", name);

  char line[6] = {}; // zero-initializes just in case fgets does not read any, it remains a *valid* string
  fgets(line, 6, stdin);
  // lets remove the possible newline ending
  size_t len = strlen(line); // will be zero, if nothing is read
  if (len > 0 && line[len - 1] == '\n') // if ends with newline
    line[len - 1] = '\0';
  printf("line: '%s'\n", line);

  return 0;
}
```

## Egyéb hasznos string műveletek
[sscanf](https://linux.die.net/man/3/sscanf), olyan mint a `scanf`, csak egy meglévő karakter bufferből olvas be, nem pedig a `stdin`-ről.
Pl.:
```c
float f;
int i;
char psw[10];
char *the_string = "foo -3.6 fum-dum 17";
// if used 'fum dum' instead of 'fum-dum', `psw` would become 'fum'
// and the read of `i` would fail.
sscanf(the_string, "foo %f %9s %d", &f, psw, &i);
printf("float: %f, num: %d, password: '%s'\n", f, i, psw);
```

[strlen](https://linux.die.net/man/3/strlen) megadja hogy egy (*zero-terminated*) string hány karakterből áll. A zero-terminátort nem számolja bele, így az eredménye lehet nulla.
```c
// #include <string.h>
char buff[6] = {}; // zero-initialized
printf("zero-initialized: %d\n", (int)strlen(buff)); // expect 0
char buff2[6] = "abc"; // hmm, what happens here?
printf("abc: %d\n", (int)strlen(buff2)); // expect 3
```


## Dokumentációk:
Ajánlom a függvény leírását, visszatérési értékét és a kapcsolódó **Bugs** szekciót.

 - [scanf doc](https://linux.die.net/man/3/scanf)
 - [fgets doc](https://linux.die.net/man/3/fgets)
 - [sscanf doc](https://linux.die.net/man/3/sscanf)
 

# Feladatok
A canvasban.
