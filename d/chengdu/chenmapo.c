// Room: /d/chengdu/chenmapo.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "麻婆豆腐店");
	set("long", @LONG
这里就是闻名天下的陈麻婆豆腐店。店堂里整齐的摆放着十几张红
漆方桌，一般客人就在这里品尝陈麻婆豆腐。几个伙计忙的是晕头转向
。柜台上摆着两坛“老妈红”和一把算盘，后面端坐着的就是陈麻婆。
LONG	);
	set("exits", ([
		"east" : __DIR__"chufang",				
		"west" : __DIR__"beijie1",				
	]));
	set("objects", ([
		__DIR__"npc/mapo" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
