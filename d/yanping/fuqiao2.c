// Room: /d/yanping/fuqiao2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "水南浮桥");
	set("long", @LONG
延平府城山环水绕，诗誉“山围八面绿，水绕二江青”，建溪和西
溪分从北、西两面环绕城郭，再汇集东去。此浮桥便是架设在西溪上通
往南岸九峰山的必经之处。整列浮桥由几十条小船串接铁链而成，上面
覆以木板，方便通行。
LONG );
	set("exits", ([
		"southup" : __DIR__"9fengshan",
		"northup" : __DIR__"yanshoumen",
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
