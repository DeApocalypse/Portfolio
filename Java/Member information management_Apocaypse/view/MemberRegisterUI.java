package view;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import service.MemberService;
import vo.MemberVO;

import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.Dialog.ModalExclusionType;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MemberRegisterUI extends JFrame {

	private JPanel contentPane;
	private JTextField txtName;
	private JTextField txtAge;
	private JTextField txtAddress;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MemberRegisterUI frame = new MemberRegisterUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public MemberRegisterUI() {
		setModalExclusionType(ModalExclusionType.APPLICATION_EXCLUDE);
		setTitle("�쉶�썝�젙蹂대벑濡�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 272, 250);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		txtName = new JTextField();
		txtName.setBounds(81, 20, 116, 21);
		contentPane.add(txtName);
		txtName.setColumns(10);
		
		txtAge = new JTextField();
		txtAge.setColumns(10);
		txtAge.setBounds(81, 59, 116, 21);
		contentPane.add(txtAge);
		
		txtAddress = new JTextField();
		txtAddress.setColumns(10);
		txtAddress.setBounds(81, 99, 116, 21);
		contentPane.add(txtAddress);
		
		JLabel lblNewLabel = new JLabel("�씠由�");
		lblNewLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNewLabel.setBounds(12, 23, 57, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("�굹�씠");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNewLabel_1.setBounds(12, 62, 57, 15);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("二쇱냼");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNewLabel_2.setBounds(12, 102, 57, 15);
		contentPane.add(lblNewLabel_2);
		
		JButton btnRegister = new JButton("�벑濡�");
		btnRegister.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(txtName.getText().length() < 1)return;
				if(txtAge.getText().length() < 1)return;
				if(txtAddress.getText().length() < 1)return;
				
				String name = txtName.getText();
				int age = Integer.parseInt(txtAge.getText());
				String address = txtAddress.getText();
				try {
					MemberService.getInstance().registerMemberVO(
							new MemberVO(name, age, address));
				} catch (Exception e1) {
					e1.printStackTrace();
				}
				dispose();
				if(MemberMainUI.getInstance() == null)
					return ;
				MemberMainUI.getInstance().setDefaultTableModel();//媛깆떊
			}
		});
		btnRegister.setBounds(12, 156, 97, 45);
		contentPane.add(btnRegister);
		
		JButton btnCancel = new JButton("痍⑥냼");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		btnCancel.setBounds(147, 156, 97, 45);
		contentPane.add(btnCancel);
	}
}
