package com.invengo.xcrf.core.event;

/**
 * ȡ�����Ӳ����ӿ�
 * 
 * @author zxl672
 * 
 */
public interface IReadPara {

	/**
	 * ȡ�ö�������
	 * 
	 * @return
	 */
	int getReadType();

	/**
	 * ȡ��Qֵ
	 * 
	 * @return
	 */
	int getQvalue();

	/**
	 * ȡ�����ߺ�
	 * 
	 * @return
	 */
	int getAntNo();
	
	boolean isOpenBeep();
}
