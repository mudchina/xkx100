inherit ROOM;

void create()
{
	set("short", "康府花园");
	set("long", @LONG
这是一个小花园，虽然花儿不太多，却十分幽雅清洁，显是平日
有人修整打扫。花园北边是一间佛堂。
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
  		"east"  : __DIR__"kang3",
  		"north" : __DIR__"fotang",
	]));
	set("coor/x", -181);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
