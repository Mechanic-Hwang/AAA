#ifndef _MESSAGEFRAME_
#define  _MESSAGEFRAME_

class MessageFrame
{

public:

protected:
	unsigned int msgType; //������
    unsigned  char msgLen[2]; //ָ���,2�ֽ�
    unsigned char msgBody[256];  //ָ������
    unsigned int iMsgBodyLen;//Msg body����
	unsigned char crc[2]; //crcУ����
    
};

#endif