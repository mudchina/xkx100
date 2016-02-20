// Room: /d/huijiang/wuchang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long",@LONG
这里是红花会的练武场，不少红花会的会众正在练功。场子中央竖
着几个木人，场子周围摆着些沙袋、兵器等物。看来反清复明、恢复故
国衣冠也实在不是一件容易的事。
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
        ]));
	set("exits", ([
		"east"     : __DIR__"bingqi",
		"north"    : __DIR__"fangju",
		"south"    : __DIR__"xingtang",
		"west"     : __DIR__"zoulang3",
	]));
	set("coor/x", -50040);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
