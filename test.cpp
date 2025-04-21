//this is a demo document used to be tested



// #include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int temp[1110];//临时数组----stack--栈
//int n,res=1;//res代表的是方案数目
//int ans[1010][1010];//优化成动态数组
//void dfs (int x)//x表示的是，搜索到第几位
//{
//    if(x>n)//搜索完了
//    {
//        for(int i=1;i<=x;i++)//优化成栈
//            ans[res][i]=temp[i];
//        res++;
//        return ;
//    }
//    for(int i=0;i<=1;i++)//每一位上有这两种状态，分别是01
//    {
//        temp[x]=i;
//        dfs(x+1);
//    }
//}
//int main ()
//{
//    cin>>n;
//
//    dfs(1);
//    for(int i=1;i<res;i++)
//    {
//        for(int j=1;j<=n;j++)
//            cout<<ans[i][j];
//        cout<<endl;
//    }
//    //cout<<res<<endl;
//    return 0 ;
//}