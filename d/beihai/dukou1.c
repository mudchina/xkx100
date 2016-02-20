// /d/beihai/dukou1.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "渡口");
	set("long", @LONG
这里是一座渡口，专门负责摆渡游客去湖中心的琼岛的。渡口是用
结实的木料建造的，还铺上了一层垫子。渡船也是很新的双层游船，坐
起来稳稳当当的。两个船家分别坐在船头很船尾，随时准备开船了。
LONG
	);
	set("exits", ([
		"north"     : __DIR__"jiulongbi",
		"southwest" : __DIR__"xiaolu2",
		"northeast" : __DIR__"xitian",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
