// Room: /d/wuyi/2qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "二曲");
	set("long", @LONG
九曲溪盘流于群山之中，沿溪三十六峰，碧水丹山，风光旖丽。奇
峰云海，山清水秀，号称“三三水，六六峰”。二曲溪岸西边就是亭亭
玉立的玉女峰了。东岸是黑乎乎的铁板嶂。水流到此，倒影着亭亭玉女，
显得格外妩媚动人。朱熹《九曲棹歌》曰：“……二曲亭亭玉女峰，插
花临水为谁容？道人不作阳台梦，兴入前山翠几重。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"yunvfeng",
		"east"      : __DIR__"1qu",
		"northwest" : __DIR__"3qu",
		"northeast" : __DIR__"tiebanzhan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

