// Room: /d/lingxiao/iceroad1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰道");
	set("long",@LONG
这里是一片冰雕玉砌的世界。走在路上，低头一看，路面是用万载
不化的寒冰所制，晶莹剔透，足可映物，照理说走在这样的冰上，应该
滑溜不堪，但仔细一看，每处冰道上，都雕有细细的花纹，而且做工精
细，显然耗费了大量人力。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"gate",
		"north" : __DIR__"iceroad2",
		"west"  : __DIR__"hotel",
		"east"  : __DIR__"sell",
	]));
	set("objects",([
		__DIR__"npc/li" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

