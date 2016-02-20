// Room: /d/huangshan/guanpu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "观瀑亭");
	set("long", @LONG
这是一座六方翘角，顶覆琉璃的小亭，坐在这里，可以远观黄山三
大名瀑之一的“百丈泉”，由此看百丈泉，只见清潭，紫云二峰有飞泉
倾泄，势如银河天降，雨少时，如轻纱薄雾，雨足时则如千匹白练，高
悬天际，实在美不胜收。
LONG
);
	set("exits", ([ 
		"westdown" : __DIR__"wenquan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
