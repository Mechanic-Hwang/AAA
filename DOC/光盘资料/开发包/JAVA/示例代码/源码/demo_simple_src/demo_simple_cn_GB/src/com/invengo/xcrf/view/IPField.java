package com.invengo.xcrf.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Rectangle;
import java.awt.event.ComponentEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.StringTokenizer;

import javax.swing.BorderFactory;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.Border;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.PlainDocument;

/**
 * һ��������IP�����ʵ����ֻ��һ���ļ�
 */
public class IPField extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private static final Dimension fixedDimension = new Dimension(140, 23);

	private static final int fixedWidth = 140; // ����Ĺ̶�����

	private static final int fixedHeight = 23; // ����Ĺ̶����

	private String ipAddress;

	JTextIPSpace digitalText1 = new JTextIPSpace();

	JTextIPSpace digitalText2 = new JTextIPSpace();

	JTextIPSpace digitalText3 = new JTextIPSpace();

	JTextIPSpace digitalText4 = new JTextIPSpace();

	JLabel jLabel1 = new JLabel();

	JLabel jLabel2 = new JLabel();

	JLabel jLabel3 = new JLabel();

	Border border;

	public JTextField prevComponent;

	public JTextField nextComponent;

	public IPField() {
		try {
			jbInit(); // ��ʼ��
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	/**
	 * <pre>
	 *    
	 *    Function:   jbInit   
	 *    Description:   ��ʼ�����ɹ��캯������   
	 * </pre>
	 * 
	 * @param void
	 * @return void
	 * @exception Exception
	 */
	private void jbInit() throws Exception {
		border = BorderFactory.createEmptyBorder(); // ����һ����ռ�ÿռ�Ŀձ߿򣨶��ߡ����ߡ���߿��ߺ��ұ߿��ߵĿ�ȶ�Ϊ�㣩

		digitalText1.setPrevNextComponent(digitalText4, digitalText2);
		digitalText2.setPrevNextComponent(digitalText1, digitalText3);
		digitalText3.setPrevNextComponent(digitalText2, digitalText4);
		digitalText4.setPrevNextComponent(digitalText3, null);

		this.setLayout(null);
		this.setBorder(BorderFactory.createEtchedBorder()); // ����һ�����С����񻯡����Ч���ı߿򣬽�����ĵ�ǰ����ɫ���ڸ�����ʾ����Ӱ��ʾ
		this.addComponentListener(new java.awt.event.ComponentAdapter() {
			public void componentResized(ComponentEvent e) {
				this_componentResized(e);
			}
		});

		this.setSize(fixedWidth, fixedHeight);
		this.setMaximumSize(fixedDimension);
		this.setMinimumSize(fixedDimension);
		this.setPreferredSize(fixedDimension);

		// ���õ�һ�����������
		digitalText1.setBorder(border);
		digitalText1.setHorizontalAlignment(SwingConstants.CENTER);
		digitalText1.setBounds(new Rectangle(2, 2, 30, 19)); // X���꣬Y���꣬����

		// ���õڶ������������
		digitalText2.setBounds(new Rectangle(37, 2, 30, 19));
		digitalText2.setBorder(border);
		digitalText2.setHorizontalAlignment(SwingConstants.CENTER);

		// ���õ��������������
		digitalText3.setBounds(new Rectangle(72, 2, 30, 19));
		digitalText3.setBorder(border);
		digitalText3.setHorizontalAlignment(SwingConstants.CENTER);

		// ���õ��ĸ����������
		digitalText4.setBounds(new Rectangle(107, 2, 30, 19));
		digitalText4.setBorder(border);
		digitalText4.setHorizontalAlignment(SwingConstants.CENTER);

		jLabel1.setBounds(new Rectangle(30, 2, 8, 19));
		jLabel1.setFont(new java.awt.Font("Dialog", 0, 13)); // ����"."������
		jLabel1.setOpaque(true);
		jLabel1.setHorizontalAlignment(SwingConstants.CENTER);
		jLabel1.setText(".");

		jLabel2.setBounds(new Rectangle(65, 2, 8, 19));
		jLabel2.setText(".");
		jLabel2.setOpaque(true);
		jLabel2.setHorizontalAlignment(SwingConstants.CENTER);
		jLabel2.setHorizontalTextPosition(SwingConstants.CENTER);
		jLabel2.setFont(new java.awt.Font("Dialog", 0, 13));

		jLabel3.setBounds(new Rectangle(100, 2, 8, 19));
		jLabel3.setText(".");
		jLabel3.setOpaque(true);
		jLabel3.setHorizontalAlignment(SwingConstants.CENTER);
		jLabel3.setFont(new java.awt.Font("Dialog", 0, 13));

		this.add(digitalText1);
		this.add(jLabel1);
		this.add(digitalText2);
		this.add(jLabel2);
		this.add(digitalText3);
		this.add(jLabel3);
		this.add(digitalText4);

	}

	public void setEnabled(boolean valueSel) {
		if (valueSel == false) {
			digitalText1.setEditable(false);
			digitalText2.setEditable(false);
			digitalText3.setEditable(false);
			digitalText4.setEditable(false);
		} else {
			digitalText1.setEditable(true);
			digitalText2.setEditable(true);
			digitalText3.setEditable(true);
			digitalText4.setEditable(true);
		}
	}

	/**
	 * <pre>
	 *    
	 *    Function:   setIpAddress   
	 *    Description:   ����IP��ַ   
	 * </pre>
	 * 
	 * @param newIpAddress
	 * @return void
	 * @exception void
	 */
	public void setIpAddress(String newIpAddress) {

		// ��"/"Ϊ�ָ��
		StringTokenizer strToken = new StringTokenizer(newIpAddress, ".");
		String[] strIPAddress = new String[strToken.countTokens()];

		if (strToken.countTokens() != 4)
			return;

		// �ָ�IP��ַ��
		int k = 0;
		while (strToken.hasMoreTokens()) {
			strIPAddress[k] = strToken.nextToken();
			k++;
		}

		// �����鸳ֵ
		try {
			digitalText1.setText(strIPAddress[0]);
			digitalText2.setText(strIPAddress[1]);
			digitalText3.setText(strIPAddress[2]);
			digitalText4.setText(strIPAddress[3]);

			ipAddress = getIpAddress();
		} catch (Exception e) {
			return;
		}
	}

	public void setText(String newIpAddress) {

		// ��"/"Ϊ�ָ��
		StringTokenizer strToken = new StringTokenizer(newIpAddress, ".");
		String[] strIPAddress = new String[strToken.countTokens()];

		if (strToken.countTokens() != 4)
			return;

		// �ָ�IP��ַ��
		int k = 0;
		while (strToken.hasMoreTokens()) {
			strIPAddress[k] = strToken.nextToken();
			k++;
		}

		// �����鸳ֵ
		try {
			digitalText1.setText(strIPAddress[0]);
			digitalText2.setText(strIPAddress[1]);
			digitalText3.setText(strIPAddress[2]);
			digitalText4.setText(strIPAddress[3]);

			ipAddress = getIpAddress();
		} catch (Exception e) {
			return;
		}
	}

	/**
	 * <pre>
	 *    
	 *    Function:   getIpAddress   
	 *    Description:   ��4��������ȡIP��ַ   
	 * </pre>
	 * 
	 * @param void
	 * @return void
	 * @exception void
	 */
	public String getIpAddress() {
		if (digitalText1.getText().length() != 0
				&& digitalText2.getText().length() != 0
				&& digitalText3.getText().length() != 0
				&& digitalText4.getText().length() != 0) {
			ipAddress = digitalText1.getText() + "." + digitalText2.getText()
					+ "." + digitalText3.getText() + "."
					+ digitalText4.getText();
			return ipAddress;
		} else {
			return null;
		}
	}

	public String getText() {
		ipAddress = digitalText1.getText() + "." + digitalText2.getText() + "."
				+ digitalText3.getText() + "." + digitalText4.getText();
		return ipAddress;
	}

	void this_componentResized(ComponentEvent e) {
		this.setSize(fixedWidth, fixedHeight);
		validate();
	}

	public void setBounds(int l, int t, int w, int h) {
		super.setBounds(l, t, w, h);
		return;
	}

	@Override
	public void requestFocus() {
		digitalText1.requestFocus();
	}
	
	public void clear(){
		digitalText1.setText("");
		digitalText2.setText("");
		digitalText3.setText("");
		digitalText4.setText("");
	}

	class JTextIPSpace extends JTextField {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public int minValue = 0;
		public int maxValue = 255;
		public JTextIPSpace textipspace;
		public boolean bFirstLostFocus = true;
		public boolean isCanFocus = false;
		public JTextField prevComponent;
		public JTextField nextComponent;

		public JTextIPSpace() {
			this(null, 255, true);
		}

		public JTextIPSpace(String str) {
			this(str, 255, true);
		}

		public JTextIPSpace(int maxValue, boolean isCanFocus) {
			this(null, maxValue, isCanFocus);
		}

		public JTextIPSpace(String str, int maxValue, boolean isCanFocus) {
			super(str);
			setNoEdge();
			setMidHorizontal();
			addKeySet();
			setBackground(new Color(6710886));
			textipspace = this;
			this.maxValue = maxValue;
			this.isCanFocus = isCanFocus;
		}

		public void setNoEdge() {
			setBorder(null);
			setOpaque(true);
		}

		public void setPrevNextComponent(JTextField prev, JTextField next) {
			this.prevComponent = prev;
			this.nextComponent = next;
		}

		private void addKeySet() {
			KeyAdapter ka = new KeyAdapter() {
				public void keyPressed(KeyEvent e) {
					if (e.getKeyCode() == KeyEvent.VK_LEFT) {
						int pos = getCaretPosition();
						if (pos == 0) {
							gotoComponent(prevComponent);
						}
					} else if (e.getKeyCode() == KeyEvent.VK_UP) {
						if (prevComponent != null)
							prevComponent.selectAll();
						gotoComponent(prevComponent);
					} else if (e.getKeyCode() == KeyEvent.VK_DOWN) {
						if (nextComponent != null)
							nextComponent.selectAll();
						gotoComponent(nextComponent);
					} else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
						int pos = getCaretPosition();
						int maxPos = getText().trim().length();
						if (pos == maxPos || maxPos == 0) {
							gotoComponent(nextComponent);
						}
					} else if (e.getKeyCode() == KeyEvent.VK_BACK_SPACE) {
						int pos = getCaretPosition();
						if (pos == 0) {
							gotoComponent(prevComponent);
						}
					} else if (e.getKeyChar() == '.') {
						int maxPos = getText().trim().length();
						if (maxPos > 0) {
							if (getSelectedText() == null) {
								if (nextComponent != null)
									nextComponent.selectAll();
								gotoComponent(nextComponent);
							}
						}
					}
				}

				public void keyReleased(KeyEvent e) {
					if (Character.isDigit(e.getKeyChar())) {
						int pos = getCaretPosition();
						if (pos >= 3) {
							gotoComponent(nextComponent);
						}
					}
				}
			};
			addKeyListener(ka);
		}

		public void gotoComponent(JComponent jc) {
			if (jc != null)
				jc.requestFocus();
		}

		public void setMidHorizontal() {
			setHorizontalAlignment(JTextField.CENTER);
		}

		protected Document createDefaultModel() {
			return new DigitalTextDocument(this);
		}

		public boolean isFocusTraversable() {
			return isCanFocus;
		}
	}

	class DigitalTextDocument extends PlainDocument {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		private JTextField JTF;

		public DigitalTextDocument(JTextField tmpJTF) {
			JTF = tmpJTF;
		}

		// ���ظ����insertString����
		public void insertString(int offset, String str, AttributeSet a)
				throws BadLocationException {
			int valueAfterInsert = 0;
			String strBeforeInsert = getText(0, getLength());
			String strAfterInsert = strBeforeInsert.substring(0, offset) + str
					+ strBeforeInsert.substring(offset);

			// ���ȱ�֤������ַ�������������������ǣ��򲻽��в������
			try {
				valueAfterInsert = Integer.parseInt(strAfterInsert);
			} catch (NumberFormatException e) {

				return;
			}

			// ��������ַ���str���ĵ������������ʧ��
			if (strAfterInsert.length() > 3)
				return;

			// �����������ݳ�����Χ������ʧ�ܣ���������
			else if (valueAfterInsert > 255) {
				JTF.setText("255");
				JOptionPane.showConfirmDialog(null, valueAfterInsert
						+ "����һ����Ч��Ŀ����ָ��һ������ 0 �� 255 ֮�����ֵ", "��ʾ",
						JOptionPane.CLOSED_OPTION);
				JTF.setCaretPosition(0);
			} else {
				super.insertString(offset, str, a);
				return;
			}
		}
	}
}
