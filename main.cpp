#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1C_07_ササナミ_ソウシ_評価課題";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 500, 720);
	

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	Player *player = new Player();
	Enemy *enemy = new Enemy(player, { float(rand() % 400), 0.0f }, 2.0f);

	Enemy *enemyA = new Enemy(player,{float(rand()%480-200),0.0f}, 3.0f);

	//プレイヤーの体力
	int playerHp = 3;
	//シーン切り替え
	int scene = TITLE;
	int gameTimer = 0;
	//スコア
	int score = 0;
	

	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		switch (scene) {
		case TITLE:

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = GAME;
				player = new Player();
				enemy = new Enemy(player, { float(rand() % 400), 0.0f }, 2.0f);

				enemyA = new Enemy(player, { float(rand() % 480 - 200),0.0f }, 3.0f);
				playerHp = 3;
				gameTimer = 0;
				score = 0;
			}


			Novice::ScreenPrintf(200, 300, "TITLE");
			Novice::ScreenPrintf(180, 320, "PUSU TO ENTER");

			break;

		case GAME:
			gameTimer++;

			player->Update(keys,playerHp,score);
			enemy->Update(gameTimer,playerHp, score,{ float(rand() % 400), 0.0f });


			enemyA->Update(gameTimer, playerHp,score ,{ float(rand() % 480 - 200),0.0f });

			if (playerHp == 0) {
				scene = GAMEOVER;
			}

			if (gameTimer >= 2000) {
				scene = CLEAR;
				
			}

			//=================================================
			//描画
			//=================================================

			Novice::DrawLine(0, 600, 1280, 600, 0xFFFFFFF);
			player->Draw();
			enemy->Draw();
			enemyA->Draw();

			Novice::ScreenPrintf(10, 20, "playerHP=%d", playerHp);
			Novice::ScreenPrintf(10, 40, "Timer=%d", gameTimer/60);
			Novice::ScreenPrintf(10, 60, "score=%d", score);

			break;

		case CLEAR:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = TITLE;
				delete enemy;
				delete enemyA;
				delete player;
			}


			Novice::ScreenPrintf(200, 300, "score=%d", score);
			Novice::ScreenPrintf(180, 320, "PUSU TO ENTER");
			break;
		case GAMEOVER:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = TITLE;
				delete enemy;
				delete enemyA;
				delete player;
			}

			Novice::ScreenPrintf(200, 300, "score=%d", score);
			Novice::ScreenPrintf(180, 320, "PUSU TO ENTER");
			break;
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemy;
	delete enemyA;
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
