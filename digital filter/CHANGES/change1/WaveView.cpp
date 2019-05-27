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

CPoint cp;                 // создаем экземпл€р класса Cpoint дл€ того, чтобы получать положение  курсора на окне 
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
	if(DrawControl){
	
		CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(cp.x*20,128); // устанавливаем логические размеры окна. cp.x это координата по х положени€ курсора
	pDC->SetViewportExt(rectClient.right,-rectClient.bottom);
	//pDC->SetViewportOrg(0,rectClient.bottom/4);
	pDC->SetViewportOrg(0,rectClient.bottom/2);
	
	int n=200;
	//byte *buffer= new byte[points];
	byte buffer[150000];
	DWORD sample;
	HANDLE hFile;
	hFile=CreateFile("rednoise.wav", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwBytesRead; 
	ReadFile(hFile, &buffer, sizeof(buffer), &dwBytesRead, (LPOVERLAPPED)NULL);
	CloseHandle(hFile);
	//PlaySound("Untitled.wav",NULL,SND_FILENAME | SND_ASYNC);
	/*ifstream File("Untitled.wav");	//открываем файлы дл€ записи данных
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
	
	
	for(int i=0;i<cp.x*20;i++)
	{
		
			pDC->MoveTo(i,0);                            //рисование с помощью вертикальных линий
			pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200);
			
		
	

		
		//pDC->LineTo(i,(buffer[i+105]-128)*cp.y/200); // рисование с помощью соединени€ точек
		Sleep(0);
	}
	


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
