// Room: /d/songshan/jianchi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "剑池");
	set("long", @LONG
没有亲眼见到，没几个人会相信，在这嵩山绝顶之上，居然会有这
么大一塘水。一炳长达五丈的铁剑凌空横卧水塘上，剑刃宽阔，剑尖非
常锋锐，正是嵩山派惯常使用的剑。
    水塘往北延伸。东西有长廊跨水而过。
LONG );
	set("exits", ([
		"south" : __DIR__"huimengtang",
		"east"  : __DIR__"eastpath1",
		"west"  : __DIR__"westpath1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		CLASS_D("songshan")+"/tang" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
