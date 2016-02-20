// Room: /d/5lt/datiepu.c

inherit ROOM;

void create()
{
	set("short", "打铁铺");
	set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片
通红，你一走进去，就感到浑身火热。墙角堆满了已完工和未完工的菜
刀、铁锤、铁棍、匕首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专
心致志地在打铁。
LONG );
	set("exits", ([
		"east" : __DIR__"sroad3",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
	set("coor/x", -160);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}