//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "南楼");
	set ("long", @LONG
这是万门弟子住的地方。万门一共有八个弟子，除第三个弟子万圭
外，其余的都住在这里。墙上挂了几把刀剑。
LONG);
	set("exits", ([
		"north" : __DIR__"dating",
		"east"  : __DIR__"chaifang",
	]));
	set("objects", ([
		__DIR__"npc/shencheng" : 1,
		__DIR__"npc/sunjun"    : 1,
		__DIR__"npc/boyuan"    : 1,
		__DIR__"npc/fengtan"   : 1,
	]));
  
	set("coor/x", -1489);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
