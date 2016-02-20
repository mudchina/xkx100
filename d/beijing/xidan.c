inherit ROOM;

void create()
{
	set("short", "西单");
	set("long", @LONG
这里就是西单，人来人往，十分热闹。游人虽然多，但大都只四处
晃悠，着东瞅瞅西看看，也不急着买什么。西边有家杂货铺，去那里买
东西的人很多。不断有人从北边走来，似乎那里也挺热闹。南边是西长
安街。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"zahuopu",
		"south" : __DIR__"xichang2",
		"north" : __DIR__"xidan1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan": 1,
		"/d/huashan/npc/youke": 2,
	]));
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
