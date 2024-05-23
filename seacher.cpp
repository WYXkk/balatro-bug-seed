#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)

int seed_length=0;
int prefix_length=0;
char all_char[]="123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";int chars=35;
int found_count=0;
char current_seed[10];
const double pi=3.141592653589793238462643383279502884;
FILE *f=stdout;

double process(double current,char c,int index)
{
	return fmod((1.1239285023/current)*c*pi+pi*index,1);
}

void simulate_process(char* s,char* prefix="")
{
	double current=1;
	printf("%s%.10e\n",prefix,current);
	int n=strlen(s);
	for(int i=n-1;i>=0;i--)
	{
		printf("%s->%c->",prefix,s[i]);
		current=process(current,s[i],i+1+prefix_length);
		printf("%.10e\n",current);
	}
}
const double threshold=1e-5;
int threshold_hit_count=0;

void output_current_seed(int current_depth)
{
	fprintf(f," ");
	for(int i=1;i<=seed_length-current_depth;i++) fprintf(f,"*");
	for(int i=seed_length-current_depth+1;i<=seed_length;i++) fprintf(f,"%c",current_seed[i]);
	++found_count;
	if(f!=stdout) {
		current_seed[seed_length+1]=0;
		printf("\t\tA new seed found: ");
		for(int i=1;i<=seed_length-current_depth;i++) printf("*");
		for(int i=seed_length-current_depth+1;i<=seed_length;i++) printf("%c",current_seed[i]);
		printf("\n");
		simulate_process(current_seed+seed_length-current_depth+1,"\t\t");
	}
}

void seed_search(double current,int current_depth)
{
	if(current_depth==seed_length)
	{
		if(fabs(current)>threshold) return;
		else ++threshold_hit_count;
	}
	if(current==0) {output_current_seed(current_depth-1);return;}
	if(current_depth>seed_length) return;
	for(int i=0;i<chars;i++)
	{
		current_seed[seed_length-current_depth+1]=all_char[i];
		if(current_depth==1&&seed_length==8) if(f!=stdout)
			printf("\tSearching all *******%c...\n",all_char[i]);
		seed_search(process(current,all_char[i],prefix_length+seed_length-current_depth+1),current_depth+1);
	}
}

int main()
{
	for(prefix_length=3;prefix_length<=18;prefix_length+=1)
	{
		f=fopen("result.txt","a");
		fprintf(f,"In prefix length %d:\n",prefix_length);
		if(f!=stdout) printf("Searching prefix length %d...\n",prefix_length);
		for(seed_length=1;seed_length<=8;seed_length++)
		{
			fprintf(f,"Length %d buggy seeds:",seed_length);
			threshold_hit_count=0;
			found_count=0;
			seed_search(1,1);
			if(found_count==0) fprintf(f," [None]");
			fprintf(f,", with %d threshold hits\n",threshold_hit_count);
		}
		fprintf(f,"\n---------------------------------\n");
		fclose(f);
	}
	return 0;
}
