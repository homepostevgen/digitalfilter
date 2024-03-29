// WaveView.cpp : implementation of the CWaveView class
//

#include "stdafx.h"
#include "Wave.h"

#include "WaveDoc.h"
#include "WaveView.h"
#include "windows.h"
#include "iostream.h"
#include "fstream"
#include "math.h"
#include "mmsystem.h"
#include "Processing.h"

using namespace std;

CPoint cp;                 // ������� ��������� ������ Cpoint ��� ����, ����� �������� ���������  ������� �� ���� 
bool DrawControl=false;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaveView

IMPLEMENT_DYNCREATE(CWaveView, CView)

BEGIN_MESSAGE_MAP(CWaveView, CView)
	//{{AFX_MSG_MAP(CWaveView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWaveView construction/destruction

CWaveView::CWaveView()
{
	// TODO: add construction code here

}

CWaveView::~CWaveView()
{
}

BOOL CWaveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView drawing

void CWaveView::OnDraw(CDC* pDC)
{
	
	float B[11] = {
    0.08306875189132,  0.08765184145022,  0.09135000361666,  0.09406489166095,
    0.09572368693989,  0.09628164888191,  0.09572368693989,  0.09406489166095,
    0.09135000361666,  0.08765184145022,  0.08306875189132
};
	
	
	
	if(DrawControl){
	
		CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(cp.x*20,128); // ������������� ���������� ������� ����. cp.x ��� ���������� �� � ��������� �������
	pDC->SetViewportExt(rectClient.right,-rectClient.bottom);
	//pDC->SetViewportOrg(0,rectClient.bottom/4);
	pDC->SetViewportOrg(0,rectClient.bottom/2);
	
	int n=200;
	//byte *buffer= new byte[points];
	byte buffer[150000];
	DWORD sample;
	HANDLE hFile;
	hFile=CreateFile("8000.wav", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwBytesRead; 
	ReadFile(hFile, &buffer, sizeof(buffer), &dwBytesRead, (LPOVERLAPPED)NULL);
	CloseHandle(hFile);
	//PlaySound("Untitled.wav",NULL,SND_FILENAME | SND_ASYNC);
	/*ifstream File("Untitled.wav");	//��������� ����� ��� ������ ������
	if (!File)sample=256;
	else sample=16;
	for(int j=0;j<n;j++)
		{
			//File>>sample;
		//	if (j>208)
			File>>buffer[j];
		}
	File>>sample;
	File.close();*/
	
	HPEN hPen3=CreatePen(PS_SOLID,0,RGB(0,0,0)); //��������� �������� ����
		pDC->SelectObject(hPen3);
	
	pDC->LineTo(0,(buffer[0+105]-128)*cp.y/200);
	pDC->LineTo(1,(buffer[1+105]-128)*cp.y/200);
	
	for(int i=11;i<cp.x*20;i++)
	{
		
		//	pDC->MoveTo(i,0);                            //��������� � ������� ������������ �����
		//	pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200);
			
		
		pDC->LineTo(i,((B[10]*buffer[i-10+105]+B[9]*buffer[i-9+105]+B[8]*buffer[i-8+105]+B[7]*buffer[i-7+105]+B[6]*buffer[i-6+105]+B[5]*buffer[i-5+105]
			+B[4]*buffer[i-4+105]+B[3]*buffer[i-3+105]+B[2]*buffer[i-2+105]+B[1]*buffer[i-1+105]+B[0]*buffer[i+105])-128)*cp.y/200);
		//pDC->MoveTo(i,0);
		//pDC->LineTo(i,(buffer[i+105]-128)*cp.y/180);
		
		
		//pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200); // ��������� � ������� ���������� �����
		Sleep(0);
	}
	


  HPEN hPen=CreatePen(PS_DOT,0,RGB(0,0,255)); //��������� �������� ����
		pDC->SelectObject(hPen);
pDC->MoveTo(2,0);
	for(int j=11;j<cp.x*20;j++)
	{
		
		//	pDC->MoveTo(i,0);                            //��������� � ������� ������������ �����
		//	pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200);
			
		
		//pDC->LineTo(i,((buffer[i-2+105]+buffer[i-1+105]+buffer[i+105]+buffer[i+1+105]+buffer[i+2+105])/5-128)*cp.y/200);
		//pDC->MoveTo(i,0);
		pDC->LineTo(j,(buffer[j+105]-128)*cp.y/200);
		
		
		//pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200); // ��������� � ������� ���������� �����
		Sleep(0);
	}


	/*
	HPEN hPen2=CreatePen(PS_DASH,1,RGB(255,0,0)); //��������� �������� ����
		pDC->SelectObject(hPen2);
	
	pDC->MoveTo(4,0);
	for(int k=4;k<cp.x*20;k++)
	{
		
		//	pDC->MoveTo(i,0);                            //��������� � ������� ������������ �����
		//	pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200);
			
		
		//pDC->LineTo(i,((buffer[i-2+105]+buffer[i-1+105]+buffer[i+105]+buffer[i+1+105]+buffer[i+2+105])/5-128)*cp.y/200);
		//pDC->MoveTo(i,0);
		pDC->LineTo(k,((buffer[k-4+105]+buffer[k-3+105]+buffer[k-2+105]+buffer[k-1+1+105]+buffer[k+105]+buffer[k+1+105]+buffer[k+2+105]+buffer[k+3+105]+buffer[k+4+105])/9-128)*cp.y/200);
		
		
		//pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200); // ��������� � ������� ���������� �����
		Sleep(0);
	}*/
	}
	
		//points=cp.x;
		
			//pDC->TextOut(0,0,cp.x);
	
	CWaveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView printing

BOOL CWaveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWaveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWaveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView diagnostics

#ifdef _DEBUG
void CWaveView::AssertValid() const
{
	CView::AssertValid();
}

void CWaveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWaveDoc* CWaveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWaveDoc)));
	return (CWaveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWaveView message handlers

void CWaveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
		//PlaySound("Untitled.wav",NULL,SND_FILENAME | SND_ASYNC);
	
		// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CWaveView::OnRButtonDown(UINT nFlags, CPoint point) 
{

DrawControl=true;
		Invalidate(true);
cp.x=point.x;
cp.y=point.y;
	
	CView::OnRButtonDown(nFlags, point);
}

void CWaveView::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
		DrawControl=true;
		Invalidate(true);
		
		// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
