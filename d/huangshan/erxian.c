// Room: /d/huangshan/erxian.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "二仙祠");
	set("long", @LONG
相传当年欲上天都，只有鲫鱼背一条路，人多有失足。后有张志程，
黄侃二位隐士，一文一武，开凿了半山寺到文殊院的道路。后世为纪念
二人，故立祠于此。左侧为张仙像，乃一长须老者，腰悬无尘剑，右侧
一位仙风道骨，手持令牌，号令六丁六甲开山，正是黄侃。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"jiyu",
	]));
	set("objects", ([
		__DIR__"obj/huang" : 1,
		__DIR__"obj/zhang" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
