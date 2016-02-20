// Room: /d/huijiang/zhangpeng1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "帐篷");
	set("long", @LONG
一顶华丽小巧的帐篷，铺着华丽的地毯，中间是张小矮几，两端的
几脚镂刻成巧妙的花纹，上面摆着个花瓶，插了几枝野花，一面青铜镜
子就挂在帐篷的边上，看得出是个姑娘的住所。
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huoqingtong" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"buluo1",
	]));
	set("coor/x", -50060);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
