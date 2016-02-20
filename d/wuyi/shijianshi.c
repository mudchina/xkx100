// Room: /d/wuyi/shijianshi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "试剑石");
	set("long", @LONG
四曲溪北的试剑石，相传是当年控鹤仙人试剑时劈开的。石上留下
的裂痕，平直而整齐。宋朝李纲题字道：“炼气为金铸成剑，且将玩石
试青萍。”这里附近的溪流叫小九曲。曲折蜿蜒，简直就是九曲溪的缩
影一般。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xiandiaotai",
		"south" : __DIR__"4qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

