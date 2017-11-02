package com.invengo.xcrf.core.util;

import java.awt.Toolkit;
import java.util.regex.Pattern;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.JTextComponent;
import javax.swing.text.PlainDocument;

@SuppressWarnings("serial")
public class CheckInput extends PlainDocument {
	private String limit = null; // �����ַ����Ƶ�������ʽ

	private int maxLength = -1; // �����ַ���󳤶ȵ����ƣ�-1Ϊ������

	private double maxValue = 0; // �������������֣������ֵ����
	private double minValue = 0; // �������������֣�����Сֵ����

	private boolean isMaxValue = false; // �Ƿ���������ֵ����
	private boolean isMinValue = false; // �Ƿ��������Сֵ����

	private Toolkit toolkit = null; // �����ڴ����ʱ�򷢳�ϵͳ����
	private JTextComponent mytarget;
	private String limit2=null;
	
	public CheckInput(String limit,JTextComponent target,int maxLength)
	{
		super();
		this.init();
		this.limit=limit;
		this.maxLength=maxLength;
		target.setDocument(this);
		mytarget=target;
	}
	public CheckInput(String limit2,String limit,JTextComponent target,int maxLength)
	{
		super();
		this.init();
		this.limit=limit;
		this.limit2=limit2;
		this.maxLength=maxLength;
		target.setDocument(this);
		mytarget=target;
	}

	public CheckInput() {
		super();
		this.init();
	}

	private void init() {
		toolkit = Toolkit.getDefaultToolkit();
	}

	public void setCharLimit(String limit) {
		this.limit = limit;
	}

	public void setMaxLength(int maxLength) {
		this.maxLength = maxLength;
	}

	public void setMaxValue(double maxValue) {
		this.isMaxValue = true;
		this.maxValue = maxValue;
	}
	
	public void setMinValue(double minValue) {
		this.isMinValue = true;
		this.minValue = minValue;
	}

	@Override
	public void insertString(int offs, String str, AttributeSet a)
			throws BadLocationException, NumberFormatException {
		// offs��ʼ��ƫ���� str - Ҫ������ַ���
		// ���ַ���Ϊ�գ�ֱ�ӷ��ء�
		if (str == null) {
			return;
		}
		char[] ch = str.toCharArray();
		if(mytarget!=null&&mytarget.getText()!=null&&limit2!=null)
		{
			boolean ab2 = Pattern.compile(limit2).matcher(mytarget.getText()+str).matches();
			if (!ab2) {
				super.insertString(offs, "", a);
				toolkit.beep(); // ��������
				return;
			}
		}

		
		for (int i = 0; i < ch.length; i++) {
			String temp = String.valueOf(ch[i]);
			// ���Ҫ������ַ���������Χ��
			boolean ab = Pattern.compile(limit).matcher(temp).find();
			if (!ab) {
				toolkit.beep(); // ��������
				return;
			}
			// ������ַ��������ƣ��������ڵ��ַ������Ѿ����ڻ��������
			if (maxLength > -1 && this.getLength() >= maxLength) {
				toolkit.beep(); // ��������
				return;
			}
		}
		// ��������������������
		if (isMaxValue) {
			String s = this.getText(0, this.getLength()); // �ĵ������е��ַ�
			s = s.substring(0, offs) + str + s.substring(offs, s.length());
			if (Double.parseDouble(s) > maxValue) {
				toolkit.beep(); // ��������
				return;
			}
		}
		// ���������������С����
		if (isMinValue) {
			String s = this.getText(0, this.getLength()); // �ĵ������е��ַ�
			s = s.substring(0, offs) + str + s.substring(offs, s.length());
			if (Double.parseDouble(s) < minValue) {
				toolkit.beep(); // ��������
				return;
			}
		}
		super.insertString(offs, new String(ch), a);
	}
}