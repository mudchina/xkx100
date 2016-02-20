// Room: /city/heyuanhouyuan.c

inherit ROOM;

void create()
{
	set("short", "何园后院");
	set("long", @LONG
这里四周描金漆银，装扮得富丽堂皇，别有气派，门廊下挂着丝雀
画眉，叫声婉转动听，几株名贵的珊瑚就放在院中，四下散放着一些躺
椅，以供在院中休息。
LONG );
	set("exits", ([
		"north" : __DIR__"heyuan",
	]));
        set("objects", ([
		__DIR__"npc/he": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -52);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}