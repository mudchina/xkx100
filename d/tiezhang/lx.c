// Room: /d/tiezhang/lx.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "泸溪");
	set("long", @LONG
这里是湘西的一个小镇。虽然地处偏僻，但这里来往的行人仍然很
多。西面是一间供人休息打尖的小客店。西南方四十里处，就是此处有
名的猴爪山。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"road1",
		"west"      : __DIR__"kedian",
		"northeast" : "/d/henshan/hsroad6",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2000);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}