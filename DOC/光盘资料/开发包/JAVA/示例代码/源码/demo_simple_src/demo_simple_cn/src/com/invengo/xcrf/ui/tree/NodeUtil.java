package com.invengo.xcrf.ui.tree;

import java.util.Enumeration;


public class NodeUtil {
	
	
	public static void changeParentNodesStatus(CheckNode node)
	{
//	    if(!node.isLeaf())
//	    	//�����ӽڵ㣬��ͬ��ѡ��״̬�������ӽڵ�
//	    {
//	    	NodeUtil.changeChildNodesSelectStatus(node);
//	    }
//	    else{
	    	//����Ҷ�ӽڵ�
	    	//case 1: Ҷ�ӽڵ�ȡ��ѡ��ʱ�����и��ڵ㣬����ڵ�Ҳȡ��ѡ��
	    	if(node.isSelected() == false)
	    	{
	    		if(node.getParent()!= null && ((CheckNode)node.getParent()).isSelected() == true)
	        		((CheckNode)node.getParent()).setParentNodeSelected(false);
	    	}
	    	//case 2: Ҷ�ӽڵ�ѡ��ʱ�����и��ڵ㣬���ж�����Ҷ�ӽڵ��Ƿ�ȫ��ѡ�У���ȫ��ѡ�У�����¸��ڵ�Ϊѡ��
	    	else if(node.isSelected() == true)
	    	{
	    		if(node.getParent()!= null && ((CheckNode)node.getParent()).isSelected() == false)
	    		{
	    			CheckNode parentNode = (CheckNode)node.getParent();
	    			if(checkNodeSelectStatus(parentNode,true))
	    			{
	    				parentNode.setParentNodeSelected(true);
	    			}
	    		}
	    	}
	    		
//	    }
	}
	
	//ͬ���ڵ�ѡ��״̬�������ӽڵ�
	public static void changeChildNodesSelectStatus(CheckNode node)
	{
		boolean parentSelectedStatus = node.isSelected();
		Enumeration<CheckNode> childNodes = node.children(); 
		while(childNodes.hasMoreElements())
		{
			childNodes.nextElement().setSelected(parentSelectedStatus);
		}
	}
	
	//��������ӽڵ��Ƿ�ȫ��Ϊ�ƶ�״̬
	public static boolean checkNodeSelectStatus(CheckNode node , boolean selected)
	{
		Enumeration<CheckNode> childNodes = node.children(); 
		while(childNodes.hasMoreElements())
		{
			if(childNodes.nextElement().isSelected() != selected)
			return false;
		}
		
		return true;
	}
	
	//��ȡ�ڵ�ȫ�ƣ��ڵ�ȫ��Ϊ ��ǰ�ڵ㸸�ڵ�����+��ǰ�ڵ�����
	public static String getNodeFullName(CheckNode node)
	{
		CheckNode parent = (CheckNode)node.getParent();
		if(parent == null)
			return node.getName();
		else
//		    return "group:"+parent.getName()+"name:"+node.getName();//"group:"+groupName+"name:"+name;
			return node.getName();
	}
	
	
}
