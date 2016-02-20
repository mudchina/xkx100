// Room: /d/jianzhong/qzroad1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
山路终于走到了尽头。一片茂密的树林出现在你的眼前。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin1",
                "west" : __DIR__"shanlu2",
	]));

	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}