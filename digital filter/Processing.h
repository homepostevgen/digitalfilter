// Processing.h: interface for the CProcessing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCESSING_H__8A50E9C5_AC2A_40EC_A3E6_D89D0F6634D6__INCLUDED_)
#define AFX_PROCESSING_H__8A50E9C5_AC2A_40EC_A3E6_D89D0F6634D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "complex"
using namespace std;

class CProcessing  
{
public:
	CProcessing();
	virtual ~CProcessing();
	
	void CProcessing::FFTReorder(complex <float> Data[],unsigned int NumOfPoints);
	void CProcessing::FFT(complex <float> Data[],unsigned int NumOfPoints,int Dir);
	void CProcessing::Gilbert(complex<float> Data[],unsigned int NumOfPoints);
};

#endif // !defined(AFX_PROCESSING_H__8A50E9C5_AC2A_40EC_A3E6_D89D0F6634D6__INCLUDED_)
