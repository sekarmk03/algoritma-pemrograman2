#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	int len;
	int alpro;
	int logif;
	int statistika;
	float avg;
}nilai;

void swap(nilai *old, nilai *new);
void pindahPos(char prev[], char dest[], int n, int m, nilai matriks[n][m]);
void printPos(int n, int m, nilai matriks[n][m]);

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);

	nilai matriks[n][m];

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%s %d %d %d", matriks[i][j].nama, &matriks[i][j].alpro, &matriks[i][j].logif, &matriks[i][j].statistika);
			matriks[i][j].len = strlen(matriks[i][j].nama);
			matriks[i][j].avg = ((matriks[i][j].alpro + matriks[i][j].logif + matriks[i][j].statistika)*100)/3;
		}
	}

	printf("Posisi Bangku Awal:\n");
	printPos(n, m, matriks);

	char prev[100], dest[100];

	scanf("%s", prev);

	while(strcmp(prev, "stop") != 0) {
	    scanf("%s", dest);

	    pindahPos(prev, dest, n, m, matriks);

	    scanf("%s", prev);
	}
	
	printf("\nPosisi Bangku Setelah Nilai Dicek:\n");
	printPos(n, m, matriks);
	return 0;
}

void swap(nilai *old, nilai *new){
	nilai tmp;

	strcpy(tmp.nama, old->nama);
	tmp.len = old->len;
	tmp.alpro = old->alpro;
	tmp.logif = old->logif;
	tmp.statistika = old->statistika;
	tmp.avg = old->avg;

	strcpy(old->nama, new->nama);
	old->len = new->len;
	old->alpro = new->alpro;
	old->logif = new->logif;
	old->statistika = new->statistika;
	old->avg = new->avg;

	strcpy(new->nama, tmp.nama);
	new->len = tmp.len;
	new->alpro = tmp.alpro;
	new->logif = tmp.logif;
	new->statistika = tmp.statistika;
	new->avg = tmp.avg;	
}

void pindahPos(char prev[], char dest[], int n, int m, nilai matriks[n][m]){
	int i, j, barisPrev, kolomPrev, barisDest, kolomDest;
	int found = 0;

	barisPrev = kolomPrev = barisDest = kolomDest = 0;

	i = 0;

	while((i < n) && (found == 0)) {
	    j = 0;
	    while((j < m) && (found == 0)) {
	    	if(strcmp(matriks[i][j].nama, prev) == 0){
	    		barisPrev = i;
	    		kolomPrev = j;
	    		found = 1;
	    	}
	        j++;
	    }
	    i++;
	}

	i = found = 0;
	while((i < n) && (found == 0)) {
	    j = 0;
	    while((j < m) && (found == 0)) {
	    	if(strcmp(matriks[i][j].nama, dest) == 0){
	    		barisDest = i;
	    		kolomDest = j;
	    		found = 1;
	    	}
	        j++;
	    }
	    i++;
	}

	if(matriks[barisPrev][kolomPrev].avg > matriks[barisDest][kolomDest].avg){
		swap(&matriks[barisPrev][kolomPrev], &matriks[barisDest][kolomDest]);
	}
}


void printPos(int n, int m, nilai matriks[n][m]){
	int i, j, k;
	int maxlen[m];

	for (i = 0; i < m; ++i)
	{
		maxlen[i] = 0;
		for (j = 0; j < n; ++j)
		{
			if(maxlen[i] < matriks[j][i].len) maxlen[i] = matriks[j][i].len;
		}
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%s", matriks[i][j].nama);
			if (j < m-1)
			{
				if (maxlen[j]-matriks[i][j].len > 0)
				{
					for (k = 0; k < maxlen[j]-matriks[i][j].len; ++k)
					{
						printf(" ");
					}
				}
				printf("  ");
			}
		}
		printf("\n");
	}
}