// /kaifeng/tinyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "龙亭园");
	set("long", @LONG
这里是一片花木葱郁的园林。园林的南北两边分别是杨家湖和潘家
湖，湖中碧波荡漾，湖边垂柳依依，芳草如茵。从此向北是龙亭大殿，
西面是西大街道。
LONG
	);
	set("exits", ([
		"east" : __DIR__"road5",
		"west" : __DIR__"wroad3",
		"north" : __DIR__"longting",
	]));

	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	setup();
	replace_program(ROOM);
}
