---
title: "6. gyakorlat"
date: 2019-10-15T13:00:00+02:00
draft: false
summary: bitműveletek, strlen, malloc használata, hibái, ascii tábla, variable length arrays, string duplikálása, stringek egyesitése, stringek összefűzése
---

### Összefoglaló
bitműveletek, strlen, malloc használata, hibái, ascii tábla, variable length arrays, string duplikálása, stringek egyesitése, stringek összefűzése

---

`#include <stdlib.h>`

[malloc](https://en.cppreference.com/w/c/memory/malloc)

[calloc](https://en.cppreference.com/w/c/memory/calloc)

[calloc-versus-malloc](https://www.geeksforgeeks.org/calloc-versus-malloc)

---

![ASCII character table](ASCII_Code_Chart.svg.png)
*from wikipedia*

---

## functions using strings
https://en.cppreference.com/w/c/string/byte

[isalnum](https://en.cppreference.com/w/c/string/byte/isalnum)

[isalpha](https://en.cppreference.com/w/c/string/byte/isalpha)

[islower](https://en.cppreference.com/w/c/string/byte/islower)

[isupper](https://en.cppreference.com/w/c/string/byte/isupper)

[isdigit](https://en.cppreference.com/w/c/string/byte/isdigit)

[isspace](https://en.cppreference.com/w/c/string/byte/isspace)

[tolower](https://en.cppreference.com/w/c/string/byte/tolower)
[toupper](https://en.cppreference.com/w/c/string/byte/toupper)

[atoi, atol, atoll](https://en.cppreference.com/w/c/string/byte/atoi)

[strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)

[memset](https://en.cppreference.com/w/c/string/byte/memset)

[memcpy](https://en.cppreference.com/w/c/string/byte/memcpy)

[strlen](https://en.cppreference.com/w/c/string/byte/strlen)

[strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)


[strdup](https://pubs.opengroup.org/onlinepubs/9699919799/functions/strdup.html) (nem szabványbeli, de a POSIX-ben definiált függvény. A [C20-as szabványban](https://en.cppreference.com/w/c/experimental/dynamic/strdup) benne lehet)

---
Fájlok:

- [bitwise.c](bitwise.c)
- [convchar.c](convchar.c)
- [main-malloc.c](main-malloc.c)
- [printascii.c](printascii.c)
- [strconcat.c](strconcat.c)
- [strdup.c](strdup.c)
- [strmerge.c](strmerge.c)
- [vla.c](vla.c)
