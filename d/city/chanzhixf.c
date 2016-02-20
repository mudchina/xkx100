// Room: /city/chanzhixf.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是一间小厢房。是庙里的火工和尚等人休息的地方，里面随随便
便地铺了几张席子，窗户上都遮了不透光的纸，厢房里的光线暗得不得
了，不过，大殿上的诵经声倒是不时地传来。
LONG );
	set("exits", ([
		"west"  : __DIR__"chanzhidadian",
	]));
	set("objects", ([
		__DIR__"npc/huogongseng": 1,
	]));
	set("coor/x", -19);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}