//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "墓碑铺");
	set ("long", @LONG
说是一家店铺，其实这是一个工场，几个石匠正起劲地凿打着石碑。
最近荆州城里做丧事的人家还真不少，卖棺材、墓碑的便忙活起来了。
四处堆放了不少未完工的墓碑，一个监工正在巡视。
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
