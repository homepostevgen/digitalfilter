// Processing.cpp: implementation of the CProcessing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Processing.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcessing::CProcessing()
{

}

CProcessing::~CProcessing()
{

}

//Перестановка массива: Data-исходный массив, NumOfPoints-объем выборки
void CProcessing::FFTReorder(complex<float> Data[],unsigned int NumOfPoints)
{
	for (int j=0;j<NumOfPoints;j++)
	{          //Вычисление номера элемента из исходного
		int inverse=0;
		int l=1;
		int t=NumOfPoints/2;
		for(int d=1;d<NumOfPoints;d*=2)
		{
			inverse=inverse+l*(j&t)/t;                      
			l=l*2;
			t=t/2;
		}

		if(j<inverse)                       //Гарантия того, что не произойдет обратной перестановки
		{
			complex<float> temp;           //Перестановка элементов
			temp=Data[j];
			Data[j]=Data[inverse];
			Data[inverse]=temp;
		}
	}
}
//Быстрое преобразование Фурье:Data-исходный массив(в него же и запишутся новые данные),NumOfPoints-объем выборки
//итерационный метод
//сначала необходимо сделать перестановку массива функцией-членом ReOrdeer
//Dir-направление преобразования:1 - прямое, -1 - обратное(перед обратным тоже необхдимо обработать массив функцией-членом ReOrder)
//ВАЖНО!!!!! Если мы делаем Фурье-преобразование последовательности, а затем делаем обратное преобразование, то
//последовательность, полученную после обратного преобразования нужно поделить на размер выборки N.
void CProcessing::FFT(complex<float> Data[],unsigned int NumOfPoints,int Dir)
{
	int Step, HalfStep;
	int b;
	double pi=3.1415926535897932384626433832;
	complex <float> wtemp ; 
	Step = 1;
	while (Step < NumOfPoints) 
	{
		HalfStep = Step;
		Step *= 2;
		complex <float> w(1,0);                         //не храним cos(x), храним cos(x)-1 в виде -2sin^2(x/2);
		complex <float> Root(-2*sin(Dir*pi/(2*HalfStep))*sin(Dir*pi/(2*HalfStep)),sin(Dir*pi/HalfStep));
		int L,R; 
		for (b = 0; b < HalfStep; b++)
		{
			for (L=b; L<NumOfPoints; L+=Step)
			{
				complex <float>TRight,TLeft;    //Бабочка     
				R=L+HalfStep;
				TLeft=Data[L];TRight=Data[R];
				TRight = TRight * w;
				Data[L] = TLeft + TRight;
				Data[R] = TLeft - TRight;
			}
			                                         
			wtemp=w;      //Переход к следующему поворачивающему множителю привет
			w=w*Root;
			w=w+wtemp;
		}
	}
	
}



void CProcessing::Gilbert(complex<float> Data[],unsigned int NumOfPoints)
{
	complex <float> doubler(2,0);
	complex <float> zero(0,0);
	int a;
	float re,im;
	for(a=0; a<NumOfPoints; a++)
	{
		if (a<NumOfPoints/2)
		{
			
			Data[a]=Data[a]*doubler;
			
		}
		else
		{
			
			Data[a]=Data[a]*zero;
		}
	}
}
