// Room: /d/mobei/byriver.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "水塘边");
	set("long", @LONG
草原上的一个小水塘，边上是几棵半枯萎的老树。塘边的青草半拖
了到水中，塘水有些浑浊。塘的北边是个畜栏，东面是个干草堆，旁边
的一间小茅屋虽然简陋，依然能看出江南的风格。
LONG
	);
	set("outdoors", "mobei");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"river",
		"northeast" : __DIR__"chulan",
		"east" : __DIR__"caodui",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
