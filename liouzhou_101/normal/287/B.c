i,k;long long n,p=1;main(){for(scanf("%I64d%d",&n,&k);k>1&&p<n;p+=--k)++i;printf("%d",p<n?-1:i);}