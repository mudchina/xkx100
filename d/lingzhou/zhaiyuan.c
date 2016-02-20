// Room: /d/lingzhou/zhaiyuan.c

inherit ROOM;

void create()
{
	set("short", "内宅院");
	set("long", @LONG
这是个极大的院子，一色青砖铺地，两边是东西厢房，住着丫鬟和
婆子，西南面有座三层的小楼，丫鬟们进进出出很是忙碌。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/yahuan" : 2,
	]));
	set("cost", 1);
	set("outdoors", "lingzhou");
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"jjdayuan",
	]));
	set("coor/x", -17940);
	set("coor/y", 32050);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
