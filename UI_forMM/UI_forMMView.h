
// UI_forMMView.h: интерфейс класса CUIforMMView
//

#pragma once


class CUIforMMView : public CView
{
protected: // создать только из сериализации
	CUIforMMView() noexcept;
	DECLARE_DYNCREATE(CUIforMMView)

// Атрибуты
public:
	CUIforMMDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CUIforMMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в UI_forMMView.cpp
inline CUIforMMDoc* CUIforMMView::GetDocument() const
   { return reinterpret_cast<CUIforMMDoc*>(m_pDocument); }
#endif

