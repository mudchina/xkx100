// Room: /d/taishan/weiping.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "围屏山");
	set("long", @LONG
这是泰山的其中一座山峰，又名悬石峰。山的东面有一个虎头崖，
其形状有如一头伏虎。南面有避风崖，崖上大大地刻着「振衣冈」三字
于上面。崖南隔涧为莲花峰，上题“海日石莲”。峰东为五花崖，俗呼
望人峰。旧时谷中有盘路，登峰视道中往来行人如蚁。峰顶二石钩连于
上，名试心石。旧传朝山者登之，心诚则不动，不诚则摇跌入崖底。北
边则有北斗坛。从这里往东走，便可到达伺奉泰山之神碧霞元君的碧霞
祠。
LONG );
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"eastdown" : __DIR__"bixia",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
