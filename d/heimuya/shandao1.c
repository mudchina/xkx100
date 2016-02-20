// Room: /d/heimuya/shandao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "山道");
	set("long", @LONG
西面是一座高山，地势极之险峻，一条窄小陡峭的山道蜿蜒盘往山
上，东边山脚是一片长滩。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"changtan",
	    "westup"   : __DIR__"shandao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", 4200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}