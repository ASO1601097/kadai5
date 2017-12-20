#include <stdio.h>
#include <string.h>

#define STR 128

void lan_dec(char bf[] , char fname[] ,int n);

/*************************************************/
/*                                               
/*				メイン関数
/*                                               
/*************************************************/
int main(void){
	
	int i = 0;
	int ch;
	FILE *fp;
	char fname[STR];                                        /*ファイル名格納用の配列*/
	char bef[STR];                                          /*復元前文字列の格納用配列*/
	
	printf("ファイル名：");
	scanf("%s",fname);
	
	if((fp = fopen(fname,"rb")) == NULL){
		printf("\aファイルをオープンできません\n");         /*エラー時*/
	}
	else{
		printf("復元前の文字列：");
		while((ch = fgetc(fp)) != EOF){                     /*終端文字列を見るまで文字列表示*/
			putchar(ch);
			bef[i] = ch;
			i++;
		}
		fclose(fp);
		printf("\n");
		
	}
	putchar('\n');
	lan_dec(bef,fname,i);
	
	return 0;
}
/*************************************************/
/*                                               
/*	デコード・表示処理、ファイル書き込み処理
/*                                   
/*************************************************/
void lan_dec(char bf[] , char fname[] ,int n){
	
	int i = 0;
	int cnt = 0;
	FILE *fp;
	fp = fopen(fname,"wb");
	
	printf("復元後の文字列：");
	if(fp == NULL){
		printf("\aファイルをオープンできません\n");
	}
	for(i = 0 ; i < n; i++){
		if(bf[i] == '@'){
				cnt = bf[i + 1] - '0';                      /*変数cntに@の次の数字を格納*/
				
				while(cnt > 1){                             /*@の次の数字分ループ*/
					putchar(bf[i + 2]);
					cnt--;
					fputc(bf[i + 2], fp );
				}
				i = i + 1;
		}
		else{
			putchar(bf[i]);
			fputc(bf[i] , fp);
		}
	}
	fclose(fp);

}
