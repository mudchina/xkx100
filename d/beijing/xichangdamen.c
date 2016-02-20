inherit ROOM;

void create()
{
	set("short", "西厂大门");
	set("long", @LONG
这里就是西厂大门，可以看到里面有许多太监。穿着制服的官兵正
在操练，不时地传来呐喊声。如果你不想找死的话，最好还是赶快离开
吧。
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin2",
		"north" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}
