// Room: /d/suzhou/yingxiaoting.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "迎笑亭");
        set("long",@long
这里是灵岩山半山上的一座小亭子，从山下上山的游客到了这里都
歇歇脚。俯望山下景色，远处一片碧波，在水天之间，点点银光，煞是
宜人。
long);
	set("outdoors","suzhou");
	set("objects",([
		__DIR__"npc/seng" : 1,
	]));
	set("exits",([
		"westdown" : __DIR__"lingyanshan",
		"southup" : __DIR__"shiyuan",
	]));
	set("coor/x", 900);
	set("coor/y", -1100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
