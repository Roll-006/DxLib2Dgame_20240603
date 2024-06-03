#pragma once
/*
 関数の宣言
*/

//※関数を作ったらsummaryは絶対作る

//関数の宣言

//<summary>
//スタート画面
//</summary>
//<param name="deltaTime">デルタタイム</param>
//<param name="startScreenImage">画像ハンドル</param>
void StartScreen(double deltaTime, int startScreenImage);
//<summary>
//ゲーム画面
//</summary>
//<param name="deltaTime">デルタタイム</param>
void GameProcessing(double deltaTime);
//<summary>
//リザルト画面
//</summary>
void ResultScreen();