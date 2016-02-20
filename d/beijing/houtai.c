inherit ROOM;

void create()
{
	set("short", "戏院后台");
	set("long", @LONG
这里是戏院后台，几个戏子正在化妆。从北边可以上台。
LONG );
	set("exits", ([
  		"west"    : __DIR__"xiyuan",
  		"northup" : __DIR__"stage",
	]));
        set("objects", ([
                __DIR__"npc/xizi" : 2,
        ]));
	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
