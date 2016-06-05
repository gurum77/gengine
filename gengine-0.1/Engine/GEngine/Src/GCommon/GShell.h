#pragma once

#define WUNKNOWN	0

#define W9XFIRST	1
#define W95			1
#define W95SP1		2
#define W95OSR2		3
#define W98			4
#define W98SP1		5
#define W98SE		6
#define WME			7
#define W9XLAST		99

#define WNTFIRST	101
#define WNT351		101
#define WNT4		102
#define W2K			103
#define WXP			104
#define WVISTA		105
#define W7			106
#define WNTLAST		199

#define WCEFIRST	201
#define WCE			201
#define WCELAST		299

#define WUNKNOWNSTR	_T("unknown Windows version")

#define W95STR		_T("Windows 95")
#define W95SP1STR	_T("Windows 95 SP1")
#define W95OSR2STR	_T("Windows 95 OSR2")
#define W98STR		_T("Windows 98")
#define W98SP1STR	_T("Windows 98 SP1")
#define W98SESTR	_T("Windows 98 SE")
#define WMESTR		_T("Windows ME")

#define WNT351STR	_T("Windows NT 3.51")
#define WNT4STR		_T("Windows NT 4")
#define W2KSTR		_T("Windows 2000")
#define WXPSTR		_T("Windows XP")
#define WVISTASTR		_T("Windows Vista")
#define W7STR		_T("Windows 7")

#define WCESTR		_T("Windows CE")

/**
	@brief
		- shell 명령 관련 기능 모음
*/
class G_EXT_CLASS CGShell
{
public:
	/**
		@brief
			- 프로그램의 실행경로를 가져온다.
	*/
	static CAtlString GetExtPath();
	static CAtlString NewGuid();
#if _MSC_VER <= 1600	// vs2010까지 지원되는 함수
	static BOOL GetWinVer(LPTSTR lpszVersion, int nVersionSize, int *pnVersion);
#endif
	static LONG GetNextNameValue(HKEY key, LPCTSTR pszSubkey, LPTSTR pszName, LPTSTR pszData);
public:
	CGShell();
	~CGShell();
};

