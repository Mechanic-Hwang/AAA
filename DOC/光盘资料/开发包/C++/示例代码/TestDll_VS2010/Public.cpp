#include "stdafx.h"
#include "Public.h"

//OutPut�����ִ�������ʾ������ΪCString�ͣ���TRACE�����ϼ���ʱ����ʾ;
void Debug_TRACE(CString strInBuf)
{
	CString strBuf;
	unsigned long time = GetTickCount();

	strBuf.Format("%d <====> ",time);
	strBuf += strInBuf;
	strBuf += "\n";
	TRACE(strBuf);
}
