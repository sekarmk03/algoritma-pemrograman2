#include "header.h"

int main()
{
	int spasi = 0;
	int i;
	char pita[200];
	printf("Masukkan string pita :\n");
	scanf("%199[^\n]s", pita);
	
	startKata(pita);

	for (i = 0; i < spasi; ++i)
	{
		printf(" ");
	}
	printf("%s\n", getCurrentKata());
	spasi += getPanjangKata();

	while(eopKata(pita) == 0) {
	    incKata(pita);
	    for (i = 0; i < spasi; ++i)
		{
			printf(" ");
		}
		printf("%s\n", getCurrentKata());
		spasi += getPanjangKata();
	}
	return 0;
}