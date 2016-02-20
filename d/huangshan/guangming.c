// Room: /d/huangshan/guangming.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "光明顶");
	set("long", @LONG
光明顶是第二高峰，因为多次出现佛光，所以被称为光明顶，光明
顶上起伏平缓，面积广大，古人曾形容它“形若覆巢，旁无依附，秋水
银河，长空一色”。这里是看日出，观云海的最佳场所，如果机缘巧合，
还可以看见难得一遇的佛光。
LONG
	);
	set("exits", ([ 
		"west"    : __DIR__"feilai",
		"southup" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/monk" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
