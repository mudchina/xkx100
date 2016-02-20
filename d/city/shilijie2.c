// Room: /yangzhou/shiliji2.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
十里长街乃是城里的繁华地段，一到晚上，一派灯红酒绿，尤为热
闹。笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿
意马，很想就此停步享受一番。南边是一个热闹的广场。西边是一家店
铺，墙上写着一个大大的“当”字，仔细倾听，可以听到压低的讨价还
价的声音。东边则是一片喧嚣，夹杂着“一五一十”的数钱声，原来那
是方圆千里之内最大的一家赌场。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"dangpu",
		"east"  : __DIR__"duchang",
		"south" : __DIR__"shilijie3",
		"north" : __DIR__"shilijie1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/bao" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}