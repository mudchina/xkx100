// Room: /d/huanggong/jiao3.c

inherit ROOM;

void create()
{
	set("short", "城角");
	set("long", @LONG
这里是内城的一角, 头上的天空只能见方方的一角. 上面有座漂亮
的角楼.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"dao7",
		"up"    : __DIR__"lou3",
		"east"  : __DIR__"dao6",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin2"  : 2,
	]));

	set("coor/x", -230);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}