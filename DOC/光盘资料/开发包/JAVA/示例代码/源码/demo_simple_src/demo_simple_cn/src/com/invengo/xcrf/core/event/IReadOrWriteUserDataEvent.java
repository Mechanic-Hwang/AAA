package com.invengo.xcrf.core.event;

/**
 * ��д��ǩ���ݼ�����
 * 
 * @author zxl672
 * 
 */
public interface IReadOrWriteUserDataEvent {

	/**
	 * �����ť�¼�
	 * 
	 * @param type
	 * @param id
	 */
	void clickButton(int type, String id);
	
}
