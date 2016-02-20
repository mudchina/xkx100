// Room: /yangzhou/xiaohongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","小红桥");
	set("long",@LONG
小红桥是一座木制拱桥，是相对大红桥而名，此桥南接桃花坞，北
连小金山。瘦西湖原为扬州蜀冈山水流入运河的河道妆点而成。湖面瘦
小清秀，得名瘦西湖。游程曲折，水树交映，亭台别致，历代疏浚治理，
建造园林，遂成秀丽风光一片。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"northup" : __DIR__"changchunling",
		"south"   : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}