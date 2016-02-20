// Room: /yangzhou/caiyidongjie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","彩衣东街");
	set("long",@LONG
一入彩衣街，你才明白扬州为何被称为「商贾如织」。只见彩衣街
两面临街开店，而且都是衣帛香粉铺。店店相连，间有茶坊酒店。街面
狭窄，人流拥挤。各店客商进出频繁，更有女子满挂珠翠，进出店铺，
购置自己喜欢的衣帛饰物。一入夜，各店铺挑起灯笼，彻夜喧哗，灯火
不绝。见到此景，真是「九里三十步街中，珠翠阗咽，邈如仙境」。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"caiyixijie",
		"east"  : __DIR__"xianguopu",
		"north" : __DIR__"sixiepu",
		"south" : __DIR__"dashidongjie",
	]));
	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}