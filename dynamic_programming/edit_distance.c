#include <stdio.h>
#include <string.h>

int edit_distance(char*,char*,int,int);
int min(int,int,int);

int main(){
	char* str1 = "SATURDAY";
	char* str2 = "SUNDAY";
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int result = edit_distance(str1,str2,l1,l2);
	printf("Edit distance = %d  ",result);
	return 0;

}

int edit_distance(char* s1, char* s2, int M , int N){
	int matrix[M+1][N+1];
	for(int i =0; i<=M; i++){
		matrix[0][i]= i;
	}
	for(int i =1; i<=N; i++){
		matrix[i][0] = i;
	}

	for(int i = 1; i <= M; i++){
		for(int j = 1; j<= N; j++){
			if(s1[i-1] == s2[j-1]){
				matrix[i][j] = matrix[i-1][j-1];
			}else{
				matrix[i][j] = min(matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]) + 1;
			}
		}
	}
	return matrix[M][N];

}


int min(int x,int y, int z){
	int temp = (x<y)?x:y;
	return (temp<z)?temp:z;
}
