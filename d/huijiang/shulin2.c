// Room: /d/huijiang/shulin2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
湖边的这树林并不茂密，只是稀疏的几棵，远处高山上覆盖着白雪，
如同天上白色的云彩。湖中碎冰相互撞击的叮叮声犹自传来。林中野花
的香味从脚下升上来，在林中铺了浅浅的一层。
LONG );
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhanshi" : 2,
	]));
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"buluo",
		"west"  : __DIR__"linzhong",
		"east"  : __DIR__"shulin3",
	]));
	set("coor/x", -50050);
	set("coor/y", 9030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
