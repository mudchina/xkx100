// Room: /d/nanshaolin/dzdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "地藏殿");
	set("long", @LONG
这是地藏殿。供奉地藏王菩萨。地藏王主宰阴间，手下自然有不少
鬼兵鬼卒，罗列帐前。菩萨眉横煞气，手断阴阳。令人一见之下，顿觉
心惊胆战，惶恐不已。
LONG );
	set("exits", ([
		"east" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

