// Room: /yangzhou/changchunling.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","长春岭");
	set("long",@LONG
长春岭因形似镇江金山，俗称小金山。当时为使乾隆帝能坐船直抵
平山堂，便开挖了莲花埂新河，挖出泥土堆积而成小金山。此岭四面环
水，岭上遍植春梅、淡竹，香气四溢，故曰"梅岭春深"。李亚如撰联云：
“借取西湖一角堪夸其瘦，移来金山半点何惜乎小”。一对参天银杏间
陈列一款原形似山水盆景的钟乳石云盆。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northdown" : __DIR__"balongqiao",
		"southdown" : __DIR__"xiaohongqiao",
		"southeast" : __DIR__"qinshi1",
		"westdown"  : __DIR__"changchunqiao",
		"east"      : __DIR__"qishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}