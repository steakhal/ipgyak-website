---
title: "10. gyakorlat"
date: 2019-11-19T13:00:00+02:00
draft: false
summary: Fájlműveletek (fopen, fclose, fread, fgets, stb.), hiba kiirása (errno, perror, strerror, ferror stb.), futtatási paraméterek használata, gyakorlás.
---

### Összefoglaló
Fájlműveletek (fopen, fclose, fread, fgets, stb.), hiba kiirása (errno, perror, strerror, ferror stb.), futtatási paraméterek használata, gyakorlás.

## Fájlműveletek

- [fopen](https://en.cppreference.com/w/c/io/fopen): open modes: `"r"`, `"w"`, `"a"`, stb.
- [fclose](https://en.cppreference.com/w/c/io/fclose)
- `FILE *`
- [fread](https://en.cppreference.com/w/c/io/fread)
- [fgets](https://en.cppreference.com/w/c/io/fgets) *(már vettük egyszer)*
- [fwrite](https://en.cppreference.com/w/c/io/fwrite)
- [fprintf](https://en.cppreference.com/w/c/io/fprintf)
- [fscanf](https://en.cppreference.com/w/c/io/fscanf)
- [fgetc](https://en.cppreference.com/w/c/io/fgetc)
- `EOF` *(end-of-file)*
- [feof](https://en.cppreference.com/w/c/io/feof)
- [ferror](https://en.cppreference.com/w/c/io/ferror)
- [errno](https://en.cppreference.com/w/c/error/errno)
- [perror](https://en.cppreference.com/w/c/io/perror)
- [strerror](https://en.cppreference.com/w/c/string/byte/strerror)

## Main függvény paraméterei
[referencia](https://en.cppreference.com/w/c/language/main_function)

`int main(int argc, const char **argv)`

- `argc`: argumentumok száma, legalább 1
- `argv`: sorban az argumentumok karakterláncai

### Példa: `./a.out first second 44`

```
argc: 4
argv[0]: "./a.out"
argv[1]: "first"
argv[2]: "second"
argv[3]: "44"
```

## Csoportos órai munka:
 [Canvas](canvas.elte.hu) `18_20_Person` feladata

---
Fájlok:

- [main-person.c](main-person.c)
- [person.c](person.c)
- [person.h](person.h)
- [myfilereader.c](myfilereader.c)
