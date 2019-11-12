#ifndef VEC_WOOW_INSANE_MAGIC_HEADER
#define VEC_WOOW_INSANE_MAGIC_HEADER

struct int_vec {
  int m_size;
  int m_cap;
  int *buff;
};
typedef struct int_vec  int_vec;

int_vec vec_default_init();
void vec_destroy(int_vec* v);

int vec_size(int_vec* v);
int vec_capacity(int_vec* v);
void vec_push_back(int_vec* v, int newvalue);
int vec_at(int_vec* v, int idx);
void vec_replace_at(int_vec* v, int idx, int newvalue);
void vec_pop_back(int_vec* v);

#endif // VEC_WOOW_INSANE_MAGIC_HEADER

