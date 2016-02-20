// Room: /d/xiakedao/xkroad3.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "平原小路");
	set("long", @LONG
你走在珠江三角洲的平原小路上。此处向称鱼米之乡，有花果之
都美誉，物产丰饶，民风淳朴。
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : "/d/foshan/southgate",
		"south"   : __DIR__"xkroad4",
	]));
        set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -8000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}