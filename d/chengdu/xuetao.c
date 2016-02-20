// Room: /d/chengdu/xuetao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "薛涛井");
	set("long", @LONG
这里是一代女诗人薛涛埋香之所，四周竹林环绕，静悄悄的连自己
的脚步声都听得到，你的面前有口古井，上面长满了青苔，看起来已经
很久没人来过了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wanliqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



