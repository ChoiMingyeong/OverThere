#pragma once

enum class BG
{
	HALLWAY,		// ����
	ROOM301,		// 301ȣ
	ROOM302,		// 302ȣ
	ROOM303,		// 303ȣ(������ġ)
	ROOM304,		// 304ȣ
	SECRETROOM,		// ��й�

	TITLE,            // Ÿ��Ʋ
	GAMEOVER,			//���ӿ���
	ENDING,            // ����
	ENDING2,            // ����

	INTROHALL,            // ��Ʈ�� ����
	INTRO303,            // ��Ʈ��

	BGNUM
};

enum class OBJ
{
	BUCKET,		// �絿��
	CHARM,		// ����
	HANGDEAD,	// �� �޴� ��ü
	BOOK,		// å(å�� ��)
	SWITCH,		// ���� ����ġ
	BAG,		// ����
	DEADBODY,	// ��ü(Į)
	NOTEBOOK,	// å��(��ǻ��)
	CAMERA,		// �Կ����
	ALTAR,		// ���
	TOILET,		// ȭ���
	FIREHYDRANT,	// ��ȭ��
	BOARD,		//�Խ���
	MAGICCIRCLE,      //������
	CANDLE_FIRE_L,      //�к� ����
	CANDLE_FIRE_R,      //�к� ������
	VENT,   //ȯǳ��


	DOOR,         // ������(����)
	DOOR301,      // 301ȣ ��
	DOOR302,      // 302ȣ ��
	DOOR303,      // 303ȣ ��
	DOOR304,      // 304ȣ ��
	SECRETDOOR,   // ��� ��
	ESCAPE,       // Ż�ⱸ

	INTRO303,       // ��Ʈ��

	OBJNUM
};

enum class UI
{
	TITLE_START,	//Ÿ��Ʋ ���ӽ���
	TITLE_EXIT,		//Ÿ��Ʋ ��������
	TITLE_ARROW,	//Ÿ��Ʋ ȭ��ǥ

	INVEN_SLOTS,	//�κ��丮
	INVEN_ARROW,	//�κ��丮 ȭ��ǥ

	ITEM_CROWBAR,	//������ ����
	ITEM_SDCARD,	//������ SD ī��
	ITEM_KNIFE,		//������ Į
	ITEM_KEYSET,	//������ ����ٷ���
	ITEM_BUCKET,	//������ �絿��
	ITEM_BONEKEY,	//������ �� ����

	UINUM
};

enum class PLAYER
{
	IDLE_L,
	IDLE_R,
	RUN_L,
	RUN_R,

	STATENUM
};

enum class MONSTER
{
	RUN_L,
	RUN_R,

	STATENUM
};

enum class SCENE
{
	TITLE,		// Ÿ��Ʋ ��
	INTRO,		// ��Ʈ�� ��
	INGAME,		// �ΰ��� ��
	GAMEOVER,	// ���ӿ��� ��
	ENDING,		// ���� ��

	SCENENUM
};

enum class ROOM
{
	HALLWAY,		// ����
	ROOM301,		// 301ȣ
	ROOM302,		// 302ȣ
	ROOM303,		// 303ȣ(������ġ)
	ROOM304,		// 304ȣ
	SECRETROOM,		// ��й�

	INTRO_HALLWAY = 10,// ��Ʈ�� ����
	INTRO_303,		// ��Ʈ�� 303

	ROOMNUM = SECRETROOM + 2
};

enum class SCR_COLOR
{
	WHITE,
	GREY,
	RED,
	GREEN,

	COLORNUM
};

enum class SCR_ID
{
	STORY_INTRO_1,
	STORY_INTRO_2,
	STORY_INTRO_3,
	STORY_INTRO_4,

	STORY_1_1,
	STORY_1_2,
	STORY_1_3,
	STORY_1_4,

	STORY_2_1,
	STORY_2_2,

	STORY_3_1,
	STORY_3_2,
	STORY_3_3,

	STORY_4_1,
	STORY_4_2,
	STORY_4_3,
	STORY_4_4,
	STORY_4_5,
	STORY_4_6,

	STORY_5_1,
	STORY_5_2,
	STORY_5_3,
	STORY_5_4,
	STORY_5_5,
	STORY_5_6,
	STORY_5_7,
	STORY_5_8,
	STORY_5_9,

	STORY_6_1,
	STORY_6_2,
	STORY_6_3,
	STORY_6_4,
	STORY_6_5,

	STORY_7_1,
	STORY_7_2,
	STORY_7_3,
	STORY_7_4,
	STORY_7_5,
	STORY_7_6,

	STORY_END_1,
	STORY_END_STAFF,

	INTER_BOOK,
	INTER_BOARD,

	EVENT_MESSAGE_1,
	EVENT_MESSAGE_2,
	EVENT_MESSAGE_3,
	EVENT_MESSAGE_4,
	EVENT_MESSAGE_5,

	DEBUG,

	NORMAL_1,
	NORMAL_2,
	NORMAL_3,
	NORMAL_4,
	NORMAL_5,

	IDNUM
};

enum class INFO_ID
{
	SEARCH_BAG,
	SEARCH_HANGDEAD,
	SEARCH_DIARY,
	SEARCH_DEADGIRL,
	SEARCH_CAMERA,
	SEARCH_COMPUTER,
	SEARCH_FIREHOSE,
	SEARCH_CHARM,
	SEARCH_BUCKET,
	SEARCH_TOILET,
	SEARCH_ALTAR,
	SEARCH_VENT,
	SEARCH_BOARD,

	INTER_SWITCH,
	INTER_DOOR,
	INTER_ESC,
	INTER_COMPUTER,
	INTER_TOILET,
	INTER_ALTAR,

	TO_HALLWAY,
	TO_301,
	TO_302,
	TO_303,
	TO_304,
	TO_SECRET,
	TO_ESC,

	INFONUM
};

enum class AUDIO
{
	BGM_RAIN,
	BGM_WIND,

	EFS_BAG,
	EFS_EMPTY_BUCKET,
	EFS_CHAMR_MELT,

	EFS_DOOR_OPEN,
	EFS_HYDRANT_OPEN,
	
	EFS_KEY_CHARMING,
	EFS_KEY_SKELETON,
	EFS_KEY_UNLOCKING,

	EFS_KNIFE_HIT,
	EFS_PAPER,
	EFS_SWICH,
	EFS_WATER_FLOW,

	EFS_PHONE_CLOSE,
	EFS_PHONE_RING,
	EFS_SCREAMING,

	HUMAN_WALK_L,
	HUMAN_WALK_R,

	MONSTER_ROAR,
	MONSTER_WALK,

	SDCARD,

	AUDIONUM
};