// Room: /d/wuxi/nirenpu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "泥人铺");
	set("long", @LONG
    这里专卖无锡特产－－惠山泥人，柜台上摆了好几排形态各异精
巧传神的泥人，其中数大小阿福最为惹人喜爱。张老板学得一手祖传
的泥人手艺，所卖的泥人远近闻名。
LONG );
	set("exits", ([
		"east"  : __DIR__"northroad1",
	]));
	set("objects", ([
			__DIR__"npc/zhang" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}