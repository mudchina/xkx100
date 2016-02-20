// chuchang shi

inherit ROOM;

void create()
{
	set("short", "储藏室");
	set("long", @LONG
这里是丐帮的储藏室，你现在只能看见一个个锁着的箱子。
LONG );
	set("exits", ([
		"west" : __DIR__"mishi",
		"east" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
