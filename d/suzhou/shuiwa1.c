// Room: /d/suzhou/shuiwa1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "划船坞");
        set("long",@long
这里名为“画船楼”，俗称“划船坞”，相传西施在此玩龙舟。向
南有一条直通太湖的人工开凿的小溪。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"eastup"    : __DIR__"shiyuan",
		"southeast" : __DIR__"caixiangjing",
	]));
	set("no_clean_up", 0);
	set("coor/x", 870);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
