// /kaifeng/daoxiang1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "稻香居");
	set("long", @LONG
稻香居有三百年的历史了。从这栋楼外面黑黑的招牌旗就能看出来。
不过里面的食客还是挺多。桌子坐满了人。楼上当然有雅座，不过是要
有一定身份地位的人才能上。
LONG
	);
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("exits", ([
		"up"   : __DIR__"daoxiang2",
		"west" : __DIR__"road2",
		"east" : __DIR__"majiu",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	setup();
	"/clone/board/kedian19_b"->foo();
	replace_program(ROOM);
}
