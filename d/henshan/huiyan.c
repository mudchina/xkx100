//Room: /d/henshan/huiyang.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "回雁楼");
	set("long", @LONG
这里是衡阳回雁楼，是本地最大的酒楼。往日这时已经十分忙碌的
酒楼今天却有点异样。一个年近四十的白衣汉子，正端坐自饮，桌面横
放着一把快刀，旁边却坐着一个小尼姑，满脸忧急愁苦之色，容貌却十
分秀丽。
LONG );
	set("exits", ([
		"down" : __DIR__"shop",
	]));
	set("objects", ([
		__DIR__"npc/tian" : 1,
		CLASS_D("hengshan")+"/lin" : 1,
	]));
//	set("no_clean_up", 0);

	set("coor/x", -400);
	set("coor/y", -1210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
