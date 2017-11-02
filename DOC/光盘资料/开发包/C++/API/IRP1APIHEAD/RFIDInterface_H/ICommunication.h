
#ifndef  _I_COMMUNICATION_H_ 
#define  _I_COMMUNICATION_H_
#include <queue>
#include <list>
#include "EnumClass.h"
#include <afxmt.h>
#include "IMessage.h"
#include "Log.h"
class  ICommunication
{
	public:
		ICommunication();
		~ICommunication();
		virtual bool Open(HANDLE &hnd);
		virtual bool close(HANDLE hnd);
		virtual int recvData(HANDLE hnd, char *buf,int bufSize);
		virtual bool wirteData(HANDLE hnd, char *buf,int bufSize);
		
		static DWORD WINAPI revDataThread(LPVOID pParma);
		static DWORD WINAPI DealStoreData(LPVOID pParma);
		
		void Push_Queue(char *buf,int length);
		BOOL Pop_Queue(MSG_NET &msg_net);

		void (*onMessageEventICom)(IMessageNotification *msg,void *context);
		void setCallBackICom( void (*funICom)(IMessageNotification *,void *),void *context);
		void *m_context;

		bool Send(IMessage *msg, int timeout);

		void StartThread();
		int OutTransform(char *out, char *in, int size);//�������м�֡ͷ0x55

		IMessage *m_p_msg;
		IMessageNotification *m_p_msg_notication;

		RFIDPort PortTypeBak;//���ݵ�ǰ�ĵ�ͨ�����ͣ����ڴ��� hanyejun
		//tcp
		CString strHostNameIP; //��������IP;        (Ӧ���Ƕ�д����IP hanyejun)
		int ServerPort;        // �������˿�        (Ӧ���Ƕ�д����port)
		int ConnectOutTime; //���ӳ�ʱʱ��
		int LocalPort;     //���ض˿�

		//com
		CString strSerialNum;//���ں�
		unsigned long iBaudRate; //������
		//usb
		HANDLE m_hCom;
		bool b_thread_state;
		
		bool b_rev_thread_state;
		bool b_deal_thread_state;
		CEvent m_event_rec,m_event_deal;
		CEvent event_msg_time_out;
		CMutex m_clsMutex;
		CCriticalSection m_cs;

		HANDLE hevent;

		std::queue<MSG_NET> queue_buf;
		ICommunication *m_pCon;


		bool isGetOneTag;
		bool isReadTag;
		bool isDonReadTag;
	protected:

	private:


};

	
#endif