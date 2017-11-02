#ifndef TCPIPLISTENER_H
#define  TCPIPLISTENER_H

// #include "../IRP1_H/BaseMessage.h"
// #include "../IRP1_H/Messages.h"
// #include "ICommunication.h"
// #include "CommunicationFactory.h"
#include <Winsock2.h>
#include "ICommunication.h"
class TcpIpListener;
#include "Reader.h"

//�ص���д��������DealTypeΪ��д���������ͣ�1������������д����2ΪҪɾ���Ķ�д��
typedef void (CALLBACK *LPCallBackReader)(Reader *pReader,int DealType); //������д���Ļص�����ָ��

class TcpIpListener : public ICommunication
{

public:
	TcpIpListener();
	virtual bool Open(int Port,CString protocol);
	virtual bool close(HANDLE hnd);
	virtual int recvData(HANDLE hnd, char *buf,int bufSize);
	virtual bool wirteData(HANDLE hnd, char *buf,int bufSize);
	
	LPCallBackReader lpCallBackReader;
	virtual void SetCallBackReader(LPCallBackReader lpCallBackFun);
	static DWORD WINAPI ConnectThread(LPVOID lpParameter);
	static DWORD WINAPI DealExceptionThread(LPVOID lpParameter);
//	static void DealNetException(HANDLE hnd);

	CString m_ReaderIp; //������������Ӻ�Ķ�д��IP      add by hanyejun
	int m_ReaderPort;   //���汣����������Ӻ�Ķ�д���˿�
	HANDLE m_hComSock;  //�������������ʱ�������Ӻ󷵻�����ͨ��socket

	unsigned int iSerSockHandle; //����������򿪡��󶨲�������socket handle
	int m_LocalPort;             //������������صļ���port
protected:
	
private:
};


struct ServerInfo 
{
	TcpIpListener *lpListener;
	unsigned int iSocketHandle;
	CString Protocol;
	int Port;
};



// #define  SIO_RCVALL  IOC_IN | IOC_VENDOR | 1
// struct tcp_keepalive 
// {
//     u_long  onoff;
//     u_long  keepalivetime;
//     u_long  keepaliveinterval;
// };


#endif
