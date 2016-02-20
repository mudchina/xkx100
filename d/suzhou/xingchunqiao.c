// Room: /d/suzhou/xingchunqiao.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "行春桥");
	set("long",@long
顺着石湖岸边走就来到了行春桥，你站在行春桥的石级上，极目远
望，湖水接天，群山蜿蜒，塔影倒影，美若画卷。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"east" : __DIR__"shihu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
