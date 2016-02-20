// Room: /d/huijiang/zhangpeng3.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "帐篷");
	set("long", @LONG
这顶粗牛皮帐篷看来很久没打扫了，在靠近地面的部分，有好几个
被老鼠咬穿的小洞，一张用羊皮拼起来的毯子摆在帐篷的中心，蓬壁挂
着的弓箭旁靠着把长铁抢，尖端发出白色的亮光。
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huoayi" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"buluo2",
	]));
	set("coor/x", -50060);
	set("coor/y", 9060);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
