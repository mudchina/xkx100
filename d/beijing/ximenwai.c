// Room: /d/beijing/ximenwai.c

inherit ROOM;

void create()
{
	set("short", "西门外");
	set("long", @LONG
这里是北京的西城门外。人来人往，煞是热闹。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"ximen",
		"west" : "/d/heimuya/road3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huabei");
	set("coor/x", -1000);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
