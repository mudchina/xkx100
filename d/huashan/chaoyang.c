// chaoyang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "朝阳峰");
	set("long", @LONG
这里就是华山的东峰，也称朝阳峰，是华山看日出的绝佳处。於此
俯瞰，黄河隐显东迤如带，南望小孤峰背倚山河。小孤峰上有一小亭，
覆以铁瓦，亭中有铁棋盘一局，那就是华山著名的“博台”了。东壁悬
崖上，更有一个巨型掌印，相传为「河神巨灵」劈山时所留下的，李白
诗中“巨灵咆哮劈两山，洪波喷流射东海”就是指这个上古传说。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"westdown" : __DIR__"chaopath2",
	]));
	set("objects", ([
		CLASS_D("huashan")+"/gao-laozhe": 1,
		CLASS_D("huashan")+"/ai-laozhe": 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -850);
	set("coor/y", 220);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
 
