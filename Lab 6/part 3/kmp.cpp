#include <iostream>
#include <cstring>

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
  int i=1, j=0;
  lps[0] = -1;
  while(i<M){
    if (pat[j] != pat[i]){
      lps[i]=j;
      while( j>=0 && pat[j]!=pat[i]){
        j = lps[j];
      }
    }
    else{
      lps[i] = lps[j];
    }
    i += 1;
    j += 1;
  }
  lps[M] = j;
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int i=0;
	int j=0;
	int M = strlen(pat);
	int h[M+1];

	computeLPSArray(pat,M,h);

	while(i<strlen(txt)){
		if(pat[j] == txt[i]){
		i += 1;
		j += 1;
		if(j == M){
			printf("Found pattern at index %d \n", i-j);
			j = h[j];
		}
		}
		else{
		j = h[j];
		if (j<0){
			i += 1; j += 1;
		}
		}
	}
	// printf("Found pattern at index %d \n", index_where_found);
}
