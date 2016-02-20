// Room: /d/quanzhou/guitangxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "桂坛巷");
	set("long", @LONG
桂坛巷顺着施府高墙蜿蜒而出，一面是潺潺流水的沟渠，幽暗宁静。
桂坛巷西南面便是承天寺。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"xuetang",
		"north"     : __DIR__"jiangjunfu",
		"southwest" : __DIR__"chengtiansi",
	]));
	set("coor/x", 1870);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
