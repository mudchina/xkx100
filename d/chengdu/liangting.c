// Room: /d/chengdu/liangting.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "凉亭");
	set("long", @LONG
这是一座木制的凉亭，亭前树着一块石碑，石碑上用隶书体写着“
日照亭”三个大字，来往的行人、游客大多在此处驻足歇脚，亭边植着
大量的花木，引来了一些蝶鸟在其中嬉戏。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast" : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
		__DIR__"npc/youke" : 1,
	]));
	set("coor/x", -6060);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

