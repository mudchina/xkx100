// Room: /yangzhou/hejiajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "禾嘉街");
	set("long", @LONG
禾嘉街南面是城守署，几个士兵在站岗，不时有士兵校尉进出。行
人到此，多不敢停留，怕惹是非。街道宽敞整洁，也少有泼皮在此打闹。
北面多为民宅，屋檐比次密接。中间有一小巷通向扬州治园名家「仇好
石」的住所。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"nanmendajie",
		"east"  : __DIR__"dongmenqiao",
		"south" : __DIR__"bingyindamen",
		"north" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}