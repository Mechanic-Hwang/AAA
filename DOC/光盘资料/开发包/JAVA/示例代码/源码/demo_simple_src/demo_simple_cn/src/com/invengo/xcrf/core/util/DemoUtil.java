package com.invengo.xcrf.core.util;

import gnu.io.CommPortIdentifier;

import java.awt.Dimension;
import java.awt.Graphics;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Enumeration;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JComponent;

import org.apache.commons.logging.Log;

import com.invengo.xcrf.core.i18n.BaseMessages;
import com.invengo.xcrf.ui.dialog.panel.ICallBack;

/**
 * ��ʾ���򹤾���
 * 
 * @author zxl672
 * 
 */
public class DemoUtil {

    public static final String hexlimit = "[a-fA-F0-9]";

    private static SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS");

    public final static String[] getCommPorts() {
        Enumeration<?> list = CommPortIdentifier.getPortIdentifiers();
        List<String> commList = new ArrayList<String>();
        while (list.hasMoreElements()) {
            CommPortIdentifier myport = (CommPortIdentifier) list.nextElement();
            int type = myport.getPortType();
            String port = myport.getName();
            if (type == 1) {
                commList.add(port);
            }
        }
        String[] myports = new String[commList.size()];
        commList.toArray(myports);
        return myports;
    }

    /**
     * * �ж��Ƿ�Ϊ�Ϸ�IP *
     * 
     * @return the ip
     */
    public static boolean isboolIp(String ipAddress) {
        String ip = "([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}";
        Pattern pattern = Pattern.compile(ip);
        Matcher matcher = pattern.matcher(ipAddress);
        return matcher.matches();
    }

    /**
     * ��ʽ������ �����뼶��
     * 
     * @return
     */
    public static String getNowDate() {
        return df.format(new Date());
    }

    /**
     * ��ʽ������ �����뼶��
     * 
     * @return
     */
    public static String getDatef(Date date) {
        return df.format(date);
    }

    /**
     * ��Ⱦ����
     * 
     * @param g
     * @param jPanel
     * @param imagePath
     */
    public static void paintComponentUtil(Graphics g, JComponent jPanel, URL imagePath) {
        ImageIcon image = new ImageIcon(imagePath);

        jPanel.setOpaque(false);
        Dimension d = jPanel.getSize();

        // ������Ⱦ
        for (int x = 0; x < d.width; x += image.getIconWidth()) {
            g.drawImage(image.getImage(), x, 0, null, null);
        }
    }

    /**
     * ת����ǩid
     * 
     * @param id
     * @return
     */
    public static String idToString(byte[] id) {
        StringBuffer myid = new StringBuffer();

        // ���������ֽ�����
        for (int i = 3; i < id.length; i++) {
            String temp = Integer.toHexString(0x000000FF & id[i]);
            if (temp.length() == 1) {
                temp = "0" + temp;
            }
            myid.append(temp);
        }
        return myid.toString();
    }

    public static String generalIdToSting(byte[] id) {

        StringBuffer myid = new StringBuffer();

        // ���������ֽ�����
        for (int i = 0; i < id.length; i++) {
            String temp = Integer.toHexString(0x000000FF & id[i]);
            if (temp.length() == 1) {
                temp = "0" + temp;
            }
            myid.append(temp);
        }
        return myid.toString();

    }

    /**
     * ת��״̬��
     * 
     * @param status
     * @return
     */
    public static String tranWord(int status) {
        if (status == 0) {
            return null;
        }

        if (status == 0x60) {
            return "��ǩ����Ӧ�򲻴���";
        }

        if (status == 0x25) {
            return "���ݸ�ʽ����";
        }

        return "δ֪����";
    }

    /**
     * ת��ǩid
     * 
     * @param id
     * @param begin
     * @return
     */
    public static String idToString(byte[] id, int begin) {
        StringBuffer myid = new StringBuffer();

        for (int i = begin; i < id.length; i++) {
            String temp = Integer.toHexString(0x000000FF & id[i]);

            if (temp.length() == 1) {
                temp = "0" + temp;
            }

            myid.append(temp);
        }

        return myid.toString();
    }

    /**
     * ͳ��һ����ǩʹ�õ���ʱ��
     * 
     * @param id
     * @param time
     * @param map
     * @return
     */
    public static long totalTime(String id, long time, Map<String, Long> map) {
        long mytotaltime = 0;

        Long totaltime = map.get(id);
        if (totaltime != null) {
            mytotaltime = totaltime.longValue();
        }

        mytotaltime = mytotaltime + time;
        map.put(id, mytotaltime);

        return mytotaltime;
    }

    /**
     * ���ַ�����ʽTIDת�����ֽ�����
     * 
     * @param tidString
     * @return
     */
    public static byte[] idToByte(String tidString) {
        int tidStringleng = tidString.length();
        byte[] tid = new byte[tidString.length() / 2];
        for (int i = 0; i < tidStringleng / 2; i++) {
            String temp = tidString.substring(0, 2);
            tidString = tidString.substring(2, tidString.length());
            tid[i] = (byte) Integer.parseInt(temp, 16);
        }
        return tid;
    }

    public static int[] idToInt(String tidString) {
        int tidStringleng = tidString.length();
        int[] tid = new int[tidString.length() / 2];
        for (int i = 0; i < tidStringleng / 2; i++) {
            String temp = tidString.substring(0, 2);
            tidString = tidString.substring(2, tidString.length());
            tid[i] = Integer.parseInt(temp, 16);
        }
        return tid;
    }

    public static URL getResource(String path) {
        return ICallBack.class.getResource(path);
    }

    /**
     * ��¼�쳣��ϸ��Ϣ
     * 
     * @param log
     * @param e
     */
    public static void logException(Log log, Exception e) {
        StringWriter mystring = new StringWriter();
        e.printStackTrace(new PrintWriter(mystring));
        log.info(mystring);
    }

    /**
     * �ж�һ���ַ����Ƿ��з�16�����ַ� �� true �� false
     * 
     * @param mytemp
     * @return
     */
    public static boolean haveNotHex(String mytemp) {
        String[] rg = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e",
                "f", "A", "B", "C", "D", "E", "F" };

        for (int j = 0; j < mytemp.length(); j++) {
            String tempbyte = mytemp.substring(j, j + 1);
            boolean rgbl = false;
            for (int i = 0; i < rg.length; i++) {
                if (tempbyte.equals(rg[i])) {
                    rgbl = true;
                }
            }
            if (rgbl == false) {
                return true;
            }
        }
        return false;
    }

    /**
     * ���ַ���ǰ��0
     * 
     * @param mystring
     * @param length
     * @return
     */
    public static String preAddZero(String mystring, int length) {
        int zerolength = length - mystring.length();
        for (int i = 0; i < zerolength; i++) {
            mystring = "0" + mystring;
        }
        return mystring;
    }

    /**
     * ���ַ������0
     * 
     * @param mystring
     * @param length
     * @return
     */
    public static String endAddZero(String mystring, int length) {
        int zerolength = length - mystring.length();
        for (int i = 0; i < zerolength; i++) {
            mystring = mystring + "0";
        }
        return mystring;
    }

    /**
     * ���ַ������f
     * 
     * @param mystring
     * @param length
     * @return
     */
    public static String endAddF(String mystring, int length) {
        int zerolength = length - mystring.length();
        for (int i = 0; i < zerolength; i++) {
            mystring = mystring + "f";
        }
        return mystring;
    }

    /**
     * ����ָ�����ȵ����16��������
     * 
     * @param length
     * @return
     */
    public static String createData(int length) {
        String[] rg = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e",
                "f", "A", "B", "C", "D", "E", "F" };
        StringBuffer mystring = new StringBuffer();
        for (int i = 0; i < length; i++) {
            Random random = new Random();
            int index = random.nextInt(rg.length);
            mystring.append(rg[index]);
        }
        return mystring.toString();
    }

    /**
     * ��ѡ�������ѡ����
     * 
     * @param ioJComboBox
     * @param key
     */
    public static void addItems(JComboBox ioJComboBox, String key) {
        ioJComboBox.removeAllItems();
        String item = BaseMessages.getString(key);
        String[] myitems = item.split("\\|");
        for (int i = 0; i < myitems.length; i++) {
            ioJComboBox.addItem(myitems[i]);
        }
    }

    public static void main(String[] args) {
        String[] myports = DemoUtil.getCommPorts();
        for (int i = 0; i < myports.length; i++) {
            System.out.println(myports[i]);
        }
    }
}
