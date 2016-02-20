// Room: /d/chengdu/zhubaopu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "周记珠宝铺");
	set("long", @LONG
这是一家专营金银、珠宝类的首饰店，老板和蔼可亲，热情周到。
如果你想找件礼物送给你的心上人，那就不要再犹豫了，赶紧到钱庄取
钱吧。
LONG	);

	set("exits", ([
		"west" : __DIR__"beijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

