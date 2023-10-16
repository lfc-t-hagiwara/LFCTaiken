#include "IO.h"
#include "Score.h"
#include <stdio.h>
#include <stdlib.h>

#define MSG_MM2                                                                                      \
  "メニュー番号を入力してください。\n1:スコアの追加\n2:スコアの編集\n3:" \
  "スコアの削除\n4:集計したスコアの表示\n9:プログラムの終了\n"
#define MSG_ME1 "誤ったメニュー番号が入力されました。\n"
#define MSG_AM1 "スコアの値を入力してください。\n"
#define MSG_AE1 "誤った値が入力されました。\n"
#define MSG_AM2 "スコアの名前を入力してください。\n"
#define MSG_AE2 "誤った名前が入力されました。\n"
#define MSG_EM1 "編集するスコアのIDを入力してください。\n"
#define MSG_EE1 "誤ったIDが入力されました。\n"
#define MSG_EM2                                                                \
  "編集するスコアの項目番号を入力してください\n1:スコアの値\n2:スコアの名前\n"
#define MSG_EE2 "誤った項目番号が入力されました。\n"
#define MSG_EM3 "スコアの新しい値を入力してください。\n"
#define MSG_EE3 "誤った値が入力されました。\n"
#define MSG_EM4 "スコアの新しい名前を入力してください。\n"
#define MSG_EE4 "誤った名前が入力されました。\n"
#define MSG_DM1 "削除するスコアのIDを入力してください。\n"
#define MSG_DE1 "誤ったIDが入力されました。\n"

int mainmenu();
void add();
void edit();
void delete ();
void waitclear();

scorearray_t scores;

int main() {
  load_scores(scores);
  int num = 0;
  while (num != 9) {
    num = mainmenu();
    switch (num) {
    case 1:
      add();
      waitclear();
      break;
    case 2:
      edit();
      waitclear();
      break;
    case 3:
      delete ();
      waitclear();
      break;
    case 4:
      print_aggregatedscores(scores);
      waitclear();
      break;
    case 9:
      return 0;
    default:
      printf(MSG_ME1);
      waitclear();
      break;
    }
  }
}

int mainmenu() {
  int num;
  print_scores(scores);
  num = getintinput(MSG_MM2, MSG_ME1);
  return num;
}

void add() {
  int value;
  name_t name;
  value = getintinput(MSG_AM1, MSG_AE1);
  getnameinput(MSG_AM2, MSG_AM2, name);
  append_score(scores, value, name);
  save_scores(scores);
}

void edit() {}

void delete () {}

void waitclear() {
  printf("続行するにはキーを入力してください...");
  int _ = getchar();
  printf("\033[0;0H\033[2J");
}