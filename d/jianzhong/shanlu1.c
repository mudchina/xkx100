// Room: /d/jianzhong/qzroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。路旁的山坡上稀稀落落地长着几棵树。
LONG
	);

	set("exits", ([
		"west" : "/d/xiangyang/eastgate2",
                "northeast" : __DIR__"shanlu2",
	]));

	set("outdoors", "jianzhong");
	set("coor/x", -430);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}