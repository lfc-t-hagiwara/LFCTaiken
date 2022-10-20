#pragma once

#define size_namemax 9

/// <summary>
/// スコアの名前を表す型です。
/// </summary>
typedef char name_t[size_namemax];

typedef struct {
  int id;
  int value;
  name_t name;
} score_t;

#define size_scorearray 100

/// <summary>
/// スコア表として用いる、サイズがあらかじめ定義されたscore型の配列です。
/// </summary>
typedef score_t scorearray_t[size_scorearray];

/// <summary>
/// スコア表を読み込みます。
/// </summary>
void load_scores(scorearray_t scores);

/// <summary>
/// スコア表を保存します。
/// </summary>
/// <param name="scores">保存するスコア表</param>
void save_scores(scorearray_t scores);

/// <summary>
/// スコア表を標準出力に出力します。
/// </summary>
/// <param name="scores">出力するスコア表</param>
void print_scores(scorearray_t scores);

/// <summary>
/// スコア表を集計して標準出力に出力します。
/// </summary>
/// <param name="scores">集計するスコア表</param>
void print_aggregatedscores(scorearray_t scores);

/// <summary>
/// 新しいスコアを追加します。
/// </summary>
/// <param name="scores">スコアを追加するスコア表</param>
/// <param name="value">追加するスコアの値</param>
/// <param name="name">追加するスコアの名前</param>
void append_score(scorearray_t scores, int value, name_t name);

/// <summary>
/// IDを指定してスコアの値を編集します。
/// </summary>
/// <param name="scores">編集するスコアを含むスコア表</param>
/// <param name="id">編集するスコアのID</param>
/// <param name="value">編集後のスコアの値</param>
void edit_scorevalue(scorearray_t scores, int id, int value);

/// <summary>
/// IDを指定してスコアの名前を編集します。
/// </summary>
/// <param name="scores">編集するスコアを含むスコア表</param>
/// <param name="id">編集するスコアのID</param>
/// <param name="name">編集後のスコアの名前</param>
void edit_scorename(scorearray_t scores, int id, name_t name);

/// <summary>
/// IDを指定してスコアを削除します。
/// </summary>
/// <param name="score">削除するスコアを含むスコア表</param>
/// <param name="id">削除するスコアのID</param>
void delete_score(scorearray_t score, int id);
