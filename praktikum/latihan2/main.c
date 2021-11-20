#include "header.h"

int main()
{
	int i, n = 0;
	char pita[200];
	scanf("%199[^\n]s", pita);
	
	startKata(pita);
	word kata[50];
	strcpy(kata[n].str, getCurrentKata());
	kata[n].len = getPanjangKata();
	n++;

	while(eopKata(pita) == 0) {
	    incKata(pita);
	    strcpy(kata[n].str, getCurrentKata());
		kata[n].len = getPanjangKata();
		n++;
	}

	quick(0, n-1, kata);

	for (i = 0; i < n; ++i)
	{
		printf("%s\n", kata[i].str);
	}
	return 0;
}