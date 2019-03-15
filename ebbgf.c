#include <stdio.h>
#include <stdlib.h>
int main(){
	int *chaves = NULL;
	int *inputs = NULL;
	int n, mod, m, x;
	int poshash;
	scanf("%d", &m);
	for (int j = 0; j < m; ++j) {
	scanf("%d %d", &mod, &n);
	chaves = malloc(mod*sizeof(int));
	inputs = malloc(n*sizeof(int));
	for (int i = 0; i < mod; ++i){
		chaves[i] = 201;
		/* code */
	}
	for(int i = 0; i < n; i++){
		inputs[i] = 300;
		scanf("%d", &x);
		poshash = x % mod;
		if (!chaves[poshash]|| chaves[poshash] > 200){
			chaves[poshash] = x;
		} else{
			inputs[i] = x;}
	}
		for (int i = 0; i < mod; i++){
			printf("%d -> ", i);
			if (chaves[i] && chaves[i] <= 200){
				printf("%d -> ", chaves[i]);
				for (int l = 0;l < n; l++){
					if (inputs[l] % mod == i && inputs[l] < 201 )
						printf("%d -> ", inputs[l]); 
				}
			} 
			printf("\\\n");

			}
			if(j < m-1)
				printf("\n");
		}
}
