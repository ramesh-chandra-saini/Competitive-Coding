from array import *
import sys
INT_MAX=sys.maxint+1
final_ans=INT_MAX
def currWoodAmount(H,R,N,L,Time):
	ans,i=0,0
	while (i<N):
		if(L<=H[i]+Time*R[i]):
			ans=ans+H[i]+Time*R[i]
		i=i+1
	return ans
    
def findMinTime(H,R,N,W,L,minTime,maxTime,final_ans):
	if(minTime<=maxTime):
		Time = (minTime+maxTime)/2;
		currAmount=currWoodAmount(H,R,N,L,Time);
		if(currAmount>=W):
			final_ans=min(final_ans,Time);
			findMinTime(H,R,N,W,L,minTime,Time-1,final_ans);
		else:
			findMinTime(H,R,N,W,L,Time+1,maxTime,final_ans);
    	
def main():
	N,W,L = map(int,raw_input().split())
	H=[]
	R=[]
	i=0
	while(i<N):
		height,rate=map(int,raw_input().split())
		H.append(height)
		R.append(rate)
		i=i+1
	print H
	print R	
	minTime=0
	maxTime=INT_MAX
	findMinTime(H,R,N,W,L,minTime,maxTime,final_ans)
	print final_ans
	print '\n'
main()

