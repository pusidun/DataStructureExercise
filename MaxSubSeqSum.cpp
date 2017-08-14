#include<cstdio>
using namespace std;

//比较三个数大小 
int max3(int a,int b,int c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}

int DividAndConquer(int List[],int left,int right)
{
	int maxLeftSum,maxRightSum;//左右子问题结果 
	int maxBoarderLeftSum,maxBoarderRightSum;//边界最值 
	int boarderLeftSum,boarderRightSum;
	//递归结束条件 
	if(left==right)
	{
		if(List[left]>0) return List[left];
		else return 0;
	}
	
	int mid=(left+right)/2;
	maxLeftSum=DividAndConquer(List,left,mid);
	maxRightSum=DividAndConquer(List,mid+1,right);
	
	maxBoarderLeftSum=0;
	boarderLeftSum=0;
	for(int i=mid;i>=left;i--)
	{
		boarderLeftSum+=List[i];
		if(boarderLeftSum>maxBoarderLeftSum)
			maxBoarderLeftSum=boarderLeftSum;
	}
	maxBoarderRightSum=0;
	boarderRightSum=0;
	for(int i=mid+1;i<=right;i++)
	{
		boarderRightSum+=List[i];
		if(boarderRightSum>maxBoarderRightSum)
			maxBoarderRightSum=boarderRightSum;
	}
	
	return max3(maxLeftSum,maxRightSum,maxBoarderLeftSum+maxBoarderRightSum);
}

int MaxSubseqSum3(int List[],int N)
{
	return DividAndConquer(List,0,N-1);
}

int main()
{
	int L[6]={-1,3,5,-2,7,8};
	printf("%d\n",MaxSubseqSum3(L,6));
	return 0;
}
