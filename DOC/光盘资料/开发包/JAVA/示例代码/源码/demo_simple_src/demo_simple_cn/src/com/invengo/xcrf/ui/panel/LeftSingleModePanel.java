package com.invengo.xcrf.ui.panel;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JToolBar;
import javax.swing.SwingConstants;

import com.invengo.xcrf.core.demo.DemoPanelRegistry;

public class LeftSingleModePanel extends JPanel{
	
	public LeftSingleModePanel(){
		
		
		setLayout(new BorderLayout());
		
		JToolBar toolBar = new JToolBar(SwingConstants.VERTICAL);
		toolBar.setFloatable(false);// ����JToolBar�ɷ񸡶�.
		
		
		JButton jb = new JButton("��ʾ������ʾ����");
		toolBar.add(jb);
		toolBar.addSeparator();
		
		jb = new JButton("��ǩ����");
		toolBar.add(jb);
		toolBar.addSeparator();
		
		jb = new JButton("��������");
		toolBar.add(jb);
		toolBar.addSeparator();
		
		jb = new JButton("�߼�����");
		toolBar.add(jb);
		toolBar.addSeparator();
		
		jb = new JButton("�������");
		toolBar.add(jb);
		toolBar.addSeparator();
		
		jb = new JButton("����");
		toolBar.add(jb);
		
		jb.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent arg0) {
					
					DemoPanelRegistry.changePanelMode();
					
				}
			}
		);
		
		add(toolBar,BorderLayout.CENTER);
		
		
//		setMaximumSize(new Dimension(400,1024));
//		setMinimumSize(new Dimension(200,1024));
		
	}
	
	public static void main(String[] args) {
		
		Frame f = new Frame();
		JPanel a = new LeftSingleModePanel();
		a.setVisible(true);
		f.add(a);
		
	}
	

}
