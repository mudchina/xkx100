//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
这是一条长长的走廊。走廊西边是知府大人的书房。东边尽头的一
间房，门上披了一匹素帏，象是个灵堂。南边是东厢房，是知府大人和
家眷住的地方。几个闲着没事的衙役正和一个丫鬟调笑着。
LONG);
	set("objects", ([
		"/d/city/npc/yayi"   : 3,
		__DIR__"npc/yahuan1" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"lingtang",
		"south" : __DIR__"dongxiang",
	]));
  
	set("coor/x", -1480);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
