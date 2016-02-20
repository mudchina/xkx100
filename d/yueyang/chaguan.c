// Room: /d/yueyang/chaguan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "巴陵茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽：那是洞庭
春的味道啊。几个衙门胥吏模样的人也在茶馆里翘着二郎腿喝茶。一些
打扮齐整的客商和汗流浃背的苦力各自自成一堆，或轻品，或驴饮，各
具神态。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
		__DIR__"npc/xingren" : 1,
	]));
	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
