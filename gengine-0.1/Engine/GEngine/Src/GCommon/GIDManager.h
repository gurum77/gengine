#pragma once
#define GNONE_ID	0	// 0�� ID�� ������ �ǹ��Ѵ�.
#define GFIRST_ID	1	// ù��° ID�� 1
/**
	@brief
		- ID�� �����Ѵ�.
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

