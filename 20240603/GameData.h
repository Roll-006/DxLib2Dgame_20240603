#pragma once
/*
 データの構造とグローバル変数宣言
*/

#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

//定数 (変わることがない数字)
#define SCREEN_X 800            //画面の大きさ
#define SCREEN_Y 600            //画面の大きさ
#define CIRCLE_POS_X 400        //円のX座標
#define CIRCLE_POS_Y 300        //円のY座標
#define CIRCLE_RADIUS_START 10  //スタート時の円の半径
#define CIRCLE_RADIUS_MAX 200   //円の最大の大きさ
#define RESULT_STRING_X 15      //
#define RESULT_STRING_Y 15      //
#define STRAT_STRING_X 230      //
#define STRAT_STRING_Y 520      //

//変数
typedef struct circle //円の構造体
{
    int posX;       //円のX座標
    int posY;       //円のY座標
    int radius;     //円の半径
    double area;    //円の面積
}circle;

//ゲームフラグ
extern bool enterPressedLastFrame;     //エンターキーが押されたかどうかのフラグ
extern bool gameStartFlag;             //ゲーム開始フラグ
extern bool circleGenerationFlag;      //円の生成フラグ
extern bool gameEndFlag;               //ゲーム終了フラグ
extern bool enterPressAllowed;         //エンターキーを押されているかを許可する

//ゲームカウント
extern int enterPressCount;    //エンターが何回押されたか
//構造体を変数にする
extern circle Circle;
//円の最大面積
extern double circleAreaMax;
//円の面積割合
extern double circlePorpotoin;

//フレームカウント
extern double frameCount;
//カウント前
extern int prevCount;
//カウント後
extern int nowCout;

//画像ハンドル変数
extern int startScreenImage;
//アルファ値
extern int alpha;