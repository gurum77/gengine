#pragma once
/**
	@brief
		- timer
*/
class G_EXT_CLASS CGTimer
{
public:
	static void Start();
	static void End(const CAtlString &strHeader=GNOTRANS(""));

	static LARGE_INTEGER m_swFreq;
	static LARGE_INTEGER m_swStart;
	static LARGE_INTEGER m_swEnd;
	
public:
	CGTimer();
	~CGTimer();
};

