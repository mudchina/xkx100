// Room: /d/yueyang/zhongxin.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "中心菜市");
	set("long", @LONG
这里是岳阳城的中心菜市。每天早上，东门来的时菜，西门来的活
鱼，米店挑出来的陈米，屠场扛出来的生猪，全在这里货买，一片吆喝
不止。集散人空后，满地的鱼腥粪臭，过往行人往往掩鼻急行。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dongjie",
		"west"  : __DIR__"xijie",
		"north" : __DIR__"beijie",
		"south" : __DIR__"nanjie",
	]));
	set("objects", ([
		__DIR__"npc/xingren" : 1,
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/xiaofan" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
		CLASS_D("gaibang")+"/wu-changfeng" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
