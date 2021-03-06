/* Copyright (C) 2001-2020 Valeriy Argunov (val AT time DOT guru) */
/*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "errors.h"
#include "text.h"

int qspErrorNum = 0;
int qspErrorLoc = -1;
int qspErrorLine = 0;
int qspErrorActIndex = -1;
int qspRealCurLoc = -1;
int qspRealLine = 0;
int qspRealActIndex = -1;

void qspSetError(int num)
{
    if (!qspErrorNum)
    {
        qspErrorNum = num;
        qspErrorLoc = qspRealCurLoc;
        qspErrorActIndex = qspRealActIndex;
        qspErrorLine = qspRealLine;
    }
}

void qspResetError()
{
    qspErrorNum = 0;
    qspErrorLoc = -1;
    qspErrorActIndex = -1;
    qspErrorLine = 0;
}

QSPString qspGetErrorDesc(int errorNum)
{
    QSPString str;
    switch (errorNum)
    {
    case QSP_ERR_DIVBYZERO: str = QSP_STATIC_STR(QSP_FMT("Division by zero!")); break;
    case QSP_ERR_TYPEMISMATCH: str = QSP_STATIC_STR(QSP_FMT("Type mismatch!")); break;
    case QSP_ERR_STACKOVERFLOW: str = QSP_STATIC_STR(QSP_FMT("Stack overflow!")); break;
    case QSP_ERR_TOOMANYITEMS: str = QSP_STATIC_STR(QSP_FMT("Too many items in expression!")); break;
    case QSP_ERR_CANTLOADFILE: str = QSP_STATIC_STR(QSP_FMT("Can't load file!")); break;
    case QSP_ERR_GAMENOTLOADED: str = QSP_STATIC_STR(QSP_FMT("Game not loaded!")); break;
    case QSP_ERR_COLONNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Sign [:] not found!")); break;
    case QSP_ERR_CANTINCFILE: str = QSP_STATIC_STR(QSP_FMT("Can't add file!")); break;
    case QSP_ERR_CANTADDACTION: str = QSP_STATIC_STR(QSP_FMT("Can't add action!")); break;
    case QSP_ERR_EQNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Sign [=] not found!")); break;
    case QSP_ERR_LOCNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Location not found!")); break;
    case QSP_ERR_ENDNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("[end] not found!")); break;
    case QSP_ERR_LABELNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Label not found!")); break;
    case QSP_ERR_NOTCORRECTNAME: str = QSP_STATIC_STR(QSP_FMT("Incorrect variable's name!")); break;
    case QSP_ERR_QUOTNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Quote not found!")); break;
    case QSP_ERR_BRACKNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Bracket not found!")); break;
    case QSP_ERR_BRACKSNOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Brackets not found!")); break;
    case QSP_ERR_SYNTAX: str = QSP_STATIC_STR(QSP_FMT("Syntax error!")); break;
    case QSP_ERR_UNKNOWNACTION: str = QSP_STATIC_STR(QSP_FMT("Unknown action!")); break;
    case QSP_ERR_ARGSCOUNT: str = QSP_STATIC_STR(QSP_FMT("Incorrect arguments' count!")); break;
    case QSP_ERR_CANTADDOBJECT: str = QSP_STATIC_STR(QSP_FMT("Can't add object!")); break;
    case QSP_ERR_CANTADDMENUITEM: str = QSP_STATIC_STR(QSP_FMT("Can't add menu's item!")); break;
    case QSP_ERR_TOOMANYVARS: str = QSP_STATIC_STR(QSP_FMT("Too many variables!")); break;
    case QSP_ERR_INCORRECTREGEXP: str = QSP_STATIC_STR(QSP_FMT("Regular expression's error!")); break;
    case QSP_ERR_CODENOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Code not found!")); break;
    case QSP_ERR_LOOPWHILENOTFOUND: str = QSP_STATIC_STR(QSP_FMT("Loop condition not found!")); break;
    default: str = QSP_STATIC_STR(QSP_FMT("Unknown error!")); break;
    }
    return str;
}
