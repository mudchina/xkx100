//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "废园");
	set ("long", @LONG
一座废弃的花园。月光下见到废园角落的瓦砾之中，长着一朵小小
的紫花，迎风摇曳，颇有孤寂凄凉之意。荒草中，有一株凹凹凸凸树干
的老梅在寒风中傲立。
LONG);

	set("exits", ([ 
		"north" : __DIR__"lingtang",
		"east"  : __DIR__"loudi",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2039);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
