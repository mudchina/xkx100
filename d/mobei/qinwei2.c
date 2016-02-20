// Room: /d/mobei/qinwei2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "亲卫营");
	set("long", @LONG
亲卫营是专为保护铁木真和其家人所设立的，多是铁木真的远亲子
弟或武功高强者，地位在一般士兵之上。蒙古人崇尚朴实，所以营帐中
除了些刀枪外就没有些什么奢侈东西。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei2" : 2,
		__DIR__"npc/chilaowen" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"road3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
