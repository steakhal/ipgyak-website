#include "vec.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int_vec vec_default_init() {
  int_vec v = {0};
  return v;
}

void vec_destroy(int_vec* v) {
  free(v->buff);
  v->buff = 0;
  v->m_size = 0;
  v->m_cap = 0;
}

int vec_size(int_vec* v) {
  assert(v->m_size <= v->m_cap && "type invariant");
  return v->m_size;
}

int vec_capacity(int_vec* v) {
  assert(v->m_size <= v->m_cap && "type invariant");
  return v->m_cap;
}

void vec_push_back(int_vec* v, int newvalue) {
  assert(v->m_size <= v->m_cap && "type invariant");
  if (v->m_size == v->m_cap) {
    int newcap = (v->m_cap == 0) ? 5 : v->m_cap * 2;
    int * newstorage = realloc(v->buff, newcap * sizeof(int));
    // uj darabszam * egy int merete    ^^^^^^^^^^^^^^^^^^^^

    if (newstorage == 0)
      return; // could not reallocate

    v->buff = newstorage;
    v->m_cap = newcap;
  }

  v->buff[v->m_size] = newvalue;
  v->m_size += 1;
}

int vec_at(int_vec* v, int idx) {
  assert(v->m_size <= v->m_cap && "type invariant");
  assert(0 <= idx && idx < v->m_size && "precondition");
  assert(v->buff != 0 && "must have storage");
  return v->buff[idx];
}

void vec_replace_at(int_vec* v, int idx, int newvalue) {
  assert(v->m_size <= v->m_cap && "type invariant");
  assert(0 <= idx && idx < v->m_size && "precondition");
  assert(v->buff != 0 && "must have storage");
  // vec_at(v, idx) = newvalue; // does not work, not lvalue
  v->buff[idx] = newvalue;
}

void vec_pop_back(int_vec* v) {
  assert(v->m_size <= v->m_cap && "type invariant");
  v->m_size -= 1;
}

