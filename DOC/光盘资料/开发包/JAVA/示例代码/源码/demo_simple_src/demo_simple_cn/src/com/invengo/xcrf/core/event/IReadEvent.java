package com.invengo.xcrf.core.event;

/**
 * ����ǩ������
 * @author zxl672
 *
 */
public interface IReadEvent {
	/**
	 * ��ʼ��
	 *
	 */
	void isRead();

	/**
	 * ֹͣ��
	 *
	 */
	void isStopRead();
	
	/**
	 * ���
	 *
	 */
	void clear();
}
