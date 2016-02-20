// Room: /yangzhou/yongdao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","甬道");
	set("long",@LONG
从天王殿至大雄宝殿，正中甬道桧柏夹立，东通“文章奥区”，西
通“仙人旧馆”。甬道中有两座铁制宝鼎，两侧高台，两株银杏参天，
东为雌株，西为雄株。
    大雄宝殿前平台，东有百年古柏，西有百年黄杨，宝殿更显古朴庄
严。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"east"  : __DIR__"pingyuanlou",
		"west"  : __DIR__"pingshantang",
		"north" : __DIR__"daxiongbaodian",
		"south" : __DIR__"tianwangdian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}