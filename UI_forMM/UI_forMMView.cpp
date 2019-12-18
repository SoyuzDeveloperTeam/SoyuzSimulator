
// UI_forMMView.cpp: реализация класса CUIforMMView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "UI_forMM.h"
#endif

#include "UI_forMMDoc.h"
#include "UI_forMMView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUIforMMView

IMPLEMENT_DYNCREATE(CUIforMMView, CView)

BEGIN_MESSAGE_MAP(CUIforMMView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CUIforMMView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CUIforMMView

CUIforMMView::CUIforMMView() noexcept
{
	// TODO: добавьте код создания

}

CUIforMMView::~CUIforMMView()
{
}

BOOL CUIforMMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CUIforMMView

void CUIforMMView::OnDraw(CDC* /*pDC*/)
{
	CUIforMMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CUIforMMView


void CUIforMMView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CUIforMMView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CUIforMMView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CUIforMMView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CUIforMMView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUIforMMView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CUIforMMView

#ifdef _DEBUG
void CUIforMMView::AssertValid() const
{
	CView::AssertValid();
}

void CUIforMMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUIforMMDoc* CUIforMMView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUIforMMDoc)));
	return (CUIforMMDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CUIforMMView
