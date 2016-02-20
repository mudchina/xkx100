// Room: /d/taohua/shore.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "岸边");
	set("long", @LONG
你疑惑地看着四周，这里就是桃花岛么？四周除了凌乱的礁石外，
什么都没有。往北面看，一座小山耸立在那里，可以通过攀爬岩壁到达
山顶。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northup" : __DIR__"hill",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
