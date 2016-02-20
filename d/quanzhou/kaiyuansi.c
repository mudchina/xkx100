// Room: /d/quanzhou/kaiyuansi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "开元寺");
	set("long", @LONG
这是一座规模宏大的千年古刹，莲宫桂宇，焕彩流金，刺桐掩映，
古榕垂荫。游人未抵门前，远远可见两座石塔凌空而起，矗立于千楼万
舍之上。它建于唐武则天二年，全寺占地庞大，是福建最大的佛教建筑
之一。寺外正面和西面，环立白石栏杆，并植刺桐。大门开启，接纳着
络绎不绝的虔诚香客。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"westroad2",
		"north" : __DIR__"tianwangdian",
	]));
	set("objects", ([
		"/d/wudang/npc/guest" : 2,
	]));
	set("coor/x", 1830);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
