//
// Created by PaperPlane on 2024/4/14.
//
#ifndef EXPRESSIONTRUTHTABLE_ExpressionTruthTable_H
#define EXPRESSIONTRUTHTABLE_ExpressionTruthTable_H
// 算符优先表
// + - | & !( ) \0
static char OPTR_PRI[8][8] =
        {
/* + */	'>', '<', '<', '<', '<', '<', '>', '>',
/* - */	'>', '>', '<', '<', '<', '<', '>', '>',
/* | */	'>', '>', '>', '<', '<', '<', '>', '>',
/* & */ '>', '>', '>', '>', '<', '<', '>', '>',
/* ! */ '>', '>', '>', '>', '>', '<', '>', '>',
/* ( */	'<', '<', '<', '<', '<', '<', '=', 'x',
/* ) */	'>', '>', '>', '>', '>', 'x', '>', '>',
/* 0 */	'<', '<', '<', '<', '<', '<', 'x', '='
        };

// 将算符转换为内码
char getOptrCode(char c);

#include <iostream>
#include <cstring>
#include <stack.h>
#include <arrayList.h>

void console_out(char* express);
#endif