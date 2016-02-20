// Room: /d/taishan/tanhai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "探海石");
	set("long", @LONG
日观峰北有一块从山崖向横突出的巨石，名拱北石，又名探海石。
长约二丈余，向东直指渤海。巨石三面无所凭依，视野广阔，但除非有
绝高胆色的人，普通人一般都不敢攀登这块探海石。石上有“绝妙”、
“船石岩”、“醉石”及明人题名等刻。登临其上可尽赏旭日东升的壮
丽场面，亦可晴览山色、阴观云海。李兴祖诗：“才听天鸡报晓声，扶
桑旭日已初明。苍茫海气连云动，石上游人别有情。”
LONG );
	set("exits", ([
		"westdown" : __DIR__"riguan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
