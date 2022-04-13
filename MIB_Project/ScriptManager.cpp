#include "pch.h"

ScriptManager::ScriptManager()
{
	m_Index = 0;
}

ScriptManager::~ScriptManager()
{

}

void ScriptManager::Init()
{
#pragma region 스크립트
#pragma region Intro
	//1
	m_Index = (int)SCR_ID::STORY_INTRO_1;
	std::vector<Script> scr;
	scr.push_back({ "[ppppp-]", SCR_COLOR::GREY });
	scr.push_back({ "예, 상무님." });
	scr.push_back({ "[너 지금 어디냐?]", SCR_COLOR::GREY });
	scr.push_back({ "말씀하신 곳에 도착했습니다. 내일 작업 준비하고 자려는 참입니다." });
	scr.push_back({ "[아침부터 중요한 일이니, 실수 마라. 너 승진하고 싶다며?]", SCR_COLOR::GREY });
	scr.push_back({ "아… 넷! 최선을 다하겠습니다!!" });
	scr.push_back({ "[복장 유지하는 거 잊지 마라. 그럼 끊는다.]", SCR_COLOR::GREY });
	scr.push_back({ "[삑-.]", SCR_COLOR::GREY });
	Add(scr);

	//2
	scr.push_back({ "진짜 시골 구석이네. 도착하니 벌써 밤이군." });
	scr.push_back({ "얼른 방에 들어가 쉬어야 겠는데." });
	scr.push_back({ "내가 머물 곳이 303호라고 했었지?" });
	scr.push_back({ "303호로 가자." });
	Add(scr);

	//3
	scr.push_back({ "전등 스위치를 껐다.", SCR_COLOR::GREY });
	scr.push_back({ "아침부터 중요한 일이라고 정장을 벗지 말라니. 참나." });
	scr.push_back({ "휴. 일단 눈 좀 붙일까…" });
	Add(scr);

	//4
	scr.push_back({ "소름끼치는 소리가 들린다...", SCR_COLOR::GREY });
	scr.push_back({ "젠장, 이게 무슨 소리야?" });
	Add(scr);
#pragma endregion

#pragma region Story_1
	//1
	m_Index = (int)SCR_ID::STORY_1_1;
	scr.push_back({ "밖에서 난 소리같은데... 나가서 확인해봐야겠어." });
	Add(scr);

	//2
	scr.push_back({ "뭔가 걸린 것 같은데..." });
	scr.push_back({ "문을 열 만한 도구를 찾아봐야겠어." });
	Add(scr);

	//3
	scr.push_back({ "빠루를 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "좋아, 이거면 되겠지. 챙겨오길 잘했어." });
	Add(scr);

	//4
	scr.push_back({ "하나...둘..." });
	scr.push_back({ "셋!!!" });
	scr.push_back({ "좋아, 열렸다!" });
	scr.push_back({ "이거 한번했다고 부러지다니…. 중국산이 뭐 어쩌겠어." });
	scr.push_back({ "망가진 빠루를 버렸다.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_2
	//1
	m_Index = (int)SCR_ID::STORY_2_1;
	scr.push_back({ "대체 뭐가 걸려 있던 거야?" });
	scr.push_back({ "!!!!!" });
	scr.push_back({ "윽… 이런… 시체였어?" });
	scr.push_back({ "..." });
	scr.push_back({ "젠장, 뭐가 어떻게 돌아가는 거야... 일단 전화로 알려야는데… 왜 신호는 또 안 잡혀?" });
	scr.push_back({ "할 수 없지. 일단 비상구로 가자." });
	Add(scr);

	//2
	scr.push_back({ "뭐야 이건 또 왜 이래? 안 열리잖아?" });
	scr.push_back({ "!!!!!" });
	scr.push_back({ "제길, 일단 방으로 도망가야겠어!" });
	scr.push_back({ "문이 열린 방을 찾아야 한다!", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_3
	//1
	m_Index = (int)SCR_ID::STORY_3_1;
	scr.push_back({ "방문을 세차게 닫았다.", SCR_COLOR::GREY });
	scr.push_back({ "헉...헉..." });
	scr.push_back({ "소리가 멀어졌다.", SCR_COLOR::GREY });
	scr.push_back({ "방까지는 못 들어오나 본데... 뭐가 저렇게 빨라?" });
	scr.push_back({ "윽... 여기에도 시체가..." });
	Add(scr);

	//2
	scr.push_back({ "열쇠 꾸러미를 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "이 양반은… 경비원인거 같은데  어쩌다가…" });
	scr.push_back({ "근데....왜 속옷에 열쇠를 달고 있는 거지??" });
	Add(scr);

	//3
	scr.push_back({ "이 열쇠 중에 맞는 게 이건가?" });
	scr.push_back({ "열쇠 꾸러미를 사용했다.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_4
	//1
	m_Index = (int)SCR_ID::STORY_4_1;
	scr.push_back({ "후… 아… 여기도 사람이 죽었잖아?" });
	Add(scr);

	//2
	scr.push_back({ "작은 쪽지가 있다… 유서를 남겨놓은 모양이다.", SCR_COLOR::GREY });
	scr.push_back({ "<나는 정화되었다. 이제 그분을 뵐 준비가 됐다.",SCR_COLOR::RED });
	scr.push_back({ "이 열쇠로 열 것이다.이 머리의 창문, 창문을…>",SCR_COLOR::RED });
	scr.push_back({ "흠... 열쇠? 이 머리에 꽂힌 칼이... 열쇠라는 건가?" });
	Add(scr);

	//3
	scr.push_back({ "칼을 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "날이 상해서 괴물에게 쓰긴 어렵겠지만, 어디 쓸 곳은 있겠지." });
	Add(scr);

	//4
	scr.push_back({ "방 주인의 컴퓨터다." });
	scr.push_back({ "뭔가 찍어 놓은 게 있는 거 같은데." });
	scr.push_back({ "작업 노트에는 아직 업로드 할 게 있다고 돼 있어." });
	scr.push_back({ "<3만 구독자 기념 스티커> 가 있다." });
	scr.push_back({ "이 사람, 스트리머였나 보군." });
	Add(scr);

	//5
	scr.push_back({ "SD 카드를 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "[중대 촬영본]… 이 메모리 칩을 컴퓨터로 열어보면 뭐가 있지 않을까?" });
	Add(scr);

	//6
	scr.push_back({ "SD 카드를 사용했다.", SCR_COLOR::GREY });
	scr.push_back({ "촬영일자: XX년 XX월 X3일 AM 02 : 44" });
	scr.push_back({ "\"쉿! 단독공개! 최초공개! 사이비 교단의 비밀 장소를 찾았어!\"" });
	scr.push_back({ "\"지금 여기는 XX동 지하 원룸텔 복도 장롱이고… 앗!저기 사람 온다.조용!\"" });
	scr.push_back({ "\"비명 들려? 사이비 신도들이 천에 사람을 넣어 끌고 가고 있어. 저기는 301호 같은데?\"" });
	scr.push_back({ "\"헐 3중 자물쇠도 걸려있어...열쇠는...소화전에 보관을 하나봐...\"" });
	scr.push_back({ "\"저 사람들 떠나면 소화전에 가서 저걸…. 앗! 당신들 뭐야 (격렬히 돌아가는 카메라 렌즈)(소음)\"" });
	scr.push_back({ "영상종료", SCR_COLOR::GREY });
	scr.push_back({ "소화전에… 301호와 관련된 게 있다는 건가." });
	scr.push_back({ "소화전으로 가보자." });
	Add(scr);
#pragma endregion

#pragma region Story_5
	//1
	m_Index = (int)SCR_ID::STORY_5_1;
	scr.push_back({ "소화전을 열었다.", SCR_COLOR::GREY });
	scr.push_back({ "이게 영상에서 나온 소화전이군." });
	scr.push_back({ "어디 확인해 볼까?" });
	Add(scr);

	//2
	scr.push_back({ "꽤 깊이 넣은 거 같은데… 응?" });
	scr.push_back({ "이 뼈다귀가 열쇠…?" });
	scr.push_back({ "뼈 열쇠를 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "... 301호로 가보자." });
	Add(scr);

	//3
	scr.push_back({ "어디보자. 뭔 자물쇠가 이렇게 많아?" });
	scr.push_back({ "첫 번째 자물쇠를 풀었다.", SCR_COLOR::GREY });
	Add(scr);

	//4
	scr.push_back({ "두 번째 자물쇠를 풀었다.", SCR_COLOR::GREY });
	scr.push_back({ "이제 하나 남았다..." });
	Add(scr);

	//5
	scr.push_back({ "마지막 자물쇠는 녹이 슬었나, 왜 이렇게 뻑뻑해?" });
	Add(scr);

	//6
	scr.push_back({ "!!!!!" });
	scr.push_back({ "윽, 또 저, 저 놈이야?" });
	scr.push_back({ "열려라, 제발...!!! 빨리!!" });
	scr.push_back({ "조금만 더 해보면 열릴 거 같은데...!", SCR_COLOR::GREY });
	scr.push_back({ "문 빨리 열기 [스페이스 연타]", SCR_COLOR::GREY });
	Add(scr);

	//7
	scr.push_back({ "돌아간다... 제발... 조금만 더!!!" });
	Add(scr);

	//8
	scr.push_back({ "문 빨리 열기 [스페이스 연타]", SCR_COLOR::GREY });
	Add(scr);

	//9
	scr.push_back({ "마지막 자물쇠를 풀었다.", SCR_COLOR::GREY });
	scr.push_back({ "됐다!!" });
	Add(scr);
#pragma endregion

#pragma region Story_6
	//1
	m_Index = (int)SCR_ID::STORY_6_1;
	scr.push_back({ "교단의 부적… 글귀가 있군." });
	scr.push_back({ "\"선택 받은 자의 영역에 닿으려는 추종자들은 볼 지어다." });
	scr.push_back({ "진리를 가로막는 장벽은 만물의 정수에 젖는 순간 무너지리라.\"" });
	scr.push_back({ "만물의 정수라......" });
	Add(scr);

	//2
	scr.push_back({ "빈 양동이를 얻었다." , SCR_COLOR::GREY });
	scr.push_back({ "이 양동이는 뭔가 쓸모가 있을 거 같은데." });
	Add(scr);

	//3
	scr.push_back({ "물이 든 양동이를 얻었다.", SCR_COLOR::GREY });
	scr.push_back({ "만물의 정수라면 물이 아닐까?" });
	scr.push_back({ "근데 가만… 왜 물에서 피냄새가 나지? 색깔도…" });
	Add(scr);

	//4
	scr.push_back({ "부적에 물이 든 양동이를 사용했다." , SCR_COLOR::GREY });
	scr.push_back({ "이 물이 답을 알고 있나… 어디 보자고." });
	Add(scr);

	//5
	scr.push_back({ "부적들이 녹아내리며 숨겨진 문이 드러났다.", SCR_COLOR::GREY });
	scr.push_back({ "빙고. … 이거 정말 피인가" });
	Add(scr);
#pragma endregion

#pragma region Story_7
	//1
	m_Index = (int)SCR_ID::STORY_7_1;
	scr.push_back({ "곰팡이 냄새, 그을음 냄새에 피 냄새까지…" });
	scr.push_back({ "정말 악몽에서나 나올 장소로군." });
	Add(scr);

	//2
	scr.push_back({ "이렇게 비좁은 황풍구로 괴물이 나온건가?" });
	Add(scr);

	//3
	scr.push_back({ "제단 위에 급하게 휘갈겨 쓴 메모가 있다." });
	scr.push_back({ "<<이번에도 선택 받은 자는 오지 않았다. 또 실패작이 나와버렸다…",SCR_COLOR::RED });
	scr.push_back({ "놈의 탈출을 막는 봉인을 여기 남겼으니,",SCR_COLOR::RED });
	scr.push_back({ "신계의 창을 여는 열쇠, 그 열쇠의 칼날에 봉인이 풀릴 지어다.>>",SCR_COLOR::RED });
	scr.push_back({ "봉인을 푸는 열쇠의 칼날? 그거라면…" });
	Add(scr);

	//4
	scr.push_back({ "칼을 제단에 꽂았다.",SCR_COLOR::GREY });
	scr.push_back({ "<<봉인이 끊어지고, 만물이 혼돈으로 향한다.",SCR_COLOR::RED });
	scr.push_back({ "실패작을 정화할 그 분의 빛이 닿기 전에… 보고 듣을 수 있는 자, 벗어나라.>>" ,SCR_COLOR::RED });
	Add(scr);

	//5
	scr.push_back({ "복도 끝에서 문 소리가 났다.",SCR_COLOR::GREY });	//★수정 요청
	scr.push_back({ "!!!" });
	scr.push_back({ "이 괴물자식이… 끝까지!" });
	Add(scr);

	//6
	scr.push_back({ "자, 이제 작별이다." });
	scr.push_back({ "비상구가 열렸다.", SCR_COLOR::GREY });
	Add(scr);
#pragma endregion

#pragma region Story_End
	m_Index = (int)SCR_ID::STORY_END_1;
	scr.push_back({ "비상구 문을 여는 순간, 등 뒤로 강렬한 불빛이 새어 나왔다.", SCR_COLOR::GREY });
	scr.push_back({ "그와 함께 괴물의 비명은 반대로 사그러들었고… 바깥의 빗소리만 강하게 들렸다.", SCR_COLOR::GREY });
	scr.push_back({ "[ppppp-]", SCR_COLOR::GREY });
	scr.push_back({ "헉헉... 네, 상무님!" });
	scr.push_back({ "너 일어났나 확인하러 전화… 왜 그렇게 헐떡거려?", SCR_COLOR::GREY });
	scr.push_back({ "… 조금 바쁜 일이 있었습니다. 자세한 건…" });
	scr.push_back({ "...", SCR_COLOR::GREY });
	scr.push_back({ "..." });
	scr.push_back({ "…확실하게 처리했냐?", SCR_COLOR::GREY });
	scr.push_back({ "메뉴얼대로 처리했습니다만… 놈이 예상보다 너무 빨리 설쳐서 죽을 뻔 했습니다." });
	scr.push_back({ "실패작들이 다 그렇지… 하지만 진짜 선택 받은 그분께서 오신다면…", SCR_COLOR::GREY });
	scr.push_back({ "그렇게 된다면야 저희 하급 관리직들도 빛을 보지 않겠습니까, 하하." });
	scr.push_back({ "거긴 교단 사제들에 맡기고 원래 가려던 시설로 가도록 해. 그럼.", SCR_COLOR::GREY });
	scr.push_back({ "넷! 알겠습니...!" });
	scr.push_back({ "[삑-.]", SCR_COLOR::GREY });
	scr.push_back({ "쳇. 바로 끊어버리기는…" });
	scr.push_back({ "그럼... 가 볼까?" });
	scr.push_back({ "거기에.", SCR_COLOR::RED });
	Add(scr);

	scr.push_back({ "[기획] 김규현 & 김찬영" });
	scr.push_back({ "[아트] 강혜정 & 최윤정" });
	scr.push_back({ "[프로그래밍] 임효빈 & 최민경" });
	scr.push_back({ "[Team - MILKTEA]" });
	scr.push_back({ "플레이 해주셔서 감사합니다." });
	Add(scr);
#pragma endregion

#pragma region 상호작용
	m_Index = (int)SCR_ID::INTER_BOOK;
	scr.push_back({ "경비일지가 있다.", SCR_COLOR::GREY });
	scr.push_back({ "『경비일지』" });
	scr.push_back({ "XX년XX월X1일.이상 무." });
	scr.push_back({ "XX년XX월X2일.이상 무, 하지만 뭔가 느낌이 이상하다." });
	scr.push_back({ "XX년XX월X3일.이상 무, 무언가 지켜보는 느낌이 든다." });
	scr.push_back({ "XX년XX월X4일.비가 많이 내려서 수로를 팠다.여전히 누군가 지켜보는 느낌이 든다." });
	scr.push_back({ "XX년XX월X2일, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무," });
	scr.push_back({ "이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무," });
	scr.push_back({ "이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무," });
	scr.push_back({ "이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무," });
	scr.push_back({ "이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무," });
	scr.push_back({ "이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무, 이상 무." });
	scr.push_back({ "XX년 XX월 X1일. 선택받은 자가 나타나면, 그분께서 돌아오시리라.", SCR_COLOR::RED });
	Add(scr);

	m_Index = (int)SCR_ID::INTER_BOARD;
	scr.push_back({ "...\"[밀크티 제조법]" });
	scr.push_back({ "1. 팬에 물 약 80-100ml를 넣고 끓인다." });
	scr.push_back({ "2. 물이 끓으면 홍찻잎을 적당량(4-6g) 넣는다." });
	scr.push_back({ "3. 2-3분 후 차가 우러나오면 우유 80-200ml를 넣고 약불로 천천히 데운다." });
	scr.push_back({ "4. 홍차가 따뜻해지면 우유가 끓기 전에 불을 끄고 찻잎을 걸러서 완성." });
	scr.push_back({ "[By Team_MilkTea]\"..." });
	scr.push_back({ "...이게 뭐야?" });
	Add(scr);
#pragma endregion

#pragma region Event
	//1
	m_Index = (int)SCR_ID::EVENT_MESSAGE_1;
	scr.push_back({ "일단 비상구부터 가는 게 먼저야." });
	Add(scr);

	//2
	scr.push_back({ "열리지 않는다." });
	Add(scr);

	//3
	scr.push_back({ "젠장...! 여긴 또 왜...! 억지로 열면서 고장났나...!?" });
	Add(scr);

	//4
	scr.push_back({ "문이 완전히 고장났어." });
	scr.push_back({ "아무래도 다시 들어갈 수는 없을 것 같군..." });
	Add(scr);
#pragma endregion


#pragma region 기본 메세지
	//1
	m_Index = (int)SCR_ID::NORMAL_1;
	scr.push_back({ "문을 열 만한게 필요해." });
	Add(scr);

	//2
	scr.push_back({ "딱히 쓸 만한 게 없어." });
	Add(scr);

	//3
	scr.push_back({ "여기에 사용할 수 없어." });
	Add(scr);

	//4
	scr.push_back({ "여기서 더 할 일은 없어." });
	Add(scr);

	//5
	scr.push_back({ "화장실 냄새 한번 끔찍하군. 밖에 비까지 내리니 완전…" });
	Add(scr);

	//DebugMode
	scr.push_back({ "[Debug Cheat Mode]" });
	Add(scr);
#pragma endregion
#pragma endregion

#pragma region 정보
	LPCSTR info[] =
	{
		"가방 조사하기 [스페이스 바]",
		"목 매달린 시체 조사하기 [스페이스 바]",
		"일지 조사하기 [스페이스 바]",
		"무릎 꿇은 시체 조사하기 [스페이스 바]",
		"촬영 장비 조사하기 [스페이스 바]",
		"컴퓨터 조사하기 [스페이스 바]",
		"소화전 조사하기 [스페이스바]",
		"부적 조사하기 [스페이스 바]",
		"빈 양동이 조사하기 [스페이스 바]",
		"화장실 조사하기 [스페이스 바]",
		"제단 조사하기 [스페이스 바]",
		"환풍구 조사하기 [스페이스 바]",
		"게시판 조사하기 [스페이스 바]",

		"스위치 상호작용 [스페이스 바]",
		"잠긴 문 상호작용 [스페이스 바]",
		"잠긴 비상구 상호작용 [스페이스 바]",
		"컴퓨터 상호작용 [스페이스 바]",
		"화장실 상호작용 [스페이스 바]",
		"제단 상호작용 [스페이스 바]",

		"복도로 이동 [스페이스 바]",
		"301호로 이동 [스페이스 바]",
		"302호로 이동 [스페이스 바]",
		"303호로 이동 [스페이스 바]",
		"304호로 이동 [스페이스 바]",
		"비밀의 방으로 이동 [스페이스 바]",
		"비상구 탈출 [스페이스 바]",
	};

	for (int i = 0; i < (int)INFO_ID::INFONUM; i++)
	{
		m_Info[i] = info[i];
	}
#pragma endregion
}

void ScriptManager::Add(std::vector<Script>& scr)
{
	if (m_Index >= (int)SCR_ID::IDNUM) return;

	m_Scripts[m_Index++] = scr;
	scr.clear();
}

void ScriptManager::AddScripts(std::vector<Script>& user, SCR_ID id)
{
	std::vector<Script> Scr = m_Scripts[(int)id];
	int size = Scr.size();
	for (int i = 0; i < size; i++)
	{
		user.push_back(Scr[size - 1 - i]);
	}
}

void ScriptManager::AddInfo(LPCSTR& user, INFO_ID id)
{
	user = m_Info[(int)id];
}