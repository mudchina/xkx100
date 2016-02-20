// Room: /d/nanshaolin/zhlou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "钟楼七层");
	set("long", @LONG
这里就是钟楼之顶。直入眼帘的便是那口大钟和一根悬挂空中的巨
杵。细看大钟，整整有两丈来高，直径也有丈许。钟身似由青铜浇铸，
上面满是密密麻麻的印文古篆，估计重逾数千斤。巨杵粗可合抱，丈把
来长，一头裹以厚皮，正对着钟腰。
LONG );
	set("exits", ([
		"down" : __DIR__"zhlou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

