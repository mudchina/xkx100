// Room: /d/baituo/caoping.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","草坪");
	set("long", @LONG
这里是一块芳草坪，绿草茵茵，蝴蝶漫舞，让人感到惬意。不过偶
尔也会碰到菜花蛇。
LONG	);
	set("exits", ([
		"west" : __DIR__"shijie",
	]));
	set("objects" , ([
		__DIR__"npc/caihuashe" : random(2),
	]));
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
