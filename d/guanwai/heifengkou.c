// /guanwai/xiaotianchi.c

inherit ROOM;

void create()
{
	set("short", "黑风口");
	set("long", @LONG
这里是密林中的险恶之境周围是为茂密的松林，不见天光。林中传
来野兽饥饿之极的嘶吼。四处有不知名的草菰和野果，可你一点也不敢
尝尝。林木幽暗深邃，似乎暗藏杀机。你到了此处，心胆俱裂，只想快
点离开。
LONG );
	set("outdoors", "changbai");
	set("exits", ([
		"east"     : __DIR__"xiaotianchi",
		"westdown" : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/bear" : 1,
	]));
	set("coor/x", 6170);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}