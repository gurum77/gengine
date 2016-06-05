#pragma once
#pragma warning(disable:4251)
#include "atlcoll.h"

/**
	@brief
		- GArray 초기화
*/
template<class T>
void GArrayInit(void *pDest, T*)
{
	CAtlArray<T*> *p = (CAtlArray<T*>*)pDest;
	if (p->GetCount() == 0)
		return;

	for (int ix = 0; ix < (int)p->GetCount(); ++ix)
	{
		delete (T*)p->GetAt(ix);
	}
	p->RemoveAll();
}

/**
	@brief
		- GArray copy
*/
template <class T>
INT32 GArrayCopy(void* pDest, void* pSrc, T*)
{
	CAtlArray <T*> *pArrSrc = (CAtlArray <T*> *) pSrc;
	CAtlArray <T*> *pArrDesc = (CAtlArray <T*> *) pDest;

	INT32 iCreate = (INT32)(pArrSrc->GetCount() - pArrDesc->GetCount());
	INT32 iSize = (INT32)pArrSrc->GetCount();
	INT32 n;
	for (n = 0; n < iCreate; n++)
	{
		T*pParent = new T;
		pArrDesc->Add(pParent);
	}
	for (n = 0; n > iCreate; n--)
	{
		delete pArrDesc->GetAt(pArrDesc->GetCount() - 1);
		pArrDesc->RemoveAt(pArrDesc->GetCount() - 1);
	}

	for (n = 0; n < iSize; n++)
	{
		T* pSrc = (T*)pArrSrc->GetAt(n);
		T* pDes = (T*)pArrDesc->GetAt(n);
		*pDes = *pSrc;
	}
	return iSize;
}

/**
	@brief
		- GList 초기화
*/
template<class T>
void GListInit(void *pDest, T*)
{
	CAtlList<T*> *p	= (CAtlList<T*>*)pDest;
	POSITION pos	= p->GetHeadPosition();

	T *pData = NULL;
	while (pos != NULL)
	{
		pData = (T*)p->GetNext(pos);
		delete pData;
	}
	
	p->RemoveAll();
}
