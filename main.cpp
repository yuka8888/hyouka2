#include <Novice.h>
#include "Title.h"
#include "Play.h"
#include "Clear.h"
#include "Over.h"
#include "Function.h"

const char kWindowTitle[] = "学籍番号";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Title* title = new Title;
	Play* play = new Play;
	Clear* clear = new Clear;
	Over* over = new Over;

	Scene scene = TITLE;



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene) {
			case TITLE:
				title->Update(keys);
				title->Draw();

				//次のシーンに行くか
				if (title->GetIsNextScene()) {
					scene = title->GetNextScene();
					title->Initialization();
				}
				break;

			case PLAY:
				play->Update(keys, preKeys);
				play->Draw();

				//次のシーンに行くか
				if (play->GetIsNextScene()) {
					scene = play->GetNextScene();
					play->Initialization();
				}
				break;

			case CLEAR:
				clear->Update(keys);
				clear->Draw();

				//次のシーンに行くか
				if (clear->GetIsNextScene()) {
					scene = clear->GetNextScene();
					clear->Initialization();
				}
				break;

			case OVER:
				over->Update(keys);
				over->Draw();

				//次のシーンに行くか
				if (over->GetIsNextScene()) {
					scene = over->GetNextScene();
					over->Initialization();
				}
				break;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::ScreenPrintf(0, 0, "scene = %d", scene);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete title;
	delete play;
	delete clear;
	delete over;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

