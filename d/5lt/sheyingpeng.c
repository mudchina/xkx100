// Room: /d/5lt/sheyingpeng.c

inherit ROOM;

void create()
{
	set("short", "摄影棚");
	set("long", @LONG
这里是电视台的摄影棚。现场人头攒动彩旗飘扬，不知道今天是哪
位大明星作客电视台。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"west"      : __DIR__"yanboting",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
