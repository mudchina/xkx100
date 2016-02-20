// Room: /d/jueqinggu/maowu.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "茅屋");
	set("long", @LONG
只见屋中的陈设简陋，但洁净异常，堂上只一桌一几，此外便无别
物，与古墓石室中的桌椅一模一样。
LONG
	);
	set("exits", ([
		"out" : __DIR__"gudi2",
	]));
	set("objects", ([
		__DIR__"npc/yangguo" : 1,
		__DIR__"npc/longnv" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 
