// Room: /d/yanping/fuqiao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "水东浮桥");
	set("long", @LONG
延平府城山环水绕，诗誉“山围八面绿，水绕二江青”，建溪和西
溪分从北、西两面环绕城郭，再汇集东去。此浮桥便是架设在建溪上的
行旅必经之处了。整列浮桥由几十条小船串接铁链而成，上面再覆以木
板，方便人马通行。
LONG );
	set("exits", ([
		"eastup" : __DIR__"mazhan",
		"westup" : __DIR__"dongmen",
	]));
	set("outdoors", "yanping");
	set("coor/x", 1530);
	set("coor/y", -6170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
