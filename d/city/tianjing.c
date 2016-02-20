// Room: /city/tianjing.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
天井甚小，纵深十余步，宽仅五六步，前有洞室，左有门与官衙的
院子相通。在门的北侧，有悬蹬十数级，可由此登山。在洞口的西侧，
有石阶数级，可以临水。如此小的天井内有如此景致，游人到此多凝思
玩赏一会，对治此园的工匠不禁生出几分敬意。
LONG );
	set("exits", ([
		"northup" : __DIR__"shixingting",
		"north"   : __DIR__"hushishandong",
		"east"    : __DIR__"yamenyuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}