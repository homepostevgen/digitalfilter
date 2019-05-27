// WaveDoc.cpp : implementation of the CWaveDoc class
//

#include "stdafx.h"
#include "Wave.h"

#include "WaveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaveDoc

IMPLEMENT_DYNCREATE(CWaveDoc, CDocument)

BEGIN_MESSAGE_MAP(CWaveDoc, CDocument)
	//{{AFX_MSG_MAP(CWaveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWaveDoc construction/destruction

CWaveDoc::CWaveDoc()
{
	// TODO: add one-time construction code here

}

CWaveDoc::~CWaveDoc()
{
}

BOOL CWaveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWaveDoc serialization

void CWaveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWaveDoc diagnostics

#ifdef _DEBUG
void CWaveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWaveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWaveDoc commands
