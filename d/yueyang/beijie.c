// Room: /d/yueyang/beijie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
这是一条又长又宽的青石大道，由于地处城北，因此也显得清净一
些。街西面，有一家药铺，打着一个膏药旗，大书“同仁堂”三字，下
面很不起眼地添上“分号”二字。东边是个小杂货铺。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"zahuopu",
		"west"  : __DIR__"yaopu",
		"south" : __DIR__"zhongxin",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/xingren" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
