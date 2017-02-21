#include <stdbool.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void ConvertToLowestTerms(int &firstNum, int &secondNum)
{
    int Low_Value, High_Value;

    if(firstNum > secondNum)
    {
    	Low_Value = secondNum;
     	High_Value = firstNum;
    }
    else
    {
    	High_Value = secondNum;
    	Low_Value = firstNum;
    }

    for(int i = Low_Value; i > 0;i--)
    {
    	if((Low_Value % i == 0) && (High_Value % i == 0))
        {
    		firstNum = firstNum/i;
    		secondNum = secondNum/i;

    		break;
        }
   }
}

struct company
{
    int candidates;
    int not_selected;

    void init (int candidates)
    {
        this->candidates = candidates;
        this->not_selected = candidates - 1;;
    }
};

int main ()
{
    company A, B ,C;
    A.init(12);
    B.init(15);
    C.init(10);

    int top = A.not_selected * B.not_selected * C.not_selected;
    int bottom = A.candidates * B.candidates * C.candidates;

    ConvertToLowestTerms(top, bottom);

    int hundred_percent = bottom;

    printf("%d/%d", hundred_percent - top, bottom);

    return 0;
}
