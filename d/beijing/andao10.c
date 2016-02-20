// /d/beijing/andao10.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
终于走出了暗道，你长长的舒了一口气。北边是天地会青木堂的大
厅，明亮的灯光让人感到无比温暖。
LONG );
	set("exits", ([
		"west"  : __DIR__"andao9",
		"east"  : __DIR__"andao9",
		"north" : __DIR__"dating",
		"south" : __DIR__"andao9",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/first" : 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
