#ifndef _MESSAGES_H
#define  _MESSAGES_H

#include "BaseMessage.h"
#include "BaseMessageNotification.h"
#include <list>


class RXD_EPC_6C : public BaseMessageNotification
{
public:
	RXD_EPC_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagAntenna;
};

class RXD_ID_6B : public BaseMessageNotification
{
public:
	RXD_ID_6B(); 
	virtual unsigned char GetAntenna();
	virtual unsigned char GetTagType();
	virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
	virtual bool GetRSSI(unsigned char *pRSSI,unsigned char RSSILen);
	unsigned char tagID[256];
	unsigned char tagIDLen;
	unsigned char tagAntenna;
	unsigned char ucTagType;
	unsigned char RSSI[256];
	unsigned char RSSILen;
};

class RXD_TID_6C  : public BaseMessageNotification
{
public:	
	RXD_TID_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
};

class RXD_EPC_TID_UserData_6C : public BaseMessageNotification
{
public:
	RXD_EPC_TID_UserData_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
};

class RXD_EPC_TID_UserData_6C_2 : public BaseMessageNotification
{
public:
	RXD_EPC_TID_UserData_6C_2();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
};


class RXD_EPC_TID_UserData_Received_6C  : public BaseMessageNotification
{
public:
	RXD_EPC_TID_UserData_Received_6C ();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	virtual bool GetReserved(unsigned char *pReserved,unsigned char &ReservedLen);
	virtual bool GetRSSI(unsigned char *pRSSI,unsigned char &RSSILen);
	virtual bool GetReadTime(unsigned char *pReadTime,unsigned char &ReadTimeLen);

	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
	unsigned char Reserved[256];
	unsigned char ReservedLen;
	unsigned char RSSI[256];
	unsigned char RSSILen;
	unsigned char ReadTime[256];
	unsigned char ReadTimeLen;

};


class RXD_ID_UserData_6B : public BaseMessageNotification
{
public:	
	RXD_ID_UserData_6B();
	virtual unsigned char GetAntenna();
	virtual unsigned char GetTagType();
	virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
	virtual bool GetUserData(unsigned char *pUserData,unsigned char &userdataLen);

	unsigned char tagID[256];
	unsigned char tagIDLen;
	unsigned char tagAntenna;	

	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
	unsigned char ucTagType;

};
class RXD_ID_UserData_6B_2 : public BaseMessageNotification
{
public:
	RXD_ID_UserData_6B_2();
	virtual unsigned char GetAntenna();
	virtual unsigned char GetTagType();
	virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
	virtual bool GetUserData(unsigned char *pUserData,unsigned char &userdataLen);
	virtual bool GetRSSI(unsigned char *pRSSI,unsigned char &RSSILen);
	virtual bool GetReadTime(unsigned char *pReadTime,unsigned char &ReadTimeLen);

	unsigned char tagID[256];
	unsigned char tagIDLen;
	unsigned char tagAntenna;	

	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
	unsigned char ucTagTyp;

	unsigned char RSSI[256];
	unsigned char RSSILen;
	unsigned char ReadTime[256];
	unsigned char ReadTimeLen;
	unsigned char ucTagType;

};
class RXD_EPC_PC_6C : public BaseMessageNotification
{
public:
	RXD_EPC_PC_6C();
	virtual unsigned char GetAntenna();
	virtual BOOL GetPC(unsigned char *pc, unsigned char &pcLen);
	virtual BOOL GetEPC(unsigned char *epc,unsigned char &epcLen);
	virtual BOOL GetRSSI(unsigned char *rssi,unsigned char &rssiLen);

	unsigned char tagPC[256];
	unsigned char tagPCLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagRSSI[256];
	unsigned char tagRSSILen;

};


 class PowerOn_800 : public BaseMessage
 {	 

	 /// <param name="antenna">���ߺ�/param>
 public:
	 PowerOn_800(unsigned char antenna);
	
};


 class ReadTag : public BaseMessage
 {
	public:
		ReadMemoryBank rmb;
        int readTime;
        int stopTime;
        CString stopType;
        volatile bool isStop;
		
		//����ɨ������
		unsigned char Antenna;  //���ߺ�
		unsigned char q;        //qֵ
		unsigned char isLoop;    //�Ƿ�ѭ��
		unsigned char tidLen;     //tid����
		unsigned char userdataPtr;  //�û�����������ַ
		unsigned char userdataLen;   //�û����ݳ���

		virtual void SetAntenna(unsigned char ucAntenna);
		virtual void SetQ (unsigned char ucQ);
		virtual void SetIsLoop (unsigned char ucIsLoop);
		virtual	void SetTidLen (unsigned char ucTidLen);
		virtual	void SetUserdataPtr_6C(unsigned int ucUserdataPtr_6C);
		virtual	void SetUserDataLen_6C (unsigned char ucUserDataLen_6C);
		virtual	void SetUserdataPtr_6B (unsigned char ucUserDataLen_6C);
		virtual	void SetUserDataLen_6B (unsigned char ucUserDataLen_6B);
		virtual	void SetReservedLen (unsigned char ucReservedLen);
		virtual	void SetAccessPwd (unsigned char* ucAccessPwd,unsigned char ucAccessPwdLen);
		virtual	void SetReadTimes_6C(unsigned char ucReadTimes_6C);
		virtual	void SetReadTimes_6B(unsigned char ucReadTimes_6B);

		ReadTag();
		ReadTag(ReadMemoryBank rmb);        
        ReadTag(ReadMemoryBank rmb, int readTime, int stopTime, CString stopType);
        ReadTag(unsigned char tidLen, unsigned char userdataPtr, unsigned char userdataLen);
		ReadTag(unsigned char tidLen, unsigned char userdataPtr, unsigned char userdataLen, int readTime, int stopTime);
		ReadTag(ReadMemoryBank rmb,CString stopType,BOOL isGetOneTag);
		
		RXD_EPC_6C *m_p_RXD_EPC_6C;
		RXD_ID_6B  *m_p_RXD_ID_6B;
		RXD_TID_6C *m_p_RXD_TID_6C;
		RXD_EPC_TID_UserData_6C *m_p_RXD_EPC_TID_UserData_6C;
		RXD_EPC_TID_UserData_6C_2 *m_p_RXD_EPC_TID_UserData_6C_2;
		RXD_EPC_TID_UserData_Received_6C *m_p_RXD_EPC_TID_UserData_Received_6C;
		RXD_ID_UserData_6B *m_p_RXD_ID_UserData_6B;
		RXD_ID_UserData_6B_2 *m_p_RXD_ID_UserData_6B_2;
		RXD_EPC_PC_6C *m_p_RXD_EPC_PC_6C;
		
		std::list<RXD_EPC_6C *>m_RXD_EPC_6C_list;
		std::list<RXD_ID_6B *>m_RXD_ID_6B_list;
		std::list<RXD_TID_6C *>m_RXD_TID_6C_list;
		std::list<RXD_EPC_TID_UserData_6C *>m_RXD_EPC_TID_UserData_6C_list;
		std::list<RXD_EPC_TID_UserData_6C_2 *>m_RXD_EPC_TID_UserData_6C_2_list;
		std::list<RXD_EPC_TID_UserData_Received_6C *>m_RXD_EPC_TID_UserData_Received_6C_list;
		std::list<RXD_ID_UserData_6B *>m_RXD_ID_UserData_6B_list;
		std::list<RXD_ID_UserData_6B_2 *>m_RXD_ID_UserData_6B_2_list;
		std::list<RXD_EPC_PC_6C *>m_RXD_EPC_PC_6C_list;
	
	    
		virtual RXD_EPC_6C * List_RXD_EPC_6C(unsigned int &len);
		virtual RXD_ID_6B  *List_RXD_ID_6B(unsigned int &len);
		virtual RXD_TID_6C *List_RXD_TID_6C(unsigned int &len);
		virtual RXD_EPC_TID_UserData_6C * List_RXD_EPC_TID_UserData_6C(unsigned int &len);
		virtual RXD_EPC_TID_UserData_6C_2 * List_RXD_EPC_TID_UserData_6C_2(unsigned int &len);
		virtual RXD_EPC_TID_UserData_Received_6C * List_RXD_EPC_TID_UserData_Received_6C(unsigned int &len);
		virtual RXD_ID_UserData_6B * List_RXD_ID_UserData_6B(unsigned int &len);
		virtual RXD_ID_UserData_6B_2 * List_RXD_ID_UserData_6B_2(unsigned int &len);
		virtual RXD_EPC_PC_6C * List_RXD_EPC_PC_6C(unsigned int &len);

		void addList(unsigned char type,unsigned char *buf,unsigned char bufLen);
		virtual void releaseMen();

		virtual void TrigerOnExecuted(void *obj);
	private:
		bool bTrigerOnExecuted;
		void setData(ReadMemoryBank rmb);

		void Clear_List_RXD_EPC_6C();
		void Clear_List_RXD_ID_6B();
		void Clear_List_RXD_TID_6C();
		void Clear_List_RXD_EPC_TID_UserData_6C();
		void Clear_List_RXD_EPC_TID_UserData_6C_2();
		void Clear_List_RXD_EPC_TID_UserData_Received_6C();
		void Clear_List_RXD_ID_UserData_6B();
		void Clear_List_RXD_ID_UserData_6B_2();
		void Clear_List_RXD_EPC_PC_6C();
 };


 /*class PowerOff_500 :  private BaseMessage
 {
	public: 
		 PowerOff_500();
		
  };*/


class TagOperationQuery_6C : public  BaseMessage
{	
	 public:
	TagOperationQuery_6C(unsigned char parameter);
	virtual BOOL GetQueryData(char *data,unsigned char &dataLen);
};


/// ���ñ�ǩ��������ָ��
class TagOperationConfig_6C : public BaseMessage
{	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="parameter">���ñ�ǩ��������ָ���������</param>
	/// <param name="pData">��������</param>
	///<param nanem="dataLen">�������ݳ���</param> 
	 public:
		TagOperationConfig_6C(unsigned char parameter, unsigned char *pData,unsigned char dataLen);
};


/// <summary>
/// IMPINJ QTָ��
/// </summary>
class QT_6C : public BaseMessage
{

	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="antenna">���߶˿�</param>
	/// <param name="pwd">����(4�ֽ�)</param>
	/// <param name="opType">�������ͣ�R/W��:0����ѯ��ǩ��ԭ��QT����;1�����ñ�ǩ��QT����</param>
	/// <param name="persistent">���ó־��ԣ�persistent����0�����ý��ڱ�ǩ�����ϵ��������Ч;1�����ÿ�һֱ����</param>
	/// <param name="payload">���ò�����payload����
	/// ��һ�ֽڳ���λ����ģʽ�������±��ڶ��ֽڱ���
	/// ����	7	6	5	4	3	2	1	0
	/// ����	QT_SR	QT_MEM	����	����	����	����	���	����
	
	/// QT_SR��1����ǩ�ڿ�״̬�Ͱ�ȫ̬ʱ�������Ӧ���루����ڽ�������Ӧ��
	///         0����ǩ��������Ӧ����
	/// QT_MEM 1����ǩ�洢��ӳ��Ϊ����ģʽ
	/// 		 0:  ��ǩ�洢��ӳ��Ϊ˽��ģʽ</param>
 public:
	QT_6C(unsigned char antenna, 
			unsigned char *accessPwd,
			unsigned char accessPwdLen, 
			unsigned char opType, 
			unsigned char persistent,
			unsigned char *payload,
			unsigned char payloadLen);
	
	virtual unsigned char GetAntenna();
	virtual bool GetPayload(unsigned char *data, unsigned char &dataLen);
	
};


 /// ���TIDʱEPC��Գ���
class FastReadTIDConfig_EpcLength : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">��Ϣ����</param>
	/// <param name="infoParam">��Ϣ����</param>
	 public:
	FastReadTIDConfig_EpcLength(unsigned char infoType, unsigned char *infoParam,unsigned char infoParamLen);
	virtual bool GetQueryData(unsigned char *pData,unsigned char &dataLen);	

};

/// ���TID����
class FastReadTIDConfig_6C : public BaseMessage
{
	/// </summary>
	/// <param name="infoType">��Ϣ����</param>
    /// <param name="infoParam">��Ϣ����</param>
	 public:
	FastReadTIDConfig_6C(unsigned char infoType, unsigned char infoParam);
	virtual bool GetQueryData(unsigned char *pData,unsigned char &dataLen);	
};

/// <summary>
/// ���䳤TID��������/��ѯ
/// </summary>
 class ReadUnfixedTidConfig_6C : public BaseMessage
{
	/// </summary>       
	/// <param name="infoType">��Ϣ���ͣ�0x00���ã�0x01��ѯ</param>
	/// <param name="infoParam">��Ϣ����:0x00�رն��䳤TID����,0x01�������䳤TID����</param>      
 public:
	 ReadUnfixedTidConfig_6C(unsigned char infoType, unsigned char infoParam);
	virtual bool GetQueryData(unsigned char *pData,unsigned char &dataLen);

};

/// �̶�TID��������/��ѯ
class FixedTidLengthConfig_6C : public BaseMessage
{
	/// <param name="infoType">��Ϣ���ͣ�0x00���ã�0x01��ѯ</param>
	/// <param name="infoParam">��Ϣ��������ȡ�̶�����TID���ָ����������0��</param>      
 public:
	FixedTidLengthConfig_6C(unsigned char infoType, unsigned char infoParam);
	virtual bool GetQueryData(unsigned char *pData,unsigned char &dataLen);
};


/// ����6C��������Ϣ��������/��ѯ
class ReadTagConfig_6C : public BaseMessage
{
	/// </summary>
	/// <param name="infoType">��Ϣ����:0Ϊ���ã�1Ϊ��ѯ</param>
	/// <param name="infoParam">��Ϣ����</param>
	/// ��Ϣ������
	/// ��1���ֽڶ�EPC���أ�0=����ȡEPC�룬1=��ȡEPC��
	/// ��2���ֽڶ�TID���أ�0=����ȡTID�룬1=��ȡTID��
	/// ��3���ֽڶ�TID����ֳ���
	/// ��4���ֽڶ�USR���ݿ��أ�0=����ȡUSR��1=��ȡUSR
	/// ��5���ֽڶ�USR���������ֳ���
     public:
	ReadTagConfig_6C(unsigned char infoType, unsigned char *infoParam,unsigned char infoParamLen);
	virtual unsigned char GetInfoType();
	virtual bool GetInfoParam(unsigned char *data,unsigned char &dataLen);

};


/// ��6B��ǩ��������Ϣ��������/��ѯ
class ReadTagConfig_6B : public BaseMessage
{
	/// <param name="infoType">��Ϣ����:0Ϊ���ã�1Ϊ��ѯ</param>
	/// <param name="infoParam">��Ϣ��������Ҫ��ȡ6B��ǩ���������ֽ���</param>
    public:
	ReadTagConfig_6B(unsigned char infoType, unsigned char infoParam);
	virtual unsigned char GetInfoType();
	virtual bool GetInfoParam(unsigned char *data,unsigned char &dataLen);

};

/// ID���ݹ���ָ��
class IDFilter_6B : public BaseMessage
{
	/// <param name="tagID">ID(8�ֽ�)</param>
	/// <param name="tagMask">ƥ�����(8�ֽ�)</param>
	 public:
	IDFilter_6B(unsigned char  *tagID, unsigned char tagIDLen,unsigned char *tagMask,unsigned char tagMaskLen);
	
};

/// EAS��־����ָ��
class EasConfig_6C : public BaseMessage
{
	/// <param name="antenna">���߶˿�</param>
	/// <param name="accessPwd">��������</param>
	/// <param name="flag">EAS��־����</param>
 public:
	EasConfig_6C(unsigned char antenna, unsigned char *accessPwd, unsigned char accessPwdLen, unsigned char flag);
	EasConfig_6C(unsigned char antenna, unsigned char* accessPwd,unsigned char accessPwdLen, unsigned char flag, unsigned char *tagID,unsigned char tagIDLen, MemoryBank tagIDType);

	virtual void TrigerOnExecuting(void *obj);

private:
	bool bTrigerOnExecuting;
	unsigned char  tagID[128];
	unsigned char tagIDType;
	unsigned char tagIDLen;


 };

/// EPCƥ�����ָ��
class EpcFilter_6C : public  BaseMessage
{
	/// <param name="opType">����</param>
	/// <param name="epcData">ƥ��EPC��</param>
	/// <param name="epcMask">Ҫƥ����������</param>
	 public:
	EpcFilter_6C(unsigned char  opType, unsigned char *epcData,unsigned char epcDataLen, unsigned char *epcMask,unsigned char epcMaskLen);

};

/// �ظ���ǩ��ʱ�����ָ��
class FilterByTime_6C : public BaseMessage
{	/// <param name="opType">����</param>
	/// <param name="time">ʱ��</param>
 public:
	FilterByTime_6C(unsigned char opType, unsigned char *time,unsigned char timeLen);
};

 /// EAS��ع�������ָ��
class EasAlarm_6C : public BaseMessage
{
	/// <param name="antenna">���߶˿�</param>
	/// <param name="easCfg">EAS�������</param>       
 public:
	EasAlarm_6C(unsigned char antenna, unsigned char easCfg);
	virtual unsigned char GetAntenna();
	virtual unsigned char GetAnswerType();
};	

/*
class RXD_EPC_6C : public BaseMessageNotification
{
 public:
	RXD_EPC_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagAntenna;
};

class RXD_ID_6B : public BaseMessageNotification
{
 public:
	RXD_ID_6B(); 
	virtual unsigned char GetAntenna();
	virtual unsigned char GetTagType();
	virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
	virtual bool GetRSSI(unsigned char *pRSSI,unsigned char RSSILen);
	unsigned char tagID[256];
	unsigned char tagIDLen;
	unsigned char tagAntenna;
	unsigned char ucTagType;
	unsigned char RSSI[256];
	unsigned char RSSILen;
};

class RXD_TID_6C  : public BaseMessageNotification
{
 public:	
	RXD_TID_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
};

class RXD_EPC_TID_UserData_6C : public BaseMessageNotification
{
 public:
	RXD_EPC_TID_UserData_6C();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
};

class RXD_EPC_TID_UserData_6C_2 : public BaseMessageNotification
{
public:
	RXD_EPC_TID_UserData_6C_2();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
};


class RXD_EPC_TID_UserData_Received_6C  : public BaseMessageNotification
{
 public:
	RXD_EPC_TID_UserData_Received_6C ();
	virtual unsigned char GetAntenna();
	virtual bool GetEPC(unsigned char *Epc,unsigned char &epcLen);
	virtual bool GetTID(unsigned char *TID,unsigned char &TIDLen);
	virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	virtual bool GetReserved(unsigned char *pReserved,unsigned char &ReservedLen);
	virtual bool GetRSSI(unsigned char *pRSSI,unsigned char &RSSILen);
	virtual bool GetReadTime(unsigned char *pReadTime,unsigned char &ReadTimeLen);

	unsigned char tagTID[256];
	unsigned char tagTIDLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
	unsigned char Reserved[256];
	unsigned char ReservedLen;
	unsigned char RSSI[256];
	unsigned char RSSILen;
	unsigned char ReadTime[256];
	unsigned char ReadTimeLen;

};


class RXD_ID_UserData_6B : public BaseMessageNotification
{
 public:	
	RXD_ID_UserData_6B();
	virtual unsigned char GetAntenna();
	virtual unsigned char GetTagType();
	virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
	virtual bool GetUserData(unsigned char *pUserData,unsigned char &userdataLen);
	
	unsigned char tagID[256];
	unsigned char tagIDLen;
	unsigned char tagAntenna;	

	unsigned char tagUserData[256];
	unsigned char tagUserDataLen;
	unsigned char ucTagType;

};
class RXD_ID_UserData_6B_2 : public BaseMessageNotification
{
	public:
		RXD_ID_UserData_6B_2();
		virtual unsigned char GetAntenna();
		virtual unsigned char GetTagType();
		virtual bool GetID(unsigned char *ID,unsigned char &IDLen);
		virtual bool GetUserData(unsigned char *pUserData,unsigned char &userdataLen);
		virtual bool GetRSSI(unsigned char *pRSSI,unsigned char &RSSILen);
		virtual bool GetReadTime(unsigned char *pReadTime,unsigned char &ReadTimeLen);

		unsigned char tagID[256];
		unsigned char tagIDLen;
		unsigned char tagAntenna;	

		unsigned char tagUserData[256];
		unsigned char tagUserDataLen;
		unsigned char ucTagTyp;

		unsigned char RSSI[256];
		unsigned char RSSILen;
		unsigned char ReadTime[256];
		unsigned char ReadTimeLen;
		unsigned char ucTagType;

};
class RXD_EPC_PC_6C : public BaseMessageNotification
{
 public:
	RXD_EPC_PC_6C();
	virtual unsigned char GetAntenna();
	virtual BOOL GetPC(unsigned char *pc, unsigned char &pcLen);
	virtual BOOL GetEPC(unsigned char *epc,unsigned char &epcLen);
	virtual BOOL GetRSSI(unsigned char *rssi,unsigned char &rssiLen);

	unsigned char tagPC[256];
	unsigned char tagPCLen;
	unsigned char tagAntenna;	
	unsigned char tagEpc[256];
	unsigned char tagEpcLen;
	unsigned char tagRSSI[256];
	unsigned char tagRSSILen;

};*/

 /// ��ǩѡ��ָ��
class SelectTag_6C : public BaseMessage
{
	/// <param name="memoryBank">ƥ��������</param>
	/// <param name="startAdd">ƥ��������ʼ��ַ(EVB��ʽ)</param>
	/// <param name="matchBitLength">ƥ�������</param>
    /// <param name="tagData">ƥ������</param>
public:
	SelectTag_6C();
	SelectTag_6C(unsigned char memoryBank, unsigned char ptr, unsigned char matchBitLength, unsigned char *tagData,unsigned char tagDataLen);
	unsigned char select(void * reader, unsigned char *tagID,unsigned char tagIDLen, unsigned char tagIDType);

};

/// <summary>
/// ͨ��д��ǩָ��
/// </summary>
class WriteTag_6C : public  BaseMessage
{
	/// <param name="antenna">���߶˿�</param>
	/// <param name="accessPwd">����(4�ֽ�)</param>
	/// <param name="memoryBank">����Bank</param>
	/// <param name="ptr">�׵�ַ</param>
	/// <param name="length">д�����ݳ���</param>
	/// <param name="data">д������</param>
 public:
	WriteTag_6C(unsigned char antenna, 
				unsigned char *accessPwd,
				unsigned char accessPwdLen, 
				unsigned char memoryBank, 
				unsigned char ptr, 
				unsigned char length, 
				unsigned char *data,
				unsigned char dataLen);

	WriteTag_6C(unsigned char antenna, 
		unsigned char *accessPwd,
		unsigned char accessPwdLen, 
		unsigned char memoryBank, 
		unsigned char ptr, 
		unsigned char length, 
		unsigned char *data,
		unsigned char dataLen,
		unsigned char *tagID,
		unsigned char tagIDLen,
		MemoryBank tagIDType);

	virtual void TrigerOnExecuting(void *obj);

private:
	bool bTrigerOnExecuting;
	unsigned char  tagID[128];
	unsigned char tagIDType;
	unsigned char tagIDLen;
               
};


/// <summary>
/// дEPC����ָ��
/// </summary>
 class WriteEpc : public BaseMessage
{
	//Byte[] tagID;
	//Byte tagIDType;	
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="antenna">���߶˿�</param>
	/// <param name="pwd">��ǩ��������</param>        
	/// <param name="epcData">д���ǩEPC����</param>
   public: 
	WriteEpc(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char *epcData,unsigned char epcDataLen);
	WriteEpc(unsigned char  antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char *epcData,
			unsigned char epcDataLen, unsigned char *tagID,unsigned char tagIDLen, unsigned char tagIDType);

	virtual void TrigerOnExecuting(void *obj);
	private:
		bool bTrigerOnExecuting;
		unsigned char  tagID[128];
		unsigned char tagIDType;
		unsigned char tagIDLen;
 };


 /// <summary>
 /// ���û�������ָ��
 /// </summary>
  class ReadUserData_6C : public BaseMessage
 {
	 
	 public: 
		unsigned char antenna;
		unsigned char ptr;
		unsigned char UserDatalenBak; //���浱ǰҪ���ȡ�û����ݵĳ���
		// List<Byte> udBuff = new List<byte>();
		int maxReadLen;//�������д��word��
	 
		unsigned char  tagID[128];
		unsigned char tagIDLen;//��ǩID����
		unsigned  char tagIDType;
	 /// <param name="antenna">���߶˿�</param>        
	 /// <param name="ptr">��ǩ�������׵�ַ��EVB��ʽ��</param>
	 /// <param name="length">��ǩ���ݶ�ȡ����</param>
		ReadUserData_6C(unsigned char  antenna, unsigned char ptr, unsigned char  length);
		ReadUserData_6C(unsigned char antenna, unsigned char ptr, unsigned char length, unsigned char *tagID, unsigned char tagIDLen,unsigned char  tagIDType);
		virtual void TrigerOnExecuting(void *obj);	
		virtual unsigned char GetAntenna();
		virtual bool GetUserData(unsigned char *usderData,unsigned char &userDataLen);
	 
	 private:
		 bool bTrigerOnExecuting;
		 char ReadUserDatabuf[512];
		 unsigned char bufLen;
  };


  /// <summary>
  /// д�û�������ָ��
  /// </summary>
  class WriteUserData_6C : public  BaseMessage
  {
  public:
	  unsigned char antenna;
	  unsigned char ptr;
	  unsigned char pwd[4];
	  unsigned char userData[512];
	  unsigned char userDataLenBak; //����д�û����ݵĳ��� add by hanyj
	  int maxWriteLen;//�������д��word��
	  unsigned char tagID[128];
	  unsigned char tagIDLen;
	  unsigned char tagIDType;
	
	  /// <param name="antenna">���߶˿�</param>
	  /// <param name="pwd">��ǩ��������</param>
	  /// <param name="ptr">������д���׵�ַ</param>
	  /// <param name="userData">д��ǩ����������</param>
      WriteUserData_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char ptr, unsigned char *userData,unsigned char userDataLen);
	  WriteUserData_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char ptr, unsigned char *userData,unsigned char userDataLen,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
      virtual void TrigerOnExecuting(void *obj);	
  private: 
	  void setData(unsigned char antenna, unsigned char *pwd, unsigned char ptr, unsigned char *userData,unsigned char userDataLen);
	  bool bTrigerOnExecuting;
	


  };


 class BlockWrite_6C : public BaseMessage
  {
	 public:
		unsigned char tagID[128];
		unsigned char tagIDLen;
		unsigned char tagIDType;
	  /// <param name="antenna">���߶˿�</param>
	  /// <param name="accessPwd">��ǩ��������</param>
	  /// <param name="memoryBank">������</param>
	  /// <param name="ptr">��ǩ�������׵�ַ��EVB��ʽ��</param>
	  /// <param name="dataLength">д����������</param>
	  /// <param name="data">д����������</param>
		BlockWrite_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char memoryBank, unsigned char ptr, unsigned char *data,unsigned char dataLen);
		BlockWrite_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char memoryBank, unsigned char ptr, unsigned char *data,unsigned char dataLen,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
		virtual void TrigerOnExecuting(void *obj);
	 private:
		 bool bTrigerOnExecuting;
		 void setData(unsigned char antenna, unsigned char *accessPwd, unsigned char memoryBank, unsigned char ptr, unsigned char *data,unsigned char dataLen);

  };


 /// <summary>
 /// ���Bank����ָ��
 /// </summary>
 class BlockErase_6C : public BaseMessage
 {
	public:	
		unsigned char tagID[128];
		unsigned char tagIDLen;
		unsigned char tagIDType;
	 /// <param name="antenna">���߶˿�</param>
	 /// <param name="accessPwd">��ǩ��������</param>
	 /// <param name="memoryBank">����Bank </param>
	 /// <param name="ptr">������ǩ�������׵�ַ��EVB��ʽ��</param>
	 /// <param name="dataLength">������ǩ����������</param>
        BlockErase_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char memoryBank, unsigned char ptr, unsigned char dataLength);
		BlockErase_6C(unsigned char antenna, unsigned char *accessPwd, unsigned char accessPwdLen,unsigned char memoryBank, unsigned char ptr, unsigned char dataLength,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
		virtual void TrigerOnExecuting(void *obj);
	private:
		bool bTrigerOnExecuting;
		void setData(unsigned char antenna, unsigned char *accessPwd, unsigned char memoryBank, unsigned char ptr, unsigned char dataLength);
 };


 /// <summary>
 /// ���÷�������ָ��
 /// </summary>
  class AccessPwdConfig_6C : public BaseMessage
 {
	public:	
		unsigned char tagID[128];
		unsigned char tagIDLen;
		unsigned char tagIDType;
	 /// <param name="antenna">���߶˿�</param>
	 /// <param name="oldPwd">ԭ��������</param>
	 /// <param name="newPwd">�·�������</param>
		AccessPwdConfig_6C(unsigned char antenna, unsigned char  *oldPwd,unsigned char oldPwdLen, unsigned char *newPwd,unsigned char newPwdLen);
		AccessPwdConfig_6C(unsigned char antenna, unsigned char  *oldPwd,unsigned char oldPwdLen, unsigned char *newPwd,unsigned char newPwdLen,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
		virtual void TrigerOnExecuting(void *obj);
	private:
		bool bTrigerOnExecuting;
		void setData(unsigned char antenna, unsigned char  *oldPwd, unsigned char *newPwd);

 };



 class KillPwdConfig_6C  : public BaseMessage
 {
	public:	
		unsigned char tagID[128];
		unsigned char tagIDLen;
		unsigned char tagIDType;
		/// <param name="antenna">���߶˿�</param>, 
		/// <param name="oldPwd">ԭ��������</param>
		/// <param name="newPwd">�·�������</param>
		KillPwdConfig_6C (unsigned char antenna, unsigned char  *accessPwd,unsigned char accessPwdLen, unsigned char *killPwd,unsigned char killPwdLen);
		KillPwdConfig_6C (unsigned char antenna, unsigned char  *accessPwd,unsigned char accessPwdLen, unsigned char *killPwd,unsigned char killPwdLen,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
		virtual void TrigerOnExecuting(void *obj);
	private:
		bool bTrigerOnExecuting;
		void setData(unsigned char antenna, unsigned char  *accessPwd, unsigned char *killPwd);
		
 };


  /// ��ǩ��״̬����ָ��
 class LockMemoryBank_6C : public  BaseMessage
 {
 public:	
	 unsigned char tagID[128];
	 unsigned char tagIDLen;
	unsigned char tagIDType;
	  /// <param name="antenna">���߶˿�</param>
	  /// <param name="accessPwd">��ǩ��������</param>
	  /// <param name="lockType">����������</param>
	  /// <param name="memoryBank">Bank���� </param>
     LockMemoryBank_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char lockType, unsigned char  memoryBank);
	 LockMemoryBank_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char lockType, unsigned char  memoryBank,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
	 virtual void TrigerOnExecuting(void *obj);
private:
		bool bTrigerOnExecuting;
		void  setData(unsigned char antenna, unsigned char *accessPwd, unsigned char lockType, unsigned char  memoryBank);
 };


 /// ��������ָ��
 /// </summary>
  class BlockPermalock_6C : public BaseMessage
 {
	 public:	
		 unsigned char tagID[128];
		 unsigned char tagIDLen;
		 unsigned char tagIDType;
	 /// <param name="antenna">���߶˿�</param>
	 /// <param name="accessPwd">����(4�ֽ�)</param>
	 /// <param name="memoryBank">����Bank</param>
	 /// <param name="readLock">��������(ReadLock):0����ѯ��ǩ�Ŀ�������״̬��Ŀǰ��֧�֣�;1���Ա�ǩ�Ľ��п�����������</param>
	 /// <param name="ptr">��ʼ���ַ(BlockPtr)��ÿ16���飨Block��Ϊһ����Ԫ����0x00��ʾ��block 0��ʼ��0x01��ʾ��block 16��ʼ��</param>
	 /// <param name="blockRange">����������ΧBlockRange��ָʾ�������������ķ�ΧΪ����ʼ���ַ��BlockPtr������16* BlockRange-1������СֵΪ1��</param>
	 /// <param name="mask">���루Mask��2*BlockRange�ֽڣ�ÿһλ��Ӧһ��block��ָʾ�Ӷ�Ӧ��block�Ƿ���п�������������1Ϊִ����������0Ϊ����ԭ����״̬��BlockPtr��ӦMask���λ����16* BlockRange-1����ӦMask�����λ��</param>
		BlockPermalock_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char memoryBank, unsigned char readLock, unsigned char ptr, unsigned char blockRange, unsigned char readLockbits, unsigned char *mask);
		BlockPermalock_6C(unsigned char antenna, unsigned char *accessPwd,unsigned char accessPwdLen, unsigned char memoryBank, unsigned char readLock, unsigned char ptr, unsigned char blockRange, unsigned char readLockbits, unsigned char *mask,unsigned char* tagID,unsigned char tagIDLen, unsigned char tagIDType);
		virtual void TrigerOnExecuting(void *obj);
	 private:
		bool bTrigerOnExecuting;
		void  setData(unsigned char antenna, unsigned char *accessPwd, unsigned char memoryBank, unsigned char readLock, unsigned char ptr, unsigned char blockRange, unsigned char readLockbits, unsigned char *mask);


 };


  /// <summary>
  /// ��ǩ���ָ��
  /// </summary>
  class KillTag_6C : public BaseMessage
  {
	  /// <param name="antenna">���߶˿�</param>
	  /// <param name="killPwd">�������</param>
	  /// <param name="epcData">EPC��</param>
	  public:
	  KillTag_6C(unsigned char antenna, unsigned char *killPwd,unsigned char killPwdLen, unsigned char *epcData,unsigned char epcDataLen);
	          
   };

	 /// ���û�������ָ��
  /// </summary>
 class ReadUserData_6B : public  BaseMessage
  {
 public:
	 unsigned char antenna;
	  unsigned char tagID[128];
	  unsigned char tagIDLen;
	  unsigned char ptr;        
	  unsigned char lastPtr;
	  unsigned char length;
	  //List<Byte> udBuff = new List<byte>();
	  unsigned char udBuff[512];
	  unsigned char udBuffLen;
	  int maxReadLen;//��������ȡ�ֽ���
	  unsigned char dataLength;//ʵ��ȡ���������ֽ���
	  /// <param name="antenna">���߶˿�</param>        
	  /// <param name="tagID">��ǩID</param>
	  /// <param name="ptr">��ǩ��������ʼ��1��107��</param>
	  /// <param name="length">��ǩ���ݶ�ȡ����</param>
	 ReadUserData_6B(unsigned char antenna, unsigned char *tagID,unsigned char tagIDLen,unsigned char ptr, unsigned char length);
	 virtual unsigned char GetAntenna();
	 virtual bool GetUserData(unsigned char *userData,unsigned char &userdataLen);
	 virtual void TrigerOnExecuting(void *obj);

 private:

	 bool bTrigerOnExecuting;
 };


 class WriteUserData_6B : public BaseMessage
 {
 public:
	 unsigned char  antenna;
	 unsigned char ptr;
	 unsigned char tagID[128];
	 unsigned char tagIDLen;
	 unsigned char userdata[512];
	 unsigned char userdataLen;
	 int maxWriteLen ;//�������д���ֽ���
	 /// <param name="antenna">���߶˿�</param>
	 /// <param name="tagID">��ǩID</param>
	 /// <param name="ptr">������д���׵�ַ��1��107��</param>
	 /// <param name="userdata">д��ǩ����������</param>
     WriteUserData_6B(unsigned char antenna, unsigned char *tagID,unsigned char tagIDLen, unsigned char ptr, unsigned char *userdata,unsigned char userdataLen);
	 virtual void TrigerOnExecuting(void *obj);
	 
 private:
	 bool bTrigerOnExecuting;
 };

 /// ���û�������ָ��(���䳤)
 /// </summary>
 class ReadUserData2_6B : public  BaseMessage
 {
 public:
	 unsigned char antenna;
	 unsigned char tagID[512];
	 unsigned char tagIDLen;

	 unsigned char ptr;
	 unsigned char length;
	 //List<Byte> udBuff = new List<byte>();
	 unsigned char udBuff[512];
	 unsigned char udBuffLen;
	 int maxReadLen;//��������ȡ�ֽ���
	
	 /// <param name="antenna">���߶˿�</param>        
	 /// <param name="ptr">��ǩ�������׵�ַ��EVB��ʽ��</param>
	 /// <param name="length">��ǩ���ݶ�ȡ����</param>
	 ReadUserData2_6B(unsigned char  antenna, unsigned char *tagID,unsigned char tagIDLen, unsigned char ptr, unsigned char length);
	 virtual unsigned char GetAntenna();
     virtual bool GetUserData(unsigned char *userData,unsigned char &userDataLen);
	 virtual void TrigerOnExecuting(void *obj);
	 
 private:
	 bool bTrigerOnExecuting;

 };

 /// д�û�������ָ��(д�䳤)
 /// </summary>
 class WriteUserData2_6B : public BaseMessage
 {
	 unsigned char antenna;
	 unsigned char ptr;
	 unsigned char tagID[128];
	 unsigned char tagIDLen;
	 unsigned char userData[512];
	 unsigned char userDataLen;

	 int maxWriteLen;//�������д���ֽ���
	 /// <param name="antenna">���߶˿�</param>
	 /// <param name="tagID">��ǩID</param>
	 /// <param name="ptr">������д���׵�ַ</param>
	 /// <param name="userData">д��ǩ����������</param>
 public:
    WriteUserData2_6B(unsigned char antenna, unsigned char *tagID,unsigned char tagIDLen, unsigned char ptr, unsigned char *userData,unsigned char userDataLen);
	virtual void TrigerOnExecuting(void *obj);
 private:
	 bool bTrigerOnExecuting;	

 };

 /// ����ǩ����ָ��
 /// </summary>
class LockUserData_6B : public BaseMessage
 {
public: 
	unsigned char antenna;
	 unsigned char ptr;
	 unsigned char tagID[128];
	 unsigned char tagIDLen;
	 unsigned char lockInfo[256];
	 unsigned char lockInfoLen;
	 unsigned char lockResult[256];
	 unsigned char lockResultLen;
	 int count;
	 /// <summary>
	 /// ���캯��
	 /// </summary>
	 /// <param name="antenna">���ߺ�</param>
	 /// <param name="tagID">��ǩID��</param>
	 /// <param name="lockInfo">������Ϣ���������ǩ�û�����������һ�£�ÿ���ֽ���Ϣ��ʾ�Ƿ�Ը��ֽڽ���������������0Ϊ������λ�õ��û�����
	 ///                        ע�⣺�������ܽ���</param>
	LockUserData_6B(unsigned char antenna, unsigned char *tagID,unsigned char tagIDLen, unsigned char *lockInfo,unsigned char lockInfoLen);
	virtual void TrigerOnExecuting(void *obj);
private:
	 bool bTrigerOnExecuting;	


};


/// ��ѯ��ǩ������״ָ̬��
/// </summary>
class LockStateQuery_6B : public BaseMessage
{
public:
	unsigned char  antenna;
	unsigned char  ptr;
	unsigned char  tagID[128];
	unsigned char tagIDLen;
	unsigned char  queryInfo[512];
	unsigned char  queryInfoLen;
	unsigned char lockState[512];
	unsigned char lockStateLen;
	int count;

	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="antenna">���ߺ�</param>
	/// <param name="tagID">��ǩID��</param>
	/// <param name="queryInfo">��ѯ��Ϣ���������ǩ�û�����������һ�£�ÿ���ֽ���Ϣ��ʾ�Ը��ֽ��Ƿ�ִ�в�ѯ��������0Ϊִ�в���</param>
   LockStateQuery_6B(unsigned char antenna, unsigned char *tagID,unsigned char tagIDLen, unsigned char *queryInfo,unsigned char queryInfoLen);
   virtual void TrigerOnExecuting(void *obj);
   virtual bool GetLockResult(unsigned char *LockResult,unsigned char &LockResultLen);
private:
	 bool bTrigerOnExecuting;	 		

};
/// ��ѯ��д��ϵͳ����ָ��
class SysQuery_800 : public BaseMessage
{
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="parameter">��ѯ��д��ϵͳ����ָ���������</param> 
    SysQuery_800(unsigned char parameter);
	
	/// ���캯��
	/// </summary>
	/// <param name="parameter">��ѯ��д��ϵͳ����ָ���������</param>
	/// <param name="data">������Ĭ��Ϊ00H,��չ��</param>
    SysQuery_800(unsigned char parameter, unsigned char data);
	
	virtual bool GetQueryData(unsigned char *data,unsigned char &dataLen);
};


/// <summary>
/// ���ö�д��ϵͳ����ָ��
/// </summary>
class SysConfig_800 : public  BaseMessage
{
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="parameter">���ö�д��ϵͳ����ָ���������</param>
	/// <param name="pData">��������</param>
	SysConfig_800(unsigned char  parameter, unsigned char *pData,unsigned char dataLen);


 };  

/// <summary>
/// IO�������ָ��
/// </summary>
class Gpo_800 : public BaseMessage
{
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="ioPort">����˿�(IO_OutputPort)</param>
	/// <param name="level">�����ƽ(IO_OutDianPing)</param>
	Gpo_800(unsigned char ioPort, unsigned char level);
	

};

/// IO�����ѯָ��
/// </summary>
class Gpi_800 : public BaseMessage
{
public:
	Gpi_800();
	Gpi_800(unsigned char  checkMode);
	virtual bool GetQueryData(unsigned char *data,unsigned char &dataLen);

};

/// <summary>
/// ��д������ģʽ����ָ��
/// </summary>
class TestModeConfig_800 : public BaseMessage
{
	/// <param name="parameter">��д������ģʽ����ָ��Ĳ���ģʽ</param>
	/// <param name="pData">���Բ���</param>
public:
	TestModeConfig_800(unsigned char  parameter, unsigned char *pData,unsigned char DataLen);


};

/// ��д����������ָ��
class FirmwareUpgrade_800 : public BaseMessage 
{
public:
	FirmwareUpgrade_800();
	
};

/// ��д������ָ��
class ResetReader_800 : public  BaseMessage 
{
public:
	ResetReader_800();

};

/// <summary>
/// ��д��ϵͳ����У��ָ��
/// </summary>
class SysCheck_800 : public  BaseMessage
{
	/// <param name="parameter">��д��ϵͳ����У��ָ���У�����ͣ�Sys_Check��</param>
	/// <param name="pData">У������</param>
public:
	SysCheck_800(unsigned char parameter, unsigned char *pData,unsigned char DataLen);
	    

};

class PowerOff_800 :  public  BaseMessage
{
public: 
	PowerOff_800();
	virtual void TrigerOnExecuting(void *obj);
	PowerOff_800(ReadTag *readTag);
private:
	bool bTrigerOnExecuting;
	ReadTag *readTag;
	
 };

class PowerOff_500 : public  BaseMessage
{
	
	public: 
		ReadTag *readTag;
		PowerOff_500();
		PowerOff_500(ReadTag *readTag);
		virtual void TrigerOnExecuting(void *obj);
	private:
		bool bTrigerOnExecuting;
};

/// <summary>
/// ������ָ��
/// </summary>
class PowerOn_500 : public BaseMessage
{
	/// ���캯��
	/// </summary>
	/// <param name="antenna">���ߺ�</param>
public:
	PowerOn_500(unsigned char antenna);
};


/// <summary>
/// ��ѯ��д��ϵͳ����ָ��
/// </summary>
class SysQuery_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">ϵͳ������Ϣ����</param>
	/// <param name="infoLength">ϵͳ������Ϣ���ͳ���</param>
public:
	SysQuery_500(unsigned char  infoType, unsigned char infoLength);
	virtual bool GetQueryData(unsigned char *data,unsigned char &dataLen);

};

/// ���ö�д��ϵͳ����ָ��
class SysConfig_500 : public BaseMessage
{
	/// <param name="infoType">ϵͳ������Ϣ����</param>
	/// <param name="infoLength">ϵͳ������Ϣ���ͳ���</param>
	/// <param name="pData">��������</param>
public:
	SysConfig_500(unsigned char infoType, unsigned char infoLength, unsigned char *pData,unsigned char DataLen);

    
};

/// Ƶ������/��ѯ
/// </summary>
class FreqConfig_500 : public BaseMessage
{
	/// ���캯��
	/// </summary>
	/// <param name="infoType">��Ϣ���ͣ�0x10���ã�0x11��ѯ</param>
	/// <param name="infoParam">��Ϣ����</param>
public:
	FreqConfig_500(unsigned char infoType, unsigned char *infoParam,unsigned char infoParamLen);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
};

/// <summary>
/// ģʽ���ã�ԭʼ��������ָ��
/// </summary>
class BaudRateMode_500 : public BaseMessage
{
	/// </summary>
	/// <param name="infoType">��Ϣ����:ԭʼ(0x00)������(0x01)</param>
public:
	BaudRateMode_500(unsigned char infoType);
};

/// <summary>
/// ����ģʽ����/��ѯ
/// </summary>
class WorkModeSet_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">����ģʽ��Ϣ����</param>
	/// <param name="infoParameter">����ģʽ��Ϣ���Ͳ���</param>
public:
	WorkModeSet_500(unsigned char infoType, unsigned char infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);

};

class RssiLimitConfig_500  : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">����ģʽ��Ϣ����</param>
	/// <param name="infoParameter">����ģʽ��Ϣ���Ͳ���</param>
public:
	RssiLimitConfig_500 (unsigned char infoType, unsigned char *infoParameter,unsigned char infoParameterLen);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

class Buzzer_500 : public BaseMessage
{
	/// ���캯��
	/// </summary>
	/// <param name="infoType">������������Ϣ����</param>
public:
	Buzzer_500(unsigned char infoType);
	
};

/// �¶�/ʪ�ȼ��ָ��
/// </summary>
 class TemperatureAndHumidityQuery_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">��Ϣ����:�¶�(0x00),ʪ��(0x01)</param>
public:
    TemperatureAndHumidityQuery_500(unsigned char  infoType);
	virtual bool GetQueryData(unsigned char *pData,unsigned char &dataLen);
	virtual int GetTemperature();
	virtual int GetHumidity();

};

class AntennaInspect_500 : public BaseMessage
{
public:
	AntennaInspect_500();
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
};


/// <summary>
/// ����ģʽ����/��ѯ
/// </summary>
class IODevices_500  : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
  /// <param name="infoType">IO�豸������Ϣ����</param>
        /// <param name="infoParameter">IO�豸������Ϣ���Ͳ���</param>
public:
	IODevices_500 (unsigned char infoType, unsigned char infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

/// ����/��ѯ���ݷ���ʱ��
class DataSentTime_500   : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
 /// <param name="infoType">�������ͣ�0,����;1,��ѯ����ʱ��ʱ����������ֽ������壩</param>
        /// <param name="infoParameter">ʱ��</param>
public:
	DataSentTime_500(unsigned char infoType, unsigned char *infoParameter,unsigned char infoParameterLen);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

/// ����/��ѯ�̵����ĳ�ʼ״̬
class RelayStartState_500    : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">�������ͣ�0,����;1,��ѯ����ʱ��״̬���һ���ֽ������壩</param>
        /// <param name="infoParameter">״̬��    0��  �̵����ĳ�̬Ϊ�Ͽ�;1��  �̵����ĳ�̬Ϊ��ͨ</param>
public:
	RelayStartState_500(unsigned char infoType, unsigned char infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

 /// �������ʲ��� ����/��ѯ
class PowerParamConfig_500    : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
 /// <param name="infoType">��Ϣ���ͣ�0���ã�1��ѯ</param>
        /// <param name="infoParam">��Ϣ����:��ֵ�����0x2000��0x2fff֮��</param> 
public:
	PowerParamConfig_500 (unsigned char infoType, unsigned char *infoParameter,unsigned char infoParameterLen);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

/// <summary>
/// �ָ�ϵͳĬ������
/// </summary>
class ResetToFactoryDefault_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>       
public:
	ResetToFactoryDefault_500();
	
    
};


/// <summary>
/// ����/��ѯ���ݵķ��ͷ�ʽ
/// </summary>
class DataSentMode_500 : public BaseMessage
{
	/// <param name="infoType">�������ͣ�0,����;1,��ѯ����ʱ��״̬���һ���ֽ������壩</param>
	/// <param name="infoParameter">״̬�� 0��  ����ͨ��Τ�����------����1-Τ��1������2-Τ��2</param>
	/// <param name="infoParameter">״̬�� 1��  ����ͨ��Τ�����------����1-Τ��1������2-Τ��1</param>
	/// <param name="infoParameter">2��  ����ͨ��Τ�����------����1-Τ��2������2-Τ��2</param>
	/// <param name="infoParameter">3��  ����ͨ��Τ�����------����1-Τ��1��2������2-Τ��1��2</param>
	/// <param name="infoParameter">4��  ����ͨ���̵�������------����1-�̵�1������2-�̵�2</param>
	/// <param name="infoParameter">5��  ����ͨ���̵�������------����1-�̵�1������2-�̵�1</param>
	/// <param name="infoParameter">6��  ����ͨ���̵�������------����1-�̵�2������2-�̵�2</param>
	/// <param name="infoParameter">7��  ����ͨ���̵�������------����1-�̵�1��2������2-�̵�1��2</param>
	
public:
	DataSentMode_500(unsigned char infoType, unsigned char  infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
};

/// <summary>
/// ����������
/// </summary>
class WhiteList_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="setType">�������ͣ� 1=���ð��������ܣ�������ȡ�����������ܣ�</param>            
public:
	WhiteList_500(unsigned char setType);


};

/// <summary>
/// ����������
/// </summary>
class WhiteListDownLoad_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="data">�������ݣ�wget -c -O username ftp://username:password@IP/filename </param>
public:
	WhiteListDownLoad_500(unsigned char  *data,unsigned char  dataLen);
	
};



/// <summary>
/// ��������ģʽ����
/// </summary>
class StartReaderAndReading_500 : public BaseMessage
{

	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="data">0x00:������������0x01:����������</param>  
public:
	StartReaderAndReading_500(unsigned char  data);

};

 /// Τ��ģʽ����/��ѯ
class WiegandMode_500     : public BaseMessage
{
   /// <param name="infoType">��Ϣ���ͣ�0���ã�1��ѯ</param>
        /// <param name="infoParam">��Ϣ������0Τ��26����ģʽ��1Τ��34����ģʽ</param>
public:
	WiegandMode_500 (unsigned char infoType, unsigned char infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

  /// ��������ģʽ����/��ѯ
class ReadModeTrigger_500 : public BaseMessage
{
       /// <param name="infoType">��Ϣ���ͣ�0���ã�1��ѯ</param>
	/// <param name="infoParam">��Ϣ������
	/// 0����Ҫ����������
	/// 1����IO��1����������
	/// 2����IO��2����������
        /// 3����IO��1��2�����Դ�������</param>
public:
	ReadModeTrigger_500 (unsigned char infoType, unsigned char infoParameter);
	virtual bool GetQueryData(unsigned char *pdata,unsigned char &dataLen);
	
};

/// <summary>
/// ��д��ϵͳ��λ
/// </summary>
class ResetReader_500 : public BaseMessage
{
public:
	ResetReader_500();
};

/// ��������ģʽ����/��ѯ
class PcSendTime_500 : public BaseMessage
{
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="readerID">��д��ID�����ݶ�д��������ID����</param>
	/// <param name="time">ʱ϶</param>
public:
	PcSendTime_500(unsigned char *readerID, unsigned char readerIDLen,unsigned char *time,unsigned char timeLen);
	PcSendTime_500();
	virtual bool GetReaderID(unsigned char *readId,unsigned char &readIdLen);
		 
};



/// ��������ѯ
/// </summary>
class WhiteListQuery_500 : public BaseMessage
{
	/// <param name="data">��ѯ��Ϣ��00��00 =��ѯ״̬�ͼ�¼������
	/// ����=��ѯ�������Ŀ���ݣ���Ŀ����Ų��ܴ����ܵ���Ŀ����</param>            
public:
	WhiteListQuery_500(unsigned char *data,unsigned char dataLen);
	virtual unsigned char GetFlag();
	virtual bool GetCount(unsigned char *count,unsigned char countLen);
	virtual bool GetContent(unsigned char *Content,unsigned char ContentLen);
};

//������/�ͻ���״̬��ѯ
class ServerClientQuery_500 : public BaseMessage
{
	public:
		ServerClientQuery_500();
		virtual bool GetReaderID(unsigned char *readId,unsigned char &readIdLen);
		virtual unsigned char GetTcpIpStatus();
		virtual bool GetInfo(unsigned char *info,unsigned char &infoLen);
};

//�ͻ���ģʽ������IP����
class PcIpsConfig_500 : public BaseMessage
{
	public:
		PcIpsConfig_500(unsigned char serverCount,unsigned char *ips,unsigned char ipsLen);
};

//�ͻ���ģʽ������IP��ѯ
class PcIpsQuery_500 : public BaseMessage
{
	public:
		PcIpsQuery_500();
		virtual unsigned char GetServerCount();
		virtual bool GetIpsInfo(unsigned char *ipsInfo,unsigned char &ipsInfoLen);
		
};

//��ѯDHCP����
class QueryDhcp_500 : public BaseMessage
{
	public:
		QueryDhcp_500();
		
		virtual unsigned char GetIpsInfo();
};

/// ����DHCP����

class EnableDhcp_500 : public BaseMessage
{
	public:
		EnableDhcp_500();
};

//�ر�DHCP����
class DisableDhcp_500 : public BaseMessage
{
	public:
		DisableDhcp_500();
		/// <param name="netInfo">12���ֽڣ��ֱ�ΪIP��ַ���������뼰�����������֡��ڹر�DHCP���ܺ󣬾��Ǿ�̬����IP��ַ��</param>
		DisableDhcp_500(unsigned char *netInfo,unsigned char netInfoLen);
};

//���ö�д��ϵͳ��ϢF6By
class FrequencyTableConfig_F6B : public BaseMessage
{
	public:
		 /// <param name="infoType">ϵͳ������Ϣ���ͣ�00���ã�01��ѯ</param>
        /// <param name="param">��Ϣ������2�ֽڣ�</param>
		FrequencyTableConfig_F6B(unsigned char infoType,unsigned char *param,unsigned char paramLen);
		FrequencyTableConfig_F6B();
		virtual unsigned char GetInfoType();
		virtual bool GetFrequencyTable(unsigned char *frequencyTable,unsigned char &frequencyTableLen);
};
 /// ���ʱ�����
 class FrequencyTableReset_F6B : public BaseMessage
 {
	public:
		FrequencyTableReset_F6B();
 };


 class AutoRead6CTagConfig_800 : public BaseMessage
 {
	public:
		 AutoRead6CTagConfig_800(unsigned char infoType);
		 /// <param name="infoType">��Ϣ����:0Ϊ���ã�1Ϊ��ѯ</param>
		 /// <param name="infoParam">��Ϣ����</param>
		 /// ��Ϣ������
		 /// ��1���ֽڶ�EPC���أ�0=����ȡEPC�룬1=��ȡEPC��
		 /// ��2���ֽڶ�TID���أ�0=����ȡTID�룬1=��ȡTID��
		 /// ��3���ֽڶ�TID����ֳ���
		 /// ��4���ֽڶ�USR���ݿ��أ�0=����ȡUSR��1=��ȡUSR
		 /// ��5���ֽڶ�USR���������ֳ���
		 /// <param name="triggerPort">�����˿�</param>
		 /// <param name="triggerType">������ʽ</param>
		 /// <param name="antenna">����</param>
		 /// <param name="q">Q</param>
		 AutoRead6CTagConfig_800(unsigned char infoType, unsigned char *infoParam,unsigned char infoParamLen, unsigned char triggerPort, unsigned char triggerType, unsigned char antenna, unsigned char q);
		 virtual unsigned char GetInfoType();
		 virtual bool GetInfoParam(unsigned char *pInfoParam,unsigned char pInfoParamLen);
		 virtual unsigned char GetTriggerPort();
		 virtual unsigned char GetTriggerType();
		 virtual unsigned char GetAntenna();
		 virtual unsigned char GetQ();
 };



 /// <summary>
 /// �Զ���ȡֹͣ����
 /// </summary>
 class StopTrigger_800  : public BaseMessage
 {	

	public:
		StopTrigger_800(unsigned char triggerType, unsigned char *param,unsigned char paramLen);


 };

//����ź�
class  RXD_TriggerSignal_800 : public BaseMessageNotification
{
	public:
		RXD_TriggerSignal_800();
		virtual bool GetIsReadTag();
};

//�Զ������ź�
class RXD_AutoReadTagSignal_800 : public BaseMessageNotification
{

	public:
		RXD_AutoReadTagSignal_800();
		virtual bool GetIsReadTag();
};

/// I/O�ź�
class RXD_IOSignal_800 : public BaseMessageNotification
{
	public:
		RXD_IOSignal_800();
	/// ��ȡ ����״̬
	virtual unsigned char GetState();	
	/// ��ȡ ���״̬
	virtual unsigned char GetPort();
	/// ��ȡ ��ѯʱ��
	virtual bool GetTime(unsigned char *pTime,unsigned char TimeLen);
	/// ��ȡ ��ȡʱ���ַ���
	virtual CString GetTimeStr();

private:
	 double HexConverToDouble(CString hexString);
	 CString strData(char *buf);
	 CString getMon(CString strMonValue);
	 long bytesToLong(char * buf);
};

 // ������/�ͻ���״̬����
class ServerClientConfig_500 : public BaseMessage
{
	public:
		/// <param name="type">������/�ͻ���ģʽ</param>
		/// <param name="ports">�����˿ں�</param>
		ServerClientConfig_500(unsigned char  type, unsigned char *ports,unsigned char portsLen);
		virtual unsigned char GetReaderType();

};

//
class RXD_TID_6C_2 : public BaseMessage
{

	public:
		/// <param name="readerID">��д��ID</param>
		/// <param name="dataNO">�������к�</param>
		RXD_TID_6C_2(unsigned char *readerID,unsigned char readerIDLen,unsigned char *dataNO,unsigned char dataNOLen);
		virtual bool GetReaderID(unsigned char *pReaderID,unsigned char readerIDLen);
		virtual bool GetDataNO(unsigned char *pDataNO,unsigned char DataNOLen);
		virtual bool GetTID(unsigned char *pTID,unsigned char TIDLen);
		virtual bool GetTime(unsigned char *pTime,unsigned char TimeLen);
		virtual unsigned char GetAntenna();
};


//806������
class Keepalive : public BaseMessage
{

public:
	Keepalive();
	Keepalive(unsigned char *sequence,unsigned char sequenceLen,unsigned char *utc,unsigned char utcLen);

	virtual bool GetIntervalTime(unsigned char *intervalTime,unsigned char &intervalTimeLen);
	virtual bool GetSequence(unsigned char *sequence,unsigned char &sequenceLen);
};

class ReadTagTriggerConfig_800:public BaseMessage
{
	
	
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="infoType">��Ϣ����:0Ϊ���ã�1Ϊ��ѯ</param>
	/// <param name="infoParam">��Ϣ����</param>
	/// ��1���ֽ�6C ��������   (0��ʾ����6C��ǩ)
	/// ��2���ֽڶ�6C TID����ֳ���
	/// ��3���ֽ�6C����������  (��λ: ��)
	/// ��4���ֽڶ�6C USR��������ʼ��ַ(EVB��ʽ N�ֽ�)
	/// ��5+N���ֽڶ�6C USR���������ֳ���
	/// ��6+N���ֽ�6C��������       (4�ֽ�)
	/// ��10���ֽ�6B ��������	(0��ʾ����6B��ǩ)
	/// ��11���ֽڶ�6B USR��������ʼ��ַ(EVB��ʽ N�ֽ�)
	/// ��12���ֽڶ�6B USR���������ֳ���
	/// <param name="triggerPort">�����˿�</param>
	/// 0x01     �˿�1
	/// 0x02     �˿�2
	/// 0x03	 �˿�3
	/// 0x04     �˿�4
	/// <param name="triggerType">������ʽ</param>
	/// 0x00     ��������
	/// 0x01     �ߵ�ƽ����
	/// 0x02     �͵�ƽ����
	/// 0x03     �����ش���
	/// 0x04     �½��ش���
	/// <param name="antenna">����</param>
	/// <param name="q">Q</param>

	ReadTagTriggerConfig_800(
		unsigned char infoType,
		unsigned char readTimes6C,
		unsigned char tidLength6C,
		unsigned char reservedMemoryLength6C,
		int userDataPtr6C,
		unsigned char userDataLength6C,
		unsigned char * accessPwd6C,
		unsigned char accessPwd6CLen,
		unsigned char readTimes6B,
		int userDataPtr6B,
		unsigned char userDataLength6B,
		unsigned char q,
		unsigned char * portInfo,
		unsigned char portInfoLen);

	ReadTagTriggerConfig_800(unsigned char  infoType);

	virtual unsigned char GetInfoType();
	virtual unsigned char GetReadTimes6C();
	virtual unsigned char GetTidLength6C();
	virtual unsigned char GetReservedMemoryLength6C();
	virtual unsigned int GetUserDataPtr6C();
	virtual unsigned char GetUserDataLength6C();
	virtual	bool GetAccessPwd6C(unsigned char* pwd,unsigned char &pwdLen);
	virtual unsigned char GetReadTimes6B();
	virtual unsigned int GetUserDataPtr6B();
	virtual unsigned char GetUserDataLength6B();
	virtual unsigned char GetQ();
	virtual bool GetPortInfo(unsigned char* portInfo,unsigned char &PortInfoLen);
private:
	int  userDataPtr6C_EvbLen ;
	unsigned int  userDataPtr6C ;
	int userDataPtr6B_EvbLen;
	unsigned int userDataPtr6B;
};

class RXD_IOTriggerSignal_800 : public BaseMessageNotification
{

	public:
		RXD_IOTriggerSignal_800();
		virtual unsigned char GetGPIPort();
		virtual bool GetIsStart();
		virtual bool GetUTCTime(unsigned char *pUTCTime,unsigned char &UTCTimeLen);
		//virtual unsigned char GetGPIState();
		//virtual unsigned char GetIsReadTag();
};

#endif
