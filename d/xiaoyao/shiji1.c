// shiji1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "石级");
        set("long", @LONG
这是一段长长的石级，四周由于缺乏光亮，难免有那么点阴森森的
感觉，石级向着东西两面伸展，一眼望去，不可以望到尽头。
LONG );
	set("exits", ([
		"east" : __DIR__"shidong",
		"west" : __DIR__"shishi1",
		"north" : __DIR__"fangjian1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50030);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}