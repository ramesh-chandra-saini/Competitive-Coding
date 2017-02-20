#include<string.h>
#include<stdlib.h>
#define gc getchar_unlocked
using namespace std;
typedef long long int INT;
inline void read(INT &x)
{
	register INT c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write(long long int a)
{
    char snum[35];
    int i = 0;
    do
    {
        snum[i++] = a%10 +48;
        a = a/10;

    }while(a!= 0);
    --i;
    while(i>=0)
    putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}
