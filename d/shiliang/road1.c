// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "青石大道");
	set("long", @LONG
这是通往衢州石梁镇的青石大道，浙南山国，比之水乡泽国的苏南
浙北，自是另一风味了。北面就是石梁温家了。
LONG
	);
        set("outdoors", "shiliang");
	set("exits", ([
                "southdown" : __DIR__"road2",
                "north"     : __DIR__"gate",
	]));
	set("objects", ([
                __DIR__"npc/nongfu" : 1,
	]));
	set("coor/x", 1610);
	set("coor/y", -1980);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}