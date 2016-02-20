// Room: /d/mobei/shulin.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "杂树林");
	set("long", @LONG
风动树林，树叶刷刷作响，昏黄的月光下几只绿幽幽的眼睛在林中
无声的移动。突然响起的尖叫令人毛骨悚然，又突兀的停止，东面向上
是荒山山顶，出了林子就是草原。
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhucong" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"hill1",
		"west"   : __DIR__"caoyuan1",
	]));
	set("coor/x", -220);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
