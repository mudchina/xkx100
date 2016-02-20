// Room: /d/huashan/jzroad3.c

inherit ROOM;
void create()
{
	set("short", "中条山脚");
	set("long", @LONG
你来到中条山脚。仰望天空，山势压顶，天边的红霞映透了整个山
林，呼啸的穿山风刮个不停。你不禁稍许有些惧意。向东有一条上山小
路。
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([
		"west"   : __DIR__"jzroad2",
		"eastup" : __DIR__"jzroad4",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -930);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
