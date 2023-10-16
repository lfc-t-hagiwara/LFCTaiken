#include "Score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 64
#define DEM ",\r\n"
#define FOREACHSCORES(scores, ite)                                             \
  for (size_t ite = 0; scores[ite].id > 0; ite++)

int nextid = 1;

void load_scores(scorearray_t scores) {
  char line[LINE_MAX];
  int i = 0;
  char *spl;
  char *context = NULL;
  FILE *fp;
  fp = fopen("Score.csv", "r");
  if (fp == NULL) {
    printf("scoreファイルが開けませんでした。");
    return;
  }

  if (fgets(line, LINE_MAX, fp) != NULL) {
    nextid = atoi(line);
  }

  while (fgets(line, LINE_MAX, fp) != NULL && i < size_scorearray) {
    spl = strtok(line, DEM);
    scores[i].id = atoi(spl);
    spl = strtok(NULL, DEM);
    scores[i].value = atoi(spl);
    spl = strtok(NULL, DEM);
    strcpy(scores[i].name, spl);
    i++;
  }

  fclose(fp);

  while (i < size_scorearray) {
    scores[i].id = 0;
    i++;
  }
}

void save_scores(scorearray_t scores) {
  FILE *fp;
  fp = fopen("Score.csv", "w");
  if (fp == NULL) {
    printf("scoreファイルが開けませんでした。");
    return;
  }

  fprintf(fp, "%d\n", nextid);

  FOREACHSCORES(scores, i) {
    fprintf(fp, "%d,%d,%s\n", scores[i].id, scores[i].value, scores[i].name);
  }

  fclose(fp);
}

void print_scores(scorearray_t scores) {
  printf("%s", "    ----------スコア表----------\n");
  printf("%12s%12s%12s\n", "ID", "VALUE", "NAME");
  FOREACHSCORES(scores, i) {
    printf("%12d%12d%12s\n", scores[i].id, scores[i].value, scores[i].name);
  }
}

typedef struct {
  name_t name;
  int max;
  int sum;
  int num;
  double ave;
} aggregating_t;
int compmax(const void *x, const void *y) {
  return (*(aggregating_t *)y).max - (*(aggregating_t *)x).max;
}
int compave(const void *x, const void *y) {
  return (*(aggregating_t *)y).ave - (*(aggregating_t *)x).ave;
}
void print_aggregatedscores(scorearray_t scores) {
  aggregating_t a[size_scorearray];
  size_t j;
  for (j = 0; j < size_scorearray; j++) {
    aggregating_t x = {"\0", 0, 0, 1, 0.0};
    a[j] = x;
  }

  FOREACHSCORES(scores, i) {
    for (j = 0; j < size_scorearray; j++) {
      if (a[j].name[0] == '\0') {
        strcpy(a[j].name, scores[i].name);
        break;
      } else if (strcmp(a[j].name, scores[i].name) == 0) {
        break;
      }
    }
    if (a[j].max < scores[i].value) {
      a[j].max = scores[i].value;
    }
    a[j].sum += scores[i].value;
    a[j].num++;
  }

  for (j = 0; j < size_scorearray; j++) {
    if (a[j].name[0] == '\0') {
      break;
    }

    a[j].ave = (double)a[j].sum / a[j].num;
  }

  qsort((void *)a, size_scorearray, sizeof(aggregating_t), compmax);

  printf("%s", "    ---最高得点表---\n");
  printf("%12s%12s\n", "VALUE", "NAME");
  for (j = 0; j < size_scorearray; j++) {
    if (a[j].name[0] == '\0')
      break;
    printf("%12d%12s\n", a[j].max, a[j].name);
  }

  qsort((void *)a, size_scorearray, sizeof(aggregating_t), compave);

  printf("%s", "    ---平均得点表---\n");
  printf("%12s%12s\n", "VALUE", "NAME");
  for (j = 0; j < size_scorearray; j++) {
    if (a[j].name[0] == '\0')
      break;
    printf("%12.2f%12s\n", a[j].ave, a[j].name);
  }
}

void append_score(scorearray_t scores, int value, name_t name) {
  int i = 0;
  while (scores[i].id > 0 && i < size_scorearray) {
    i++;
  }

  if (i < size_scorearray) {
    scores[i].id = nextid++;
    scores[i].value = value;
    strcpy(scores[i].name, name);
  }
}

void edit_scorevalue(scorearray_t scores, int id, int value) {
  for (size_t i = 0; i < size_scorearray; i++) {
    if (scores[i].id == id) {
      scores[i].value = value;
    }
  }
}

void edit_scorename(scorearray_t scores, int id, name_t name) {
  for (size_t i = 0; i < size_scorearray; i++) {
    if (scores[i].id == id) {
      strcpy(scores[i].name, name);
    }
  }
}

void delete_score(scorearray_t scores, int id) {
  int afterdelete = 0;
  for (size_t i = 0; i < size_scorearray; i++) {
    if (scores[i].id == id) {
      scores[i].id = 0;
      afterdelete = 1;
    } else if (afterdelete) {
      scores[i - 1].id = scores[i].id;
      scores[i - 1].value = scores[i].value;
      strcpy(scores[i - 1].name, scores[i].name);
    }
  }
}
