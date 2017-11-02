package com.invengo.xcrf.ui.dialog;

import java.awt.Container;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.Insets;
import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JDialog;
import javax.swing.JProgressBar;

import com.invengo.xcrf.core.util.DemoUtil;


public class WaitBar extends JDialog {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public WaitBar() {
		Toolkit tk = Toolkit.getDefaultToolkit();
		Image image = tk.createImage(DemoUtil.getResource("image/logo.gif"));
		setIconImage(image);
		// ���ô�С
		setSize(200, 100);
		// ģ̬�Ի���
		setModal(true);
		// ���þ���
		setLocationRelativeTo(null);
		// ���ӹرմ����¼�
		addWindowListener(new WindowAdapter() {
			@SuppressWarnings("unused")
			public void WindowClosing(WindowEvent e) {
				dispose();
			}
		});
        Container pane = getContentPane();
        pane.setLayout(null);
        Insets insets = pane.getInsets();

        JProgressBar bar = new JProgressBar(0,100);//����������
        bar.setIndeterminate(true);//ֵΪ true ��ζ�Ų�ȷ������ֵΪ false ����ζ����ͨ����ȷ���� 

        Dimension dim = bar.getPreferredSize();
        int x = insets.left + 20;
        int y = insets.top + 20;
        dim.width += 100;
        bar.setBounds(x,y,dim.width,dim.height);
        pane.add(bar);		
		
	}
}
