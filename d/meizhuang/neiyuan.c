// /d/meizhuang/neiyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "内院");
	set("long", @LONG
这里是梅庄的内院，从这里走过去就可以找到四位庄主，这里似乎
非常安静，可以听见落叶触地的声音，但又似乎非常吵闹，经常可以听
到嘈杂的琴声，但这琴声又可以将你的心弦打乱，你真不知道该怎么形
容这个地方。有一位壮年的汉子，腰悬宝剑守在院门口。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"senlin1",
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huyuan" : 1,
		"/d/shaolin/npc/mu-ren" : 5,
	]));

	set("coor/x", 3500);
	set("coor/y", -1390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

