// Room: /d/suzhou/zhonglou.c
// Last Modified by winder on May. 15 2001
inherit ROOM;
void create()
{
	set("short", "钟楼");
	set("long", @LONG
这是一座砖木结构的宝塔，塔高七层，塔身作八角形，飞檐翘翎，
檐角上挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂空雕绘着无数
佛陀们的坐像。一个个形态维肖，看来出自名匠之手。塔底入口处开了
一扇拱形的小木门，门扇两侧用彩漆涂绘，画的是释祖在灵山对诸天众
佛讲经时的情形。
LONG
	);
	set("outdoors","suzhou");
	set("exits", ([
		"east" : __DIR__"lingyansi",
//		"enter" : __DIR__"zhonglou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 895);
	set("coor/y", -1120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

