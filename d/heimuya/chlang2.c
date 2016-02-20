// Room: /d/heimuya/chlang2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","长廊");
	set("long", @LONG
这里是非常气派的长廊。但是却没什么人在这里，南边是青龙堂的
大厅。
LONG  ); 
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"chlang1",
		"south" : __DIR__"qing",
	]));			   
	set("objects",([
		__DIR__"npc/shinu1"   :1,
	]));
	set("no_fight",0);
	set("no_steal",0);
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}