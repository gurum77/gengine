
// GLauncherDoc.h : CGLauncherDoc Ŭ������ �������̽�
//


#pragma once

class CDlgCommandBar;


class CGLauncherDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CGLauncherDoc();
	DECLARE_DYNCREATE(CGLauncherDoc)

// Ư���Դϴ�.
public:
	CG3DDB *m_pG3DB;
	CG3DDB *m_pG3DBPreview;
	CG3DDB *m_pG3DBTemp;
	CGDCDirectX11 *m_pGDC;

	

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CGLauncherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CAtlString& value);
#endif // SHARED_HANDLERS
public:
};
