
// GLauncherView.h : CGLauncherView 클래스의 인터페이스
//

#pragma once

#define TIMER_ID_MOVE_TEXTURE	100
#define TIMER_INTERVAL_MOVE_TEXTURE	200

class CGLauncherView : public CView
{
protected: // serialization에서만 만들어집니다.
	void DrawPolyline2D();
	void DrawLine2D();
	void DrawPoint2D();
	const double GetHeight(const double &dX, const double &dY, const double &dMaxX, const double &dMaxY) const;

	CG3DView *m_pG3DView;
	CG3DActionManager *m_pActionManager;
	CDlgCommandBar *m_pDlgCommandBar;
	CGLauncherView();
	DECLARE_DYNCREATE(CGLauncherView)

// 특성입니다.
public:
	CGLauncherDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CGLauncherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnControlSpaceview();
	afx_msg void OnDrawGrid();
	afx_msg void OnDrawTriangle();
	afx_msg void OnDrawCylinder();
	afx_msg void OnDrawBox();
	afx_msg void OnDrawSphere();
	afx_msg void OnDrawCircle();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnEditDeleteAll();
	afx_msg void OnEditDelete100objects();
	afx_msg void OnEditDeletealleach();
	afx_msg void OnEditDelete100objectseach();
	afx_msg void OnActionDrawline();
	afx_msg void OnActionEndaction();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSelectSelect100objects();
	afx_msg void OnSelectSelect100objectseach();
	afx_msg void OnSelectUnselectall();
	afx_msg void OnActionSelect();
	afx_msg void OnDrawPolyline3d();
	afx_msg void OnSelectDynamichighlight();
	afx_msg void OnUpdateSelectDynamichighlight(CCmdUI *pCmdUI);
	afx_msg void OnActionDrawcircle();
	afx_msg void OnDrawCompoundobject();
	afx_msg void OnEditMove();
	afx_msg void OnActionCopy();
	afx_msg void OnActionRotate2d();
	afx_msg void OnActionScale();
	afx_msg void OnDxfImport();
	afx_msg void OnDrawText();
	afx_msg void OnDrawFace();
	afx_msg void OnViewCommandbar();
	afx_msg void OnAlignmentCreatehorizontalalignment();
	afx_msg void OnDrawProxyOlympicFlag();
	afx_msg void OnDrawHorizontalalignment();
	afx_msg void OnAlignmentCreateverticalalignment();
	afx_msg void OnAlignmentInputdesignvip();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEditMovetexture();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSettingPerspective();
	afx_msg void OnUpdateSettingPerspective(CCmdUI *pCmdUI);
	afx_msg void OnSettingFog();
	afx_msg void OnUpdateSettingFog(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // GLauncherView.cpp의 디버그 버전
inline CGLauncherDoc* CGLauncherView::GetDocument() const
   { return reinterpret_cast<CGLauncherDoc*>(m_pDocument); }
#endif

