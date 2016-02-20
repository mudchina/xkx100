// Room: /d/suzhou/chaguan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙
桌一字排开，坐满了客人，或高声谈笑，或交头接耳。几个店伙计在一
旁伺候着客人们，在台后坐着一位老板娘，正在弹着算盘。
LONG );
	set("resource/water", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/lady2" : 1,
	]));
	set("coor/x", 860);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
