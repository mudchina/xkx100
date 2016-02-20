// Room: /d/mobei/caocong1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "草丛中");
	set("long", @LONG
西方天边黑云重重叠叠的堆积，头顶却是一片暗蓝色的天空，更无
片云。西北风一阵缓，一阵急，明月渐至中天，月旁一团黄晕。月光之
下，草丛中露出石板一角。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"hill1",
	]));
	set("coor/x", -220);
	set("coor/y", 5240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
