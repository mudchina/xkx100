// Room: /d/huijiang/zhangpeng.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "帐篷");
	set("long", @LONG
这个牛皮帐篷大约能容十多人。地上铺着华丽的地毯，上面绣着美
丽的花纹，边上拖着流苏。毯子中间摆着果盆。边上是几个大的箱子，
一边还横着把铁背弓。
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/muzhuolun": 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"buluo1",
	]));
	set("coor/x", -50040);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
