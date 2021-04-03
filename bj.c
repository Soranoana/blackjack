#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){

	//乱数シード宣言
	srand((unsigned)time(NULL));

	//各種宣言
	int a[13][4]/*使った確認*/, b/*選択肢*/, i, k/*絵柄*/, l, m, x, h, s/*数字*/,c[100]/*手札格納*/;
	//各種宣言　ゲームループ用
	int j=0,r;

	while (1){
		//ゲーム回数
		j++;

		//ヘッダー
		printf("BLACK JACK\n");
		if (j != 1){
			printf("Now game is %d times.\n\n", j);
		}

		//デッキの初期化
		for (i = 0; i < 13; i++){
			a[i][0] = 0;
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}

		//無限ループ
		for (i = 0; i < 52; i++){

			//問答及び選択肢取り込み
			printf("Q.  HIT  or  STAY  ?\nA. HIT is type 1.\n  STAY is type any number.//");
			scanf("%d", &b);

			//合計表示未確認
			x = 0;

			//ステイ条件
			if (b != 1)break;

			//手札表示
			printf("手札：");

			//手札確定ループ
			while (1){
				h = (rand() % 13);
				k = (rand() % 4);
				if (a[h][k] == 0)break;
			}

			//使った確認
			a[h][k] = 1;

			//手札に格納
			c[i] = k * 100 + h;

			//合計計算!!!!!!!!!
			m = 0;
			for (l = 0; l <= i; l++){
				if (c[l] / 100 < 1){
					s = c[l] + 1;
					printf("ﾊｰﾄ%d  ", s);
				}
				else if (c[l] / 100 < 2){
					s = c[l] - 100 + 1;
					printf("ﾀﾞｲﾔ%d  ", s);
				}
				else if (c[l] / 100 < 3){
					s = c[l] - 200 + 1;
					printf("ｽﾍﾟｰﾄﾞ%d  ", s);
				}
				else {
					s = c[l] - 300 + 1;
					printf("ｸﾗﾌﾞ%d  ", s);
				}
				if (s < 10){
					m += s;
				}
				else {
					m += 10;
				}
			}

			//合計表示
			printf("\n合計：%d\n", m);

			//合計表示確認
			x = 1;

			//バースト条件
			if (m > 21)printf("Burst!!!\n\n\n");
			if (m > 21)break;

			//BJ条件
			if (m == 21)printf("BLACK JACK!!!\n\n\n");
			if (m == 21)break;

			//改行
			printf(" \n");
		}
		//ゲームを続行するか
		printf("Continue?\nContinue is type 1.\nQuit is type any nomber.\n//");
		scanf("%d", &r);
		if (r != 1)break;

	}

	printf("Thank for your playing!\nSee you again.\n\n");

	return 0;
}