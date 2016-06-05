#pragma once
#define GNONE_ID	0	// 0은 ID가 없음을 의미한다.
#define GFIRST_ID	1	// 첫번째 ID는 1
/**
	@brief
		- ID를 관리한다.
*/
class G_EXT_CLASS CGIDManager
{
private:
	GID m_CurrentID;

public:
	void InitCurrentID();
	GID GetCurrentID();

public:
	CGIDManager();
	~CGIDManager();
};

