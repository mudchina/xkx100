// Room: /d/fuzhou/wushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "福州于山");
	set("long", @LONG
于山因战国时于越族在此居住而得名。相传闽越王无诸曾于九月九
日大宴于此，又称“九日山”，于山之麓的白塔，又称定光塔，系唐王
审知为了向死去的父母报恩而建。登上白塔榕城历历如画。
LONG );
	set("exits", ([
		"northdown" : __DIR__"dongdajie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
