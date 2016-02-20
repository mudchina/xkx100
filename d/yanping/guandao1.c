// Room: /d/yanping/guandao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这里密迩城郊，来往行人也渐渐多了起来。福州的官话听起来刺耳
难懂，可是抑扬顿挫，别有一番风味。
    北面有股青烟冒起，似乎有家野店。
LONG );
	set("exits", ([
		"east"   : "/d/fuzhou/ximen",
		"north"  : __DIR__"jiusi",
		"westup" : __DIR__"guandao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1800);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
