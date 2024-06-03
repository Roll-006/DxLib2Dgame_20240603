/*
 エンターを押したら円が縮小・拡大を繰り返す
 もう一度エンターを押すと円の動きが停止する
 
 円の最小値は10、最大値は200
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

//変数
typedef struct circle //円の構造体
{
    int posX;       //円のX座標
    int posY;       //円のY座標
    int radius;     //円の半径
    double area;    //円の面積
}circle;

//ゲームフラグ
bool enterPressedLastFrame = false;     //エンターキーが押されたかどうかのフラグ
bool gameStartFlag = false;             //ゲーム開始フラグ
bool circleGenerationFlag = true;       //円の生成フラグ
bool gameEndFlag = false;               //ゲーム終了フラグ
bool enterPressAllowed = true;          //エンターキーを押されているかを許可する
//(bool型 : trueかfalseかのみ)

//ゲームカウント
int enterPressCount;    //エンターが何回押されたか
//構造体を変数にする
circle Circle;
//円の最大面積
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//円の面積割合
double circlePorpotoin = 0.0f;

//フレームカウント
double frameCount = 0;
//デルタ時間
int prevCount, nowCout;

//メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)//Windowsのメインで動かす
{
    //基本設定
    ChangeWindowMode(TRUE);                 //Windowsの画面をアクティブにする
    DxLib_Init();                           //DxLibの初期化
    SetMainWindowText("タイミングゲーム");  //WindowTextの表示変更
    SetDrawScreen(DX_SCREEN_BACK);          //画面の背景は黒
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);   //画面の大きさ

    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    //色指定
    int CircleColor = GetColor(128, 128, 128);
    int resultColor = GetColor(255, 255, 255);
    //円の描画
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;
    //フレームカウント初期化
    nowCout = prevCount = GetNowCount();

    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //時間を獲得
        nowCout = GetNowCount();
        //デルタタイム
        double deltaTime = (nowCout - prevCount)/1000.0f;

        //フレームカウントに追加
        frameCount += deltaTime;

        //画面の初期化
        ClearDrawScreen();

        //エンターキーを押してゲームをスタート
        if (enterPressAllowed && CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            enterPressCount++;
            if (enterPressCount % 2 == 1)
            {
                //ゲームの開始
                gameStartFlag = true;
                gameEndFlag = false;
            }
            else
            {
                //ゲーム終了フラグ
                gameEndFlag = true;
                gameStartFlag = false;
                enterPressAllowed = false;
            }
        }
        //エンターキーが押されたかを記憶させる
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);
        //終了フラグがfalseであれば
        if (!gameEndFlag)
        {
            //円の変化をつける
            if (gameStartFlag)
            {
                if (frameCount >= 1.0f / 60.f)
                {
                    frameCount = 0;
                    //大きくする
                    if (circleGenerationFlag)
                    {
                        //半円を5ずつ増やす
                        Circle.radius += 5;
                        //半径が最大値になったときフラグを変換
                        if (Circle.radius >= CIRCLE_RADIUS_MAX)
                        {
                            circleGenerationFlag = false;
                        }
                    }
                    //半径を5ずつ減らす
                    else
                    {
                        Circle.radius -= 5;
                        //半円が最小値になったときフラグを変換
                        if (Circle.radius <= CIRCLE_RADIUS_START)
                        {
                            circleGenerationFlag = true;
                        }
                    }
                }

            }
        }
        else
        {
            //リザルトを出力
            Circle.area = M_PI * (double)Circle.radius * (double)Circle.radius;
            //面積の割合合計
            circlePorpotoin = Circle.area / circleAreaMax * 100;
            //画面に描画
            SetFontSize(30);
            DrawFormatString(RESULT_STRING_X, RESULT_STRING_Y, resultColor, "円の割合は%.1f%%です", circlePorpotoin);
        }

        //円の描画
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CircleColor);

        //裏画面の内容を表画面に反映させる
        ScreenFlip();

        //処理したフレームの時間
        prevCount = nowCout;
    }

    //Dxlib終了処理
    DxLib_End();

    return 0;
}