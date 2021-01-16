package view;

import java.awt.EventQueue;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import service.MemberService;
import vo.MemberVO;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MemberMainUI extends JFrame {
	//-------------------------------------------
	private static MemberMainUI instance = null;
	private static DefaultTableModel model;
	
	public static MemberMainUI getInstance() {
		return instance;
	}
	
	public void setDefaultTableModel() {
		String[] header = {"회원명","나이","주소"};
		ArrayList<MemberVO> list = MemberService.getInstance().selectAllMemberVO();
		//회원 정보가 저장
		String[][] content = new String[list.size()][header.length];
		for(int i=0;i<list.size();i++) {
			content[i][0] = list.get(i).getName();
			content[i][1] = String.valueOf(list.get(i).getAge());
			content[i][2] = list.get(i).getAddress();
		}
		model = new DefaultTableModel(content, header);
		table.setModel(model);//다시 목록을 갱신
	}	
	//--------------------------------------------
	private JPanel contentPane;
	private JTable table;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MemberMainUI frame = new MemberMainUI();
					instance = frame;
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
	public MemberMainUI() {
		setTitle("회원정보관리 프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 759, 552);
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu mnNewMenu_3 = new JMenu("추가");
		menuBar.add(mnNewMenu_3);
		
		JMenuItem menuRegister = new JMenuItem("회원정보등록");
		menuRegister.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MemberRegisterUI memberRegisterUI = new MemberRegisterUI();
				memberRegisterUI.show();
			}
		});
		
		mnNewMenu_3.add(menuRegister);
		
		JMenu mnNewMenu = new JMenu("조회");
		menuBar.add(mnNewMenu);
		
		JMenuItem menuSearch = new JMenuItem("회원정보검색");
		menuSearch.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MemberSearchUI memberSearchUI = new MemberSearchUI();
				memberSearchUI.show();
			}
		});
		
		mnNewMenu.add(menuSearch);
		
		JMenu mnNewMenu_1 = new JMenu("삭제");
		menuBar.add(mnNewMenu_1);
		
		JMenuItem memberDelete = new JMenuItem("회원정보삭제");
		memberDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String name = (String) table.getValueAt(table.getSelectedRow(), 0);
				try {
					MemberService.getInstance().deleteMemberVO(name);
					setDefaultTableModel();//갱신
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
		
		mnNewMenu_1.add(memberDelete);
		
		JMenu mnNewMenu_2 = new JMenu("종료");
		mnNewMenu_2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.out.println("프로그램 종료");
				System.exit(0);
			}
		});
		menuBar.add(mnNewMenu_2);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(12, 10, 691, 373);
		contentPane.add(scrollPane);
		
		table = new JTable();
		table.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) {
				if(e.getKeyCode() != e.VK_ENTER) return;//엔터를 눌러야 진행
				int row = table.getSelectedRow();
				String name = (String) table.getValueAt(table.getSelectedRow(), 0);
				int age = Integer.parseInt(String.valueOf(table.getValueAt(
											table.getSelectedRow(), 1)));
				String address = (String) table.getValueAt(table.getSelectedRow(), 2);
				try {
					MemberService.getInstance().updateMemberVO(new MemberVO(name, age, address));
					setDefaultTableModel();
					table.changeSelection(row, 0, false, false);
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
		table.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.out.println("테이블 마우스 클릭 이벤트");
				System.out.println("선택한 행번호 : " + table.getSelectedRow());
				System.out.println("선택한 열번호 : " + table.getSelectedColumn());
				System.out.println("선택한 곳 데이터 : "+table.getValueAt(
						table.getSelectedRow(), table.getSelectedColumn()));
			}
		});
		scrollPane.setViewportView(table);
		
		
		
		
		JButton btnExit = new JButton("프로그램 종료");
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println("프로그램을 종료합니다.");
				System.exit(0);
			}
		});
		btnExit.setBounds(554, 393, 149, 50);
		contentPane.add(btnExit);
		
		JButton btnDelete = new JButton("회원정보삭제");
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String name = (String) table.getValueAt(table.getSelectedRow(), 0);
				try {
					MemberService.getInstance().deleteMemberVO(name);
					setDefaultTableModel();//갱신
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
		btnDelete.setBounds(393, 393, 149, 50);
		contentPane.add(btnDelete);
		
		JButton btnRegister = new JButton("회원정보추가");
		btnRegister.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MemberRegisterUI registerUI = new MemberRegisterUI();
				registerUI.show();
			}
		});
		btnRegister.setBounds(232, 393, 149, 50);
		contentPane.add(btnRegister);
		setDefaultTableModel();
	}

	public void changeSelectRow(int no) {
		table.changeSelection(no, 0, false, false);		
	}
}
