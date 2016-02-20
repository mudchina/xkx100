// Room: /d/quanzhou/kaojiaochang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "考教场");
	set("long", @LONG
这里是武馆的考教场，面积甚大。有许多武馆子弟在此习武，拳打
脚踢，舞刀弄剑，耍枪挥棒的好不热闹。穿过考教场便是武馆的前厅。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east" : __DIR__"wuguangate",
		"west" : __DIR__"dating",
	]));
	set("objects", ([
		__DIR__"npc/xuetu" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
