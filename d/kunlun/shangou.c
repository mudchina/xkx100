// Room: /d/kunlun/shangou.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "山沟");
	set("long", @LONG
山壁之下的一条小山沟，往西是一片稍矮的山壁，其余三面山壁直
接云天。这里绿草丛生，有许多雪中之鸡出没其中。
LONG	);
	set("outdoors", "hongmei");
	set("exits", ([ /* sizeof() == 1 */
		"westup" : __DIR__"shanbi",
	]));
	set("objects",([
		__DIR__"npc/xueji" : 2,
	]));
	setup();
	set("coor/x", -98000);
	set("coor/y", 20050);
	set("coor/z", 40);
	replace_program(ROOM);
}
