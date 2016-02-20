// Room: /d/heimuya/chlang1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","长廊");
	set("long", @LONG
这里是非常气派的长廊。两边站着数十个刀斧手，警卫森严，透着
腾腾杀气。
LONG );

	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"dating3",
		"south" : __DIR__"chlang2",
	]));
	set("objects",([
		__DIR__"npc/jiaotu"   :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}