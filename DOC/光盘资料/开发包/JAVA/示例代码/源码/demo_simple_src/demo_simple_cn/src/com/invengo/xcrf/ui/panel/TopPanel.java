/**
 * ״̬��
 */
package com.invengo.xcrf.ui.panel;

import java.awt.Dimension;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.invengo.xcrf.ui.MainFrame;


/**
 * �ײ�״̬��ʾ
 * @author zxl672
 */
public class TopPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	final ImageIcon backgroundImg = new ImageIcon(MainFrame.class
			.getResource("image/OpBtn1.png"));
	
	public TopPanel() {

		// ��ʾ״̬��
		JLabel statusLabel = new JLabel(" ");
		add(statusLabel);

		// ��������ʴ�С�����
		this.setPreferredSize(new Dimension(10, 76));
		
		

				
	
	}
//	public void paintComponent(Graphics g) {
//		int width = this.getWidth();
//		int height = this.getHeight();
//			g
//			.drawImage(backgroundImg.getImage(), 0, 0, width,
//					height, this);
//				super.paintComponent(g);
//	}

}