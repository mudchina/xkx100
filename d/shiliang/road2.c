// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是通往衢州石梁镇的青石大道，浙南山国，比之水乡泽国的苏南
浙北，自是另一风味了。
LONG
	);
	set("outdoors", "shiliang");
	set("exits", ([
		"southwest" : "/d/jiaxing/chating",
		"northup"   : __DIR__"road1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1610);
	set("coor/y", -1990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}