/*
ゲーム関数定義
*/

#include "GameData.h"
#include "GameFunction.h"

//スタート画面の処理
void StartScreen(double deltaTime, int startScreenImage)
{
    //メインからフレーム数を獲得
    frameCount += deltaTime * 1000;

    //文字の色
    int stringColor = GetColor(255, 99, 71);

    //画面の初期化
    ClearDrawScreen();

    //エンターキーを押してゲームをスタート
    if (enterPressAllowed && CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
    {
        gameStartFlag = true;
    }
    else
    {
        //画像の描画
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //アルファ値を計算
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

        //描画モードをブレンドモードに設定
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        SetFontSize(30);
        DrawFormatString(STRAT_STRING_X, STRAT_STRING_Y, stringColor, "Press Enter to Start");
        //描画モードで戻す
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    //裏画面に内容を表画面に反映させる
    ScreenFlip();
    //処理したフレーム時間
    prevCount = nowCout;
}

void GameProcessing(double deltaTime)
{

}
void ResultScreen()
{

}