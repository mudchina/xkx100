// Room: /wuliang/shanlu9.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
青石山路还砌得蛮整齐的。因为山上就是无量剑派的地头了。无
量剑派在无量山中自己做大已久，所以少有资财，把这路也修得有模
有样。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"jianhugate",
		"northdown" : __DIR__"shanlu8",
	]));
	set("coor/x", -71000);
	set("coor/y", -79970);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}