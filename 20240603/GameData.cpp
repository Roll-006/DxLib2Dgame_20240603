/*
 グローバル変数の初期化
*/
#include "GameData.h"

//グローバル変数の定義
//ゲームフラグ
bool enterPressedLastFrame = false;     //エンターキーが押されたかどうかのフラグ
bool gameStartFlag = false;             //ゲーム開始フラグ
bool circleGenerationFlag = true;       //円の生成フラグ
bool gameEndFlag = false;               //ゲーム終了フラグ
bool enterPressAllowed = true;          //エンターキーを押されているかを許可する
//(bool型 : trueかfalseかのみ)

//ゲームカウント
int enterPressCount = 0;    //エンターが何回押されたか
//構造体を変数にする
circle Circle;

//円の最大面積
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//円の面積割合
double circlePorpotoin = 0.0f;

//フレームカウント
double frameCount = 0;
//カウント前
int prevCount = 0;
//カウント後
int nowCout = 0;

//画像ハンドル変数
int startScreenImage;
//アルファ値
int alpha;