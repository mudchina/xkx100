// Room: /d/5lt/houtai.c

inherit ROOM;

void create()
{
	set("short", "后台");
	set("long", @LONG
这里是演播厅的后台，演员们得了空儿赶着跑来歇口气。嘉宾室门
口的过道里挤满了索要签名的歌迷影迷。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"southwest" : __DIR__"yanboting",
	]));
        set("objects", ([
		__DIR__"npc/niu": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 35);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
