// CSE373  Assignment-3
// Longest Common Subsequence algorithm


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxValue(int n1, int n2){
	int result;
	result = (n1 > n2) ? n1 : n2;
	
	return result;
}

void lcs(char *s1, char *s2, int m, int n){
	// define lcs table
	int lcsTable[m + 1][n + 1];
	
	// define tracer table;
	char tracerTable[m + 1][n + 1];
	
	// index variable to traverse row and column of lcs table
	int i, j;
	
/*
	// base case - if one of the subsequence element is 0
	// then set the value of that element 0
	for(i = 0; i <= m; i++) {
		lcsTable[i][0] = 0;
	}
	for(j = 0; j <= n; j++) {
		lcsTable[0][0] = 0;
	}
*/
	
	// fill the lcs table
	// c means cross, l means left, u means upper 
	// elements in lcs table
	for(i = 0; i <= m; i++){
		for(j = 0; j <= n; j++){
			if(i == 0 || j == 0){
				lcsTable[i][j] = 0;
			}
			else if(s1[i - 1] == s2[j - 1]){
				lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
				tracerTable[i][j] = 'c';
			}
			/*
			else if(lcsTable[i - 1][j] >= lcsTable[i][j - 1]){
				lcsTable[i][j] = lcsTable[i - 1][j];
				tracerTable[i][j] = 'u';
			}
			else if(lcsTable[i - 1][j] <= lcsTable[i][j - 1]){
				lcsTable[i][j] = lcsTable[i][j - 1];
				tracerTable[i][j] = 'l';
			}
			*/
			else{
				lcsTable[i][j] = maxValue(lcsTable[i - 1][j], lcsTable[i][j - 1]);
			}
		}
	}
	
	
	
	// Index of LCS length
	int lcsIndex = lcsTable[m][n];
	
	// create a char array to store lcs string
	char lcsStr[lcsIndex + 1];
	lcsStr[lcsIndex] = '\0';

	// here, p = i, q = j
	int p = m, q = n;
	while(p > 0 && q > 0){
		if(s1[p - 1] == s2[q - 1]){
			lcsStr[lcsIndex - 1] = s1[p - 1];
			p--;
			q--;
			lcsIndex--;
		}
		else if(lcsTable[p - 1][j] > lcsTable[i][q - 1]){
			p--;
		}
		else{
			q--;
		}
	}	
	
	// store the lcs length to print
	int lcsLength = strlen(lcsStr);
	//printf("\nLCS Length: %d\n", lcsLength);
	
	
	// print LCS
	printf("\nLCS = %s, length = %d\n", lcsStr, lcsLength);
	
}

int main()
{
	printf("LCS Algorithm\n");
	
	// define variables for string sequence input
	char str1[15], str2[15];
	
	// take 2 string sequence input 
	printf("\nEnter first string sequence: ");
	scanf("%s", str1);
	printf("\nEnter Second string sequence: ");
	scanf("%s", str2);
	
	// find the length of str1 and str2
	int str1Length, str2Length;
	
	str1Length = strlen(str1);
	str2Length = strlen(str2);
	
	// pass the str1 and str2 into lsc() function
	// to find out the Longest Common Subsequence
	lcs(str1, str2, str1Length, str2Length);
	
	
	

	return 0;
}

