// Room: /d/jiaxing/jiaxinggang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "嘉兴海港");
	set("long", @LONG
这里是嘉兴海港，港内白帆点点，码头上停着好多渔船，正要出海
的渔民忙碌地来来往往，一个船老大摸样的人正在拼命呼喝着在船上做
帮工的渔家孩子。船工是不少，可是一提起桃花岛却个个摇头。
LONG );
	set("exits", ([
		"west" : __DIR__"nanhu",
	]));
	set("objects", ([
		"/d/taohua/npc/laoda": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiaxing");
	set("coor/x", 1520);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}