// /kaifeng/yushi2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小浴室");
	set("long", @LONG
这些小浴室经过专门装修，而且有专人伺候打扫，所以很干净，墙
角落中还供奉着鲜花，梁柱上供奉着小佛像。房间正中当然是浴盆，有
些人为示对佛诚心，拜佛之前定要沐浴。
LONG);
	set("objects", ([
		__DIR__"npc/obj/zaopeng" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"yushi1",
	]));

	setup();
	replace_program(ROOM);
}
