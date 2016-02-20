// wg_lang6.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，往东通向休息室，西面是物品房，这里静悄悄的，人
们走路都也小心翼翼的，怕吵着东面休息室里休息的人。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_woshi1",
		"west" : __DIR__"wg_wupinfang",
	]));
	set("outdoors", "wuguan");
	set("coor/x", 51);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

