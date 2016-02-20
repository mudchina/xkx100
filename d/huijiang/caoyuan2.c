// Room: /d/huijiang/caoyuan2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
脚下是软软的青草，还留着早晨的露珠，便如同一块绿色的大毯子
般。成群的牛羊就是这块毯子上绣着的点点花朵。牧羊的姑娘轻轻挥动
手中的皮鞭，唱着草原上的牧歌。
LONG );
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/sheep" : 2,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"caoyuan",
	]));
	set("coor/x", -50060);
	set("coor/y", 9080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
