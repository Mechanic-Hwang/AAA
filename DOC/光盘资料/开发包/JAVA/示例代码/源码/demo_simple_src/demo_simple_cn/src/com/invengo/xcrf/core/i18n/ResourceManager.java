package com.invengo.xcrf.core.i18n;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Locale;
import java.util.ResourceBundle;


/**
 * @author zxl672
 */
public class ResourceManager {

	/**
	 * �������б�
	 */
	LinkedList<LanguageChangeListener> listeners = new LinkedList<LanguageChangeListener>();

	/**
	 * �ض����Ի�����Դ������
	 */
	ResourceBundle bundle;

	/**
	 * �������Ի���
	 */
	Locale locale;

	/**
	 * ResourceBundle�ļ�
	 */
	private static final String RESOURCE_NAME = "resswing";

	/**
	 * ʹ��Singletonʹ��ResourceManager�ڳ�����ֻ��һ��ʵ��
	 */
	private static ResourceManager _instance = new ResourceManager();

	public static ResourceManager getInstance() {
		return _instance;
	}

	/**
	 * ����������ʾ
	 * 
	 * @param lang
	 */
	public void changeLang(String lang) {
		// 1 ��bundle
		if (lang.equalsIgnoreCase("zh_CN")) {
			locale = Locale.CHINA;
//			XcrfInstruction.load("cn");
		} else {
			locale = Locale.US;
//			XcrfInstruction.load(lang);
		}
		// 2 ֪ͨlisteners
		Iterator<LanguageChangeListener> ite = listeners.iterator();
		while (ite.hasNext()) {
			(ite.next()).updateResource();
		}
	}

	/**
	 * ȡ����ʾ�ַ���
	 * 
	 * @param key
	 * @return
	 */
	public String getString(String key) {
		return getBundle().getString(key);
	}

	/**
	 * ȡ�����ú�����԰汾�����û�����ã���ʹ��Ĭ��ֵLocal.US
	 * 
	 * @return
	 * @uml.property name="bundle"
	 */
	public ResourceBundle getBundle() {

		if (locale == null)
			locale = Locale.CHINA;

		bundle = ResourceBundle.getBundle(RESOURCE_NAME, locale);
		return bundle;
	}

	/**
	 * ���Ӽ�����
	 * 
	 * @param lsn
	 */
	public void addListener(LanguageChangeListener lsn) {
		listeners.add(lsn);
	}
	
	
	public static void main(String[] args) {
		
		ResourceBundle bundle = ResourceManager.getInstance().getBundle();
		System.out.println(bundle);
		
	}

}
