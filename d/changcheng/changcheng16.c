// Room: /d/changcheng/changcheng16.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长城");
	set("long", WHT @LONG
由于长期受到风沙的侵蚀，一小段城墙已经倒塌。你只好暂时从旁
边的小路绕过去。从这里你可以看到，虽然有的地方已经倒塌，但整条
长城依然雄伟的屹立在山顶，并向两边山脊延伸出去。
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"northup"   :__DIR__"changcheng17",
		"southeast" :__DIR__"changcheng15",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13000);
	set("coor/y", 10000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}