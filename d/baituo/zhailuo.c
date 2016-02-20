// Room: /d/baituo/zhailuo.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","小宅落");
	set("long", @LONG
这里是一个树影婆娑的静谧的小宅落，当中放着一口乌黑发亮的大
水缸。白驼山上常年积雪，这里的主人架起一条长长的竹渠，把清凉的
雪水引到家中的水缸里来。
LONG	);
	set("exits",([
		"east" : __DIR__"tangwu",
	]));
	set("objects",([
		__DIR__"npc/jiren": 1,
		__DIR__"npc/jiren1": 1,
	]));
	set("outdoors", "baituo");
	set("resource/water", 1); 
	set("coor/x", -50020);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}



