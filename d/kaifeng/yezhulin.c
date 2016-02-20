// /kaifeng/jiedao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "野猪林");
	set ("long", @LONG
自从不久前这林子中出了野猪之后，这片松林就少人来开封境内，
谈猪色边。只有为生活所迫的樵子还在林边打些野柴。自认武艺高强的
图个路近，也从此过。穿过此地便是华山。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"northeast" : __DIR__"dadao2",
	]));
	set("objects", ([
		ANIMAL_DIR"pig" : random(2)+1,
	]));
	setup();
	replace_program(ROOM);
}
