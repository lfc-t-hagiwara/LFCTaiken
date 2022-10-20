#pragma once
#include "Score.h"

/// <summary>
/// メッセージを表示しながら、int値をユーザー入力から受け取ります。
/// </summary>
/// <param name="message">ユーザーに値の入力を促すメッセージ</param>
/// <param
/// name="errormessage">入力した値が不正だった際に表示するメッセージ</param>
/// <returns></returns>
int getintinput(const char *message, const char *errormessage);

/// <summary>
/// メッセージを表示しながら、name_t値をユーザー入力から受け取ります。
/// </summary>
/// <param name="message">ユーザーに値の入力を促すメッセージ</param>
/// <param
/// name="errormessage">入力した値が不正だった際に表示するメッセージ</param>
/// <param name="name">入力されたname_t値を返す</param>
void getnameinput(const char *message, const char *errormessage, name_t name);
