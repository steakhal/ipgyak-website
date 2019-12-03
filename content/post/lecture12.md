---
title: "12. gyakorlat"
date: 2019-12-03T1:00:00+02:00
draft: false
summary: Minta ZH feladatok megoldásai, gyakorlás
---

### Összefoglaló
Előző óra folytatása.

Minta ZH feladatok megoldásai, gyakorlás

# *(minta)* ZH feladatok folytatása

## 3. feladat: is monotonic
Írj egy C programot az alábbi működéssel:

Ellenőrizd, hogy egy adott lista/tömb monoton-e (akár csökkenő, akár növekvő).
A programokat modulárisan szervezd.
A másik modulban valósíts meg egy főprogramot, amely alaposan leteszteli az első modulban megvalósított függvényt.
Írj főprogramot, amelyben minden érdekes esetet leellenőrzöl.

`Igazat` ad vissza ezekre a bementekre:
```
<<1,1,4,5>>
<<>>
<<-1,-1,-1,-1,-1>>
<<42>>
<<42, 55>>
```

`Hamisat` ad vissza ezekre:
```
<<1,5,1>>
<<5,1,5>>
<<1,1,4,5,4>>
<<-1,0, 0, -6>>
```

---

## 4. feladat: compress string
Írj egy függvényt, amely egy paraméterként kapott sztringet tömörít (*). A függvénynek egy char-tömböt kelljen átadni, **amit megváltoztat**.

A tömörítés a következőképpen történjen:
**Ha** egymás után ugyanaz a betű többször szerepel, **akkor** az első előfordulás után írjuk be, hogy hányszor fordul elő. 

Például az `az abba   aaaah, de joooooooooo!!!` sztringből tömörítés után `az ab2a 3a4h, de jo10!3` lesz.
```
"az abba   aaaah, de joooooooooo!!!" tömöritve "az ab2a 3a4h, de jo10!3"
"aabb"                               tömöritve "a2b2"
"abc"                                tömöritve "abc"
"b"                                  tömöritve "b"
""                                   tömöritve ""
```

Írj főprogramot, amelyben minden érdekes esetet leellenőrzöl.

(*) A bemenet nem tartalmaz számokat, igy egyértelmű az elkódolás.

---
Fájlok:

#### 3. feladat: is monotonic
- [main-monotonic.c](main-monotonic.c)
- [monotonic.c](monotonic.c)
- [monotonic.h](monotonic.h)

#### 4. feladat: compress string
- [main-compress.c](main-compress.c)
- [compress.c](compress.c)
- [compress.h](compress.h)

Feladatok forrása:
**Luksa Norbert** Imperativ programozás [gyakorlatáról](https://docs.google.com/document/d/1tR48WoOFX2ybyP0t00j1NtTR17c_MihJR2hRsP_nZs4/edit)
