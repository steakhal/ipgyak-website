---
title: "1. gyakorlat"
date: 2019-09-13T12:00:00+02:00
draft: false
---

### Összefoglaló
alapvető bash utasítások: cd, ls, mkdir, touch, rm, mv, cp, echo, vim

haladó fogások

---

# Alapvető *bash* utasítások a terminálban
 * `cd <path>` (*change directory*), az adott mappába lépteti a terminált.
 * `cd -`, az előző `cd` hívás mappájába lép vissza.
 * `cd`, a saját `home` mappádba lép, ugyan úgy mint a `cd ~` tenné.
 * `ls <path>` (*list*), az adott mappába tartalmát listázza ki. Ha nem adjuk meg a `<path>`-t, akkor az aktuális mappa tartalmát listázza.
 * `touch <file>`, frissíti az időbélyegjét az adott fájlnak, ha még nem létezett, akkor létrehozza azt.
 * `mkdir <name>` (*make directory*), létrehoz egy mappát az adott névvel az aktuális mappába.
 * `cp <src> <dst>` (*copy*), egy fájlt vagy mappát másol.
 * `mv <src> <dst>` (*move*), egy fájlt vagy mappát mozgat.
 * `rm <target>` (*remove*), egy fájlt vagy (`-r` kapcsolóval) mappát töröl.

A `*` egy utasításban az adott mappa látható fájljainak és mappáinak nevére helyettesítődik be automatikusan, függetlenül az utasítástól. Pl `rm -r *` törli az aktuális mappa minden látható elemét (mappákat és fájlokat).

A `<path>` lehet *relatív* vagy *abszolút*. Részletesebben róluk [itt](https://en.wikipedia.org/wiki/Path_(computing)#Absolute_and_relative_paths).

További terminál utasításokat [itt](https://dev.to/awwsmm/101-bash-commands-and-tips-for-beginners-to-experts-30je) találtok.

# Haladó *bash* utasítások (rendkívül hasznos *shortcut*-ok)
 * `control + r` (*reverse search*), a kiadott utasítításaid (*history*) között keres visszafelé. Elkezdve begépelve az utasítást megkeresi az első egyezőt. A következő egyezőt a billenyűkombináció újra lenyomásával kapjuk meg.
 * `up/down arrow`, a *history*-ban egyel vissza vagy előre lép.
 * `control + left/right arrow`, az aktuális utasításodban egy szóval balra vagy jobbra ugrik a kurzor.
 * `control + a`, az aktuális utasításod elejére ugrik a kurzor.
 * `control + e`, az aktuális utasításod végére ugrik a kurzor.
 * `control + w`, az aktuális utasításodból a szó elejéig töröl a kurzortól balra.
 * `alt + backspace`, az aktuális utasításodból egy szótöredéket töröl a kurzortól balra.

