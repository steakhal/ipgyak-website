#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct domino {
  int left, right;
};
typedef struct domino   domino;

domino read_domino(FILE *stream) {
  domino tmp;
  fscanf(stream, "%d %d", &tmp.left, &tmp.right);
  return tmp;
}

void print_domino(FILE *stream, domino d) {
  fprintf(stream, "%d %d", d.left, d.right);
}

int main() {
  int n;

  FILE * f = fopen("inp.txt", "r");
  domino start = read_domino(f);
  fscanf(f, "%d", &n);
  
  domino *stock = malloc(sizeof(domino) * n);
  for (int i = 0; i < n; ++i) {
    stock[i] = read_domino(f);
  }
  fclose(f);


  printf("Initial domino: %d|%d\n",
               start.left, start.right);

  char *in_use = calloc(n, 1);
  domino state = start;
  bool did_put_domino = true;
  int placed_dominos = 0;
  while (did_put_domino) {
    did_put_domino = false;

    // look for appropriate domino to place
    for (int i = 0; i < n; ++i) {
      if (in_use[i])
        continue;

      // jobbra siman
      if (state.right == stock[i].left) {
        state.right = stock[i].right;
        in_use[i] = true;
        did_put_domino = true;
        ++placed_dominos;
        printf("Added to the right end: %d|%d\n",
               stock[i].left, stock[i].right);
        break;
      }

      // jobbra forditva
      if (state.right == stock[i].right) {
        state.right = stock[i].left;
        in_use[i] = true;
        did_put_domino = true;
        ++placed_dominos;
        printf("Added to the right end: %d|%d\n",
               stock[i].left, stock[i].right);
        break;
      }

      // balra siman
      if (state.left == stock[i].right) {
        state.left = stock[i].left;
        in_use[i] = true;
        did_put_domino = true;
        ++placed_dominos;
        printf("Added to the left end: %d|%d\n",
               stock[i].left, stock[i].right);
        break;
      }

      // balra forditva
      if (state.left == stock[i].left) {
        state.left = stock[i].right;
        in_use[i] = true;
        did_put_domino = true;
        ++placed_dominos;
        printf("Added to the left end: %d|%d\n",
               stock[i].left, stock[i].right);
        break;
      }
    }
  }
  printf("Summary: %d dominos were placed.\n", placed_dominos);
  /*
  printf("start: ");
  print_domino(stdout, start);
  printf("\nnumber of dominos: %d\ndominos: ", n);
  for (int i = 0; i < n; ++i) {
    print_domino(stdout, stock[i]);
    printf(" ");
  }
  printf("\n");
  */
  free(in_use);
  free(stock);
  return 0;
}






