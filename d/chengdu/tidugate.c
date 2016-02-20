// Room: guangchang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "提督府门");
	set("long", @LONG
这便是提督府门。巍峨雄伟的城墙上， "成都提督府" 五个大字
十分显眼，气势辉煌。几名亲兵立在两旁。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"tidujie",
		"north" : __DIR__"tidufu",
	]));
	set("objects", ([
		__DIR__"npc/qinbing" : 2,
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir=="north") && (objectp(present("qin bing", environment(me)))))
		return notify_fail("亲兵上前挡住你，朗声说道：这位" + RANK_D->query_respect(me) + "请回吧。老爷不见客。\n");
	return ::valid_leave(me, dir);
}
