// dianwai.c
inherit ROOM;

void create()
{
	set("short", "午门广场");
	set("long", @LONG
这里是皇帝廷杖官吏的地方, 也是大将得胜还朝后举行献俘礼仪的
场所. 每年十月初一日, 在这里向全国颁发来年历书, 时称“颁朔”.
在内金水河上的五座汉白玉雕桥, 造型秀丽, 同雄伟壮观的午门城楼和
金碧辉煌的太和门相映, 引人注目. 
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"  : __DIR__"youmen",
		"west"  : __DIR__"zuomen",
		"north" : __DIR__"wumen",
		"south" : "/d/beijing/zhengmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
