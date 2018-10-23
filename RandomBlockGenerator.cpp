#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

char charset[20];
int m=0,n;

int main(int argc,char* argv[])
{
	if (argc==1)
	{
		printf("Please enter the size of iv: ");
		scanf("%d",&n);
	}
	else
		n=atoi(argv[1]);
	srand(time(0));
	for (int i=0;i<10;i++)
		charset[m++]=i+48;
	for (int i='A';i<'G';i++)
		charset[m++]=i;
	for (int i=1;i<=n;i++)
		printf("0x%c%c%c",charset[rand()%16],charset[rand()%16],i==n?'\n':',');
	return 0;
}