// Room: /d/baituo/xiaolu4.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条上山的小路。小路两边杂草丛生，看来少有行人。不过
路泥却甚是平滑，倒象常有人来往一般。你不禁有点犹豫。从这里，上
山的小路向西分出一条岔道。北边是山贼的老窝。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north"     : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
		"westdown"  : "/d/npc/m_weapon/lianzhangshi",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
