// Room: /d/quanzhou/weiyuanlou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "威远楼");
	set("long", @LONG
这是泉州的北门城楼，青石筑成两层楼台坚固异常，巍峨宽阔的拱
形城门上方，镂着「泉州」两个红漆大字。城墙上贴着一张泉州官府告
示(gaoshi)。过了此门就是北边蜿蜒崎岖的清源山区了。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"northroad3",
		"north" : __DIR__"shanlu6",
	]));
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
        ]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1850);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n靖海将军\n施琅\n";
}
