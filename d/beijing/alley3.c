// /d/beijing/alley3.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
这是一条十分僻静的小胡同，东南面有一家客店，隐隐约约传来打
斗之声。你颇有些犹豫：要不要过去看一看呢，不会有什么危险吧？东
北边可以出胡同。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"southeast" : __DIR__"kedian1",
		"northeast" : __DIR__"alley2",
	]));
	set("objects", ([
		"/d/village/npc/dipi" : 1,
		"/d/village/npc/punk" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
