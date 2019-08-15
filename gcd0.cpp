#include<stdio.h>

int gcd(int a, int b)
{
	return a%b? gcd(b,a%b) : b; //b는 0이 아니다. 
}

int main()
{
	printf("유클리드 호제법을 활용한 디오판토스 일차선형방정식 계산기\n\n");
	printf("방정식의 계수를 순서대로 입력하시오.\nax+by=c 에서 a, b, c를 띄어쓰기로 구분하여 순서대로\n\n");
	
	int a,b,c,d;
	int r, r1, r2, q[50] = {0};
	int s[50] = {1,0};
	int t[50] = {0,1};
	
	scanf("%d %d %d",&a, &b, &c);
	
	d = gcd(a,b);
	r = a;
	r1 = b;
	int cnt = 0;
	while(r1 >= 1)
	{
		q[cnt+1] = r / r1;
		r2 = r%r1;
		if(cnt >= 2)
		{
			s[cnt] = s[cnt-2] - q[cnt-1] * s[cnt-1];
			t[cnt] = t[cnt-2] - q[cnt-1] * t[cnt-1];
		}
		r = r1;
		r1 = r2;
		cnt++;
	}
	s[cnt] = s[cnt-2] - q[cnt-1] * s[cnt-1];
	t[cnt] = t[cnt-2] - q[cnt-1] * t[cnt-1];
	
	int psx = s[cnt]*(c/d), psy = t[cnt]*(c/d);
	printf("\n************************************\ngcd : %d\nx.particular_solution : %d\ny.particular_solution : %d\n\n",d,psx,psy);
	
	if(b>0&&a>0)
	printf("x.solution : %d + %dk\ny.solution : %d - %dk",psx,b/d,psy,a/d);
	else if(b>0&&a<0)
	printf("x.solution : %d + %dk\ny.solution : %d + %dk",psx,b/d,psy,a/d);
	else if(b<0&&a>0)
	printf("x.solution : %d - %dk\ny.solution : %d - %dk",psx,b/d,psy,a/d);
	else
	printf("x.solution : %d - %dk\ny.solution : %d + %dk",psx,b/d,psy,a/d);
	
	// reference : Extended Euclidian Algorithm 
	
	return 0;	
}
