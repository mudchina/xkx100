//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "北楼");
	set ("long", @LONG
这是万老爷子住的地方。摆设简单整洁，右首一张木床。方砖地上
有几处凹凸，显是主人勤于习武所致。
LONG);
	set("exits", ([
		"south" : __DIR__"dating",
		"east"  : __DIR__"shufang1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1489);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
