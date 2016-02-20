// Room: /d/suzhou/shihu.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "石湖");
	set("long",@long
石湖是太湖的一个内陆支流，位于苏州城南春秋时，越兵伐吴，横
断山麓，凿石开湖，通故苏，故名石湖。湖畔有座上方山，山顶矗立上
方塔。湖的北面横跨高大的越城桥，湖东有当年越兵登陆的越来溪，湖
西隔着始建于南宋末年的行春桥。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"south" : __DIR__"tianpingshan",
		"west" : __DIR__"xingchunqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
