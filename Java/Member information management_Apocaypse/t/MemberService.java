package service;
/*
 * ArrayList
 * 추가  :  registerMemberVO(MemberVO) - void
 * 삭제   :  deleteMemberVO(String name) - void
 * 검색   :  searchMemberVO(String name) - MemberVO
 * 수정   :  updateMemberVO(MemberVO) - void
 * 전체선택 : selectAllMemberVO() - ArrayList<MemberVO>
 */

import java.util.ArrayList;

import vo.MemberVO;

public class MemberService {
	private ArrayList<MemberVO> list;
	private static MemberService instance = new MemberService();
	
	private MemberService() {
		list = new ArrayList<MemberVO>();
		list.add(new MemberVO("홍길동", 20, "서울"));
		list.add(new MemberVO("김철수", 32, "인천"));
		list.add(new MemberVO("길동수", 15, "광주"));
		list.add(new MemberVO("이근", 54, "부산"));
		list.add(new MemberVO("박철우", 42, "대구"));
		list.add(new MemberVO("장삐쭈", 67, "울산"));
	}
	
	public static MemberService getInstance() {
		if(instance == null)
			instance = new MemberService();
		return instance;
	}

	public void registerMemberVO(MemberVO vo) throws Exception {
		for(int i=0;i<list.size();i++){
			if(list.get(i).equals(vo))
				throw new Exception("");
		}
		list.add(vo);
	}
	
	public void deleteMemberVO(String name) throws Exception {
		for(int i=0;i<list.size();i++){
			if(list.get(i).getName().equals(name)) {
				list.remove(i);
				return ;
			}		
		}
		throw new Exception("");
	}
	
	public void updateMemberVO(MemberVO vo) throws Exception {
		for(int i=0;i<list.size();i++){
			if(list.get(i).equals(vo)) {
				list.get(i).setAddress(vo.getAddress());
				list.get(i).setAge(vo.getAge());
				return;
			}
		}
		throw new Exception("");
	}
	public int searchMemberVO(String name) {
		for(int i=0;i<list.size();i++){
			if(list.get(i).getName().equals(name)) {
				return i;
			}
		}
		return -1;
	}
	public ArrayList<MemberVO> selectAllMemberVO(){
		return list;
	}
}
