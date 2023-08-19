inline void getz(char *a,int n,int *z)
{
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;++i)
	{
		if(r<i) z[i]=0;
		else z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&a[z[i]+i]==a[z[i]+1])
			z[i]++;
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}

