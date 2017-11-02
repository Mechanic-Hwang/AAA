#ifndef _READER_H
#define  _READER_H

#include "../IRP1_H/BaseMessage.h"
#include "../IRP1_H/Messages.h"
#include "ICommunication.h"
#include "CommunicationFactory.h"
class Reader;
#include "../Communication_H/TcpIpListener.h"
class Reader
{
	public:

		Reader();
		Reader(CString readerName);
		Reader(CString readerName, CString protocolVersion, CString portType, CString connStr);
		virtual bool connect();
		virtual bool disconnect();
		virtual bool send(IMessage *msg);
		bool ParaeXmlReadInfo(CString FilePath,CString ReaderName); //���ݴ������Ķ�д�����ƣ�ȥXML�����ļ�������Ӧ������add by hanyejun

		
		//�ص�����....������
		//BaseMessage *m_message;
		//BaseMessage * create_message();
		HANDLE hand;
		IMessage * m_message;
		virtual IMessage * create_message();
		
		void (*onMessageEvent)(IMessageNotification *msg,void *context);
		virtual void setCallBack( void (*fun)(IMessageNotification *,void *),void *m_p_reader_context);
		void *m_reader_context;
		
		bool			IsConnected; //= false;
        CString			ModelNumber; //= "unknown";
        CString			ReaderName; //= "Reader1";
        CString			ReaderGroup; //= "Group1";
		CString			ReaderEnable; //= "Enable";//��д���Ƿ����� add by hanyejun
		CString			PortType;// = "RS232";
		CString			ProtocolVersion;// = "IRP1_H";
		CString			connStr;
		CString			UCfgProtocolVersion;	//�����û�ѡ���Э��汾 add by hanyejun
		CString			UCfgReaderType;			//�����û�ѡ��Ķ�д������ add by hanyejun
		CString			UCfgReadMemoryBank;		//��ȡ��ǩ���� 
		CString			UCfgAntenna;			//���ߺ�
		CString			UCfgIsLoop;				//�Ƿ�ѭ����ȡ
		CString		    UCfgTagNum;				//Ԥ����ǩ��
		CString			UCfgStopType;			//��д��ֹͣ����
		CString			UCfgReadTime;			//����ǩʱ��
		CString			UCfgStopTime;			//ֹͣ����ǩǰ��ͣ��ʱ��

		static int		CriSecNum; //���浱ǰ���ӵĶ�д������  add by hanyejun
        BOOL			isExistReaderConfig;// = true;
		ICommunication *pCon;
		TcpIpListener  *pListener; //�ڶ�д�������ӷ������������� hanyejun
	protected:
		
	private:
		

};


#endif